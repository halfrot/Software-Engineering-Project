/*
* @Author lai yuhang
* Create Time   : 2022/01/31
* Last Edit Time: 2022/02/11
*/
#pragma once
#include"pch.h"
#include"station.h"
class Line {
public:
	Line() {
		lineNumber = 0;
	}
	int lineNumber;
	std::string lineName;
	std::vector<Station> stationVec;
};

