/*
* @Author lai yuhang
* Create Time   : 2022/01/31
* Last Edit Time: 2022/02/11
*/
#pragma once
//singleton
#include"line.h"
#include<vector>
#include<map>
class Subway {
private:
	Subway() :INF(int(1e9)) {
		isCreated = false;
		maxNumber = 0;
		goodArgFilePath = "good_arg.txt";
	}
	std::vector<Line> lineVector;
	std::vector<bool> isSaved;
	std::map<std::string, int> nameToNumber;
	std::map<int, std::string> numberToName;
	bool isCreated;
	int maxNumber;
	std::vector<std::vector<std::pair<int, int>>> G;
	std::vector<bool> visit;
	std::vector<std::vector<int>> floyd;
	const int INF;
	std::string goodArgFilePath;
	void RequestStationNameMap();
	void CreateGraph();
	void RefreshGraph();
	std::vector<std::string> DrawPathFromVector(const std::vector<int>& path);
	void CreateFloyd(bool plusFlag = false);
	int CalculateCost(std::vector<int> path);
	void NextState(std::vector<int>& path, std::vector<int>& next);
	std::vector<int> SimulatedAnnealing(int start, double temperature, double zeroT, double downRate, bool plusFlag = false);
public:
	void SaveLine(Line line);
	Line LineQuery(int lineNumber, bool saveFlag = false);
	void SaveStationNameMap(const std::map<std::string, int>& map);
	std::vector<std::string> CalPath(std::string start, std::string end, bool saveFlag = false);
	/*
	* double temperature, double zeroT, double downRate,
	* 1000, 0.01, 0.00001
	*/
	std::vector<Station> TravelAllPath(std::string start, bool plusFlag = false);
	std::string FileTest(std::string fileName);
	static Subway& GetInstance() {
		static Subway instance;
		return instance;
	}
};

