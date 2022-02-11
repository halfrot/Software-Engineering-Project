/*
* @Author lai yuhang
* Create Time   : 2022/01/31
* Last Edit Time: 2022/02/11
*/
#include"pch.h"
#include"user.h"
#include"command_controller.h"
using namespace std;

void User::GetResult(char* str) {
	strcpy_s(str, result.size() + 1, result.c_str());
}

void User::CommandLine(int argc, char* argv[]) {
	//cout << "argc: " << argc << endl;
	if (argc < 2) return;
	rawCommandString = std::to_string(argc);
	for (int i = 1; i < argc; i++) {
		rawCommandString += " ";
		rawCommandString += string(argv[i]);
	}
	CommandController* cc = new CommandController;
	cc->Parse(rawCommandString);
	delete cc;
}

void User::Command(std::string CommandString) {
	rawCommandString = CommandString;
	CommandController* cc = new CommandController;
	cc->Parse(rawCommandString);
	delete cc;
}

void User::ReadRawCommand() {
	int lineNumber;
	std::cin >> lineNumber;
	rawCommandString = std::to_string(2) + " " + std::to_string(lineNumber);
	CommandController* cc = new CommandController;
	cc->Parse(rawCommandString);
	delete cc;
}

void User::PrintLine(Line line) {
	result = "";
	for (auto& station : line.stationVec) {
		result += station.stationName + " ";
	}
}

void User::PrintPath(std::vector<std::string> path, bool plusFlag) {
	//std::ofstream filetest("filetest.txt");
	int cost = int(path.size());
	if (plusFlag) {
		for (auto& stationInfo : path) {
			if (stationInfo.find("»»³Ë") != stationInfo.npos) {
				cost += 3;
			}
		}
	}
	result = "";
	result += std::to_string(cost);
	for (auto& stationInfo : path) {
		result += " ";
		//if (stationInfo.find("»»³Ë") != stationInfo.npos) {
		//	stationInfo = stationInfo.substr(0, stationInfo.find("»»³Ë") - 1);
		//}
		result += stationInfo;
	}
	//filetest << cost << endl;
	//for (auto& stationInfo : path) {
	//	filetest << stationInfo << endl;
	//}
	//filetest.close();
}

void User::PrintResult(std::string testResult) {
	result = testResult;
}
