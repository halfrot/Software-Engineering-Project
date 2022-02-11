/*
* @Author lai yuhang
* Create Time   : 2022/01/31
* Last Edit Time: 2022/02/08
*/
#pragma once
#include"pch.h"
#include"controller.h"
#include"line.h"
class SendFileController :
	public Controller {
protected:
	Line queryLine;
	virtual void PrintMyLog();
public:
	bool Parse(Line line);
	bool Parse(const std::map<std::string, int>& m);
};

