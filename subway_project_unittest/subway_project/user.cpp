/*
* @Author lai yuhang
* Create Time   : 2022/01/31
* Last Edit Time: 2022/02/11
*/
#include "user.h"
#include"command_controller.h"
#include<iostream>
#include<fstream>
using namespace std;
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

void User::Command(std::string commandString) {
	rawCommandString = commandString;
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
	cout << line.lineName << endl;
	for (auto& station : line.stationVec) {
		cout << station.stationName << endl;
		utstr += station.stationName;                //UT1
	}
}

void User::PrintPath(std::vector<std::string> path, bool plusFlag) {
	//std::ofstream filetest("filetest.txt");
	int cost = path.size();
	if (plusFlag) {
		for (auto& stationInfo : path) {
			if (stationInfo.find("»»³Ë") != stationInfo.npos) {
				cost += 3;
			}
		}
	}
	cout << cost << endl;
	utnum = cost;
	for (auto& stationInfo : path) {
		cout << stationInfo << endl;
		utstr += stationInfo;               //UT2
	}
	//filetest << cost << endl;
	//for (auto& stationInfo : path) {
	//	filetest << stationInfo << endl;
	//}
	//filetest.close();
}

void User::PrintResult(std::string testResult) {
	cout << testResult << endl;
}
