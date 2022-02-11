/*
* @Author lai yuhang
* Create Time   : 2022/01/31
* Last Edit Time: 2022/02/10
*/
#include "command_controller.h"
#include "subway.h"
#include <fstream>
void CommandController::PrintMyLog() {
	std::cout << "CC log: " << myLog << std::endl;
}

bool CommandController::Parse(std::string command) {
	//std::cout << "command: " << command << std::endl;
	std::string argc;
	for (int i = 0; command[i] != ' '; i++) argc += command[i];
	switch (atoi(argc.c_str())) {
	case 2: {
		commandType = "#";
		commandContent = command.substr(argc.length() + 1);
		int queryLineNumber = atoi(commandContent.c_str());
		if (queryLineNumber) {
			Subway::GetInstance().LineQuery(queryLineNumber);
		}
		else {
			std::cout << "Debug: CommandController switch case2" << std::endl;
			std::cout << "incorrect input" << std::endl;
		}
		break;
	}
	case 3: {
		commandType = command.substr(argc.length() + 1, 2);
		commandContent = command.substr(argc.length() + 1 + 2 + 1);
		if (commandType == "/a") {
			std::string start = commandContent;
			Subway::GetInstance().TravelAllPath(start);
		}
		else if (commandType == "/d") {
			std::string start = commandContent;
			Subway::GetInstance().TravelAllPath(start, true);
		}
		else if (commandType == "/z") {
			std::string fileName = commandContent;
			Subway::GetInstance().FileTest(fileName);
		}
		else {
			std::cout << "Debug: CommandController switch case3" << std::endl;
			std::cout << "incorrect input" << std::endl;
		}
		break;
	}
	case 4: {
		commandType = command.substr(argc.length() + 1, 2);
		commandContent = command.substr(argc.length() + 1 + 2 + 1);
		if (commandType == "/b") {
			int sPos = 0;
			int ePos = sPos;
			while (commandContent[ePos] != ' ') ePos++;
			ePos++;
			std::string start = commandContent.substr(sPos, ePos - sPos - 1);
			std::string end = commandContent.substr(ePos);
			Subway::GetInstance().CalPath(start, end);
		}
		else {
			std::cout << "Debug: CommandController switch case4" << std::endl;
			std::cout << "incorrect input" << std::endl;
		}
		break;
	}
	default: {
		std::cout << "Debug: CommandController switch default" << std::endl;
		std::cout << "incorrect input" << std::endl;
	}
	}
	return true;
}
