/*
* @Author lai yuhang
* Create Time   : 2022/01/31
* Last Edit Time: 2022/02/11
*/
#pragma once
#include"pch.h"
#include"line.h"
class User {
private:
	/*
	* rawCommandString format:
	* "$argc $arg1 $arg2 ..."
	*/
	std::string rawCommandString;
	std::string result;
public:
	void GetResult(char* str);
	void CommandLine(int argc, char* argv[]);
	void Command(std::string CommandString);
	void ReadRawCommand();
	void PrintLine(Line line);
	void PrintPath(std::vector<std::string> vec, bool plusFlag = false);
	void PrintResult(std::string result);
	static User& GetInstance() {
		static User instance;
		return instance;
	}
};

