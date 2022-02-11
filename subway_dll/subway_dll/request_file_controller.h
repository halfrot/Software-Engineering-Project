/*
* @Author lai yuhang
* Create Time   : 2022/01/31
* Last Edit Time: 2022/02/09
*/
#pragma once
#include"pch.h"
#include"controller.h"
class RequestFileController :
	public Controller {
protected:
	int queryLineNumber;
	virtual void PrintMyLog();
public:
	RequestFileController() {
		queryLineNumber = 0;
	}
	bool Parse(int number);
	bool Parse(std::string str);
};

