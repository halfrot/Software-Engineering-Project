/*
* @Author lai yuhang
* Create Time   : 2022/01/31
* Last Edit Time: 2022/02/08
*/
#pragma once
#include"pch.h"
#include"line.h"
using namespace std;
class File {
private:
	File() {
		isSaved = false;
		lineInformationFilePath = "beijing-subway.txt";
		stationNameFilePath = "station.txt";
		lineNameFilePath = "line.txt";
	}
	bool isSaved;
	map<string, int> m;
	int ReadStationNumber(string name);
public:
	std::string lineInformationFilePath;
	std::string stationNameFilePath;
	std::string lineNameFilePath;
	Line ReadLine(int lineNumber);
	void SendMap();
	static File& GetInstance() {
		static File instance;
		return instance;
	}
};

