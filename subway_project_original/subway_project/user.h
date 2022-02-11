/*
* @Author lai yuhang
* Create Time   : 2022/01/31
* Last Edit Time: 2022/02/11
*/
#pragma once
#include<string>
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
	void CommandLine(int argc, char* argv[]);
	void ReadRawCommand();
	void PrintLine(Line line);
	void PrintPath(std::vector<std::string> vec, bool plusFlag = false);
	void PrintResult(std::string testResult);
	static User& GetInstance() {
		static User instance;
		return instance;
	}
};

