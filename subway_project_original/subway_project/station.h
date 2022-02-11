/*
* @Author lai yuhang
* Create Time   : 2022/01/31
* Last Edit Time: 2022/02/07
*/
#pragma once
#include<string>
#include<list>
class Station {
public:
	int stationNumber, transferCount;
	std::string stationName;
	std::list<int> transferLineNumber;
};

