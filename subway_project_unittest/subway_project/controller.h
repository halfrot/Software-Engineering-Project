/*
* @Author lai yuhang
* Create Time   : 2022/01/31
* Last Edit Time: 2022/02/01
*/
#pragma once
#include<string>
#include<iostream>
class Controller {
protected:
	std::string myLog;
	virtual void PrintMyLog() = 0;
};

