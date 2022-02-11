/*
* @Author lai yuhang
* Create Time   : 2022/01/31
* Last Edit Time: 2022/02/11
*/
#pragma once
#include "controller.h"
#include"line.h"
class ResultController :
	public Controller {
protected:
	std::string resultType;
	std::string resultContent;
	virtual void PrintMyLog();
public:
	bool Parse(Line line);
	bool Parse(std::string result);
	bool Parse(std::string result, std::string forgotStation);
	bool Parse(std::string result, std::string wrongStation1, std::string wrongStation2);
	bool Parse(std::vector<std::string> vec, bool plusFlag = false);
};

