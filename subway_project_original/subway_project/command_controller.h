/*
* @Author lai yuhang
* Create Time   : 2022/01/31
* Last Edit Time: 2022/01/31
*/
#pragma once
#include "controller.h"
class CommandController :
	public Controller {
protected:
	std::string commandType;
	std::string commandContent;
	virtual void PrintMyLog();
public:
	/*
	* rawCommandString format:
	* "$argc $arg1 $arg2 ..."
	*/
	bool Parse(std::string command);
};

