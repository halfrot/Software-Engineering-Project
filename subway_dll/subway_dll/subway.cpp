/*
* @Author lai yuhang
* Create Time   : 2022/01/31
* Last Edit Time: 2022/02/11
*/
#include"pch.h"
#include"subway.h"
#include"request_file_controller.h"
#include"result_controller.h"
void Subway::SaveLine(Line line) {
	lineVector[line.lineNumber] = line;
	isSaved[line.lineNumber] = true;
}

Line Subway::LineQuery(int lineNumber, bool saveFlag) {
	while (int(isSaved.size()) - 1 < lineNumber) {
		isSaved.push_back(false);
		lineVector.push_back(Line());
	}
	if (!isSaved[lineNumber]) {
		RequestFileController* rlc = new RequestFileController;
		rlc->Parse(lineNumber);
		delete rlc;
	}
	if (!saveFlag) {
		ResultController* rc = new ResultController;
		rc->Parse(lineVector[lineNumber]);
		delete rc;
	}
	return Line();
}

void Subway::RequestStationNameMap() {
	RequestFileController* rlc = new RequestFileController;
	rlc->Parse("request map");
	delete rlc;
}

void Subway::SaveStationNameMap(const std::map<std::string, int>& map) {
	nameToNumber = map;
}

void Subway::CreateGraph() {
	if (!isCreated) isCreated = true;
	else {
		RefreshGraph();
		return;
	}
	int ptr = 1;
	do {
		LineQuery(ptr, true);
	} while (isSaved[ptr++]);
	RequestStationNameMap();
	maxNumber = int(nameToNumber.size());
	for (auto p : nameToNumber) {
		numberToName[p.second] = p.first;
	}
	for (int i = 0; i <= maxNumber; i++) {
		G.push_back(std::vector<std::pair<int, int>>());
		visit.push_back(false);
	}
	for (auto& line : lineVector) {
		for (int i = 0; i + 1 < int(line.stationVec.size()); i++) {
			Station a = line.stationVec[i], b = line.stationVec[i + 1];
			G[a.stationNumber].push_back(std::make_pair(b.stationNumber, line.lineNumber));
			G[b.stationNumber].push_back(std::make_pair(a.stationNumber, line.lineNumber));
		}
	}
}

void Subway::RefreshGraph() {
	for (int i = 0; i < int(visit.size()); i++) {
		visit[i] = false;
	}
}

std::vector<std::string> Subway::CalPath(std::string startName, std::string endName, bool saveFlag) {
	CreateGraph();
	int s = nameToNumber[startName], t = nameToNumber[endName];
	std::queue<std::pair<
		std::pair<
		std::pair<int, int>, int>,
		std::vector<std::string>>> que;
	std::vector<std::string> initRoute;
	initRoute.push_back(startName);
	que.push(std::make_pair(
		std::make_pair(
			std::make_pair(s, 0), 1),
		initRoute
	));
	//std::vector<std::string> ret;
	while (!que.empty()) {
		auto now = que.front();
		que.pop();
		int number = now.first.first.first;
		if (visit[number]) continue;
		visit[number] = true;
		if (number == t) {
			if (!saveFlag) {
				ResultController* rc = new ResultController;
				rc->Parse(now.second);
				delete rc;
				break;
			}
			else return now.second;
		}
		int line = now.first.first.second;
		int distant = now.first.second;
		std::vector<std::string> route = now.second;
		for (auto& e : G[number]) {
			if (line && line != e.second) {
				std::string transferInfo;
				transferInfo = numberToName[number];
				transferInfo += " 换乘";
				transferInfo += lineVector[e.second].lineName;
				route.pop_back();
				route.push_back(transferInfo);
			}
			route.push_back(numberToName[e.first]);
			que.push(std::make_pair(
				std::make_pair(
					std::make_pair(e.first, e.second), distant + 1),
				route
			));
			route.pop_back();
			if (line && line != e.second) {
				route.pop_back();
				route.push_back(numberToName[number]);
			}
		}
	}
	return std::vector<std::string>();
}

std::vector<std::string> Subway::DrawPathFromVector(const std::vector<int>& path) {
	std::vector<std::string> ret;
	for (int i = 1; i < maxNumber; i++) {
		int x = path[i], y = path[i + 1];
		std::vector<std::string> temp = CalPath(numberToName[path[i]], numberToName[path[i + 1]], true);
		std::string a = numberToName[path[i]], b = numberToName[path[i + 1]];
		ret.insert(ret.end(), temp.begin(), temp.end() - 1);
	}
	return ret;
}

void Subway::CreateFloyd(bool plusFlag) {
	if (!plusFlag) {
		std::vector<int> newVector;
		for (int i = 0; i <= maxNumber; i++) {
			newVector.push_back(INF);
		}
		for (int i = 0; i <= maxNumber; i++) {
			floyd.push_back(newVector);
		}
		for (int i = 1; i <= maxNumber; i++) {
			floyd[i][i] = 0;
		}
		for (auto& line : lineVector) {
			for (int i = 0; i + 1 < int(line.stationVec.size()); i++) {
				Station a = line.stationVec[i], b = line.stationVec[i + 1];
				floyd[a.stationNumber][b.stationNumber] = 1;
				floyd[b.stationNumber][a.stationNumber] = 1;
			}
		}
		for (int k = 1; k <= maxNumber; k++) {
			for (int i = 1; i <= maxNumber; i++) {
				for (int j = 1; j <= maxNumber; j++) {
					floyd[i][j] = std::min(floyd[i][j], floyd[i][k] + floyd[k][j]);
				}
			}
		}
	}
	else {
		int newMaxNumber = maxNumber;
		std::map<int, std::vector<std::pair<int, int>>> transferStationMap;
		for (auto& line : lineVector) {
			for (int i = 0; i < int(line.stationVec.size()); i++) {
				if (line.stationVec[i].transferCount) {
					if (transferStationMap.find(line.stationVec[i].stationNumber) == transferStationMap.end()) {
						transferStationMap[line.stationVec[i].stationNumber] = std::vector<std::pair<int, int>>();
					}
					transferStationMap[line.stationVec[i].stationNumber].push_back(std::make_pair(line.lineNumber, ++newMaxNumber));
				}
			}
		}
		//std::cout << newMaxNumber << std::endl;
		std::vector<std::vector<int>> tempFloyd;
		std::vector<int> newVector;
		for (int i = 0; i <= newMaxNumber; i++) {
			newVector.push_back(INF);
		}
		for (int i = 0; i <= newMaxNumber; i++) {
			tempFloyd.push_back(newVector);
		}
		for (int i = 1; i <= newMaxNumber; i++) {
			tempFloyd[i][i] = 0;
		}
		for (auto& line : lineVector) {
			for (int i = 0; i + 1 < int(line.stationVec.size()); i++) {
				Station a = line.stationVec[i], b = line.stationVec[i + 1];
				int aProjectNumber = a.stationNumber, bProjectNumber = b.stationNumber;
				if (transferStationMap.find(aProjectNumber) != transferStationMap.end()) {
					for (auto x : transferStationMap[aProjectNumber]) {
						if (x.first == line.lineNumber) {
							aProjectNumber = x.second;
							break;
						}
					}
				}
				if (transferStationMap.find(bProjectNumber) != transferStationMap.end()) {
					for (auto x : transferStationMap[bProjectNumber]) {
						if (x.first == line.lineNumber) {
							bProjectNumber = x.second;
							break;
						}
					}
				}
				tempFloyd[aProjectNumber][bProjectNumber] = 1;
				tempFloyd[bProjectNumber][aProjectNumber] = 1;
			}
		}
		for (int i = 1; i <= maxNumber; i++) {
			if (transferStationMap.find(i) != transferStationMap.end()) {
				for (auto x : transferStationMap[i]) {
					for (auto y : transferStationMap[i]) {
						if (x != y) {
							tempFloyd[x.second][y.second] = 3;
							tempFloyd[y.second][x.second] = 3;
						}
					}
				}
			}
		}
		for (int k = 1; k <= newMaxNumber; k++) {
			for (int i = 1; i <= newMaxNumber; i++) {
				for (int j = 1; j <= newMaxNumber; j++) {
					tempFloyd[i][j] = std::min(tempFloyd[i][j], tempFloyd[i][k] + tempFloyd[k][j]);
				}
			}
		}
		newVector.clear();
		for (int i = 0; i <= maxNumber; i++) {
			newVector.push_back(INF);
		}
		for (int i = 0; i <= maxNumber; i++) {
			floyd.push_back(newVector);
		}
		for (int i = 1; i <= maxNumber; i++) {
			for (int j = 1; j <= maxNumber; j++) {
				if (transferStationMap.find(i) == transferStationMap.end() &&
					transferStationMap.find(j) == transferStationMap.end()) {
					floyd[i][j] = tempFloyd[i][j];
				}
				if (transferStationMap.find(i) != transferStationMap.end() &&
					transferStationMap.find(j) == transferStationMap.end()) {
					for (auto x : transferStationMap[i]) {
						floyd[i][j] = std::min(floyd[i][j], tempFloyd[x.second][j]);
					}
				}
				if (transferStationMap.find(i) == transferStationMap.end() &&
					transferStationMap.find(j) != transferStationMap.end()) {
					for (auto y : transferStationMap[j]) {
						floyd[i][j] = std::min(floyd[i][j], tempFloyd[i][y.second]);
					}
				}
				if (transferStationMap.find(i) != transferStationMap.end() &&
					transferStationMap.find(j) != transferStationMap.end()) {
					for (auto x : transferStationMap[i]) {
						for (auto y : transferStationMap[j]) {
							floyd[i][j] = std::min(floyd[i][j], tempFloyd[x.second][y.second]);
						}
					}
				}
			}
		}
	}
}

int Subway::CalculateCost(std::vector<int> path) {
	//std::vector<std::string> path = DrawPathFromVector(rawPath);
	//int ret = path.size();
	//for (auto& x : path) {
	//	if (x.find("换乘") != x.npos) {
	//		ret += 3;
	//	}
	//}
	int ret = 0;
	for (int i = 1; i + 1 < int(path.size()); i++) {
		//std::cout << numberToName[path[i]] << " " << numberToName[path[i + 1]] << " " << floyd[path[i]][path[i + 1]] << std::endl;
		ret += floyd[path[i]][path[i + 1]];
	}
	//std::cout << ret << std::endl;
	return ret;
}

void Subway::NextState(std::vector<int>& path, std::vector<int>& next) {
	int x = rand() % (int(path.size()) - 2) + 2, y;
	do {
		y = rand() % (int(path.size()) - 2) + 2;
	} while (x == y);
	next = path;
	std::swap(next[x], next[y]);
}

std::vector<int> Subway::SimulatedAnnealing(int start, double temperature, double zeroT, double downRate, bool plusFlag) {
	CreateFloyd(plusFlag);
	//return std::vector<int>();
	double T = temperature, Z = zeroT, D = downRate;
	//获取随机初始生成的评价函数值
	std::vector<int> path, answer;
	std::ifstream goodArg(goodArgFilePath);
	if (goodArg.is_open()) {
		int temp;
		while (goodArg >> temp) {
			path.push_back(temp);
		}
		for (int i = 1; i <= maxNumber; i++) {
			if (path[i] == start) {
				std::swap(path[1], path[i]);
				break;
			}
		}
		goodArg.close();
	}
	else {
		path.push_back(0);
		for (int i = 1; i <= maxNumber; i++) {
			path.push_back(i);
		}
		std::swap(path[1], path[start]);
	}
	answer = path;
	int value = CalculateCost(path), bestValue = value;
	return answer;
	//srand(time(NULL));
	srand(1120192236);
	//Count作为输出中间结果的辅助变量
	//int downCount = 0;
	while (T > Z) {
		//downCount++;
		//if (downCount == 10000) {
		//	//每随机10000次输出1次当前状态
		//	printf("%lf %d %d\n", T, value, bestValue);
		//	downCount = 0;
		//}
		std::vector<int> next;
		NextState(path, next);
		int newValue = CalculateCost(next);

		//两个状态的评价函数差值
		int deltaValue = newValue - value;
		//若新状态更优，则接受
		if (deltaValue < 0) {
			path = next;
			value = newValue;
			if (bestValue > value) {
				bestValue = value;
				answer = path;
			}
		}//否则以概率接受
		else if (rand() < exp(-deltaValue / T) * RAND_MAX) {
			path = next;
			value = newValue;
		}
		//一轮完成，温度下降
		T *= 1.0 - D;
	}
	return answer;
}

std::vector<Station> Subway::TravelAllPath(std::string start, bool plusFlag) {
	CreateGraph();
	//std::vector<int> answerNum = SimulatedAnnealing(nameToNumber[start], 0.1, 0.0001, 0.000001, plusFlag);
	//std::ofstream good("goodarg.txt");
	//for (auto x : answerNum) good << x << std::endl;
	//good.close();
	std::vector<int> answerNum = SimulatedAnnealing(nameToNumber[start], 10, 0.001, 0.0001, plusFlag);
	//return std::vector<Station>();
	std::vector<std::string> answer = DrawPathFromVector(answerNum);
	//std::cout << "------TravelAllPath Complete------" << std::endl;
	ResultController* rc = new ResultController;
	rc->Parse(answer, plusFlag);
	delete rc;
	return std::vector<Station>();
}

std::string Subway::FileTest(std::string fileName) {
	CreateGraph();
	CreateFloyd();
	std::ifstream givenAnswer(fileName);
	int givenCount;
	givenAnswer >> givenCount;
	int tot = 1, differentTot = 1;
	std::string nowStation, nextStation;
	std::map<std::string, int> vis;
	givenAnswer >> nowStation;
	vis[nowStation] = 1;
	while (givenAnswer >> nextStation) {
		//std::cout << nextStation << std::endl;
		if (nextStation.find("换乘") != nextStation.npos) {
			continue;
		}
		int nowNumber = nameToNumber[nowStation],
			nextNumber = nameToNumber[nextStation];
		if (floyd[nowNumber][nextNumber] != 1) {
			ResultController* rc = new ResultController;
			rc->Parse("error", nowStation, nextStation);
			delete rc;
			return std::string("error");
		}
		tot++;
		if (vis.find(nextStation) == vis.end()) {
			differentTot++;
			vis[nextStation] = 1;
		}
		nowStation = nextStation;
	}
	ResultController* rc = new ResultController;
	//std::cout << givenCount << " " << differentTot << std::endl;
	if (tot == givenCount && differentTot == maxNumber) {
		rc->Parse("true");
		return std::string("true");
	}
	else {
		std::string forgotStation;
		for (auto x : nameToNumber) {
			if (vis.find(x.first) == vis.end()) {
				forgotStation = x.first;
				break;
			}
		}
		rc->Parse("false", forgotStation);
	}
	delete rc;
	return std::string("false");
}
