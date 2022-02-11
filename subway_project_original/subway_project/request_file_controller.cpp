/*
* @Author lai yuhang
* Create Time   : 2022/01/31
* Last Edit Time: 2022/02/08
*/
#include "request_file_controller.h"
#include"file.h"
void RequestFileController::PrintMyLog() {
	std::cout << "RLC log: " << myLog << std::endl;
}

bool RequestFileController::Parse(int number) {
	File::GetInstance().ReadLine(number);
	return false;
}

bool RequestFileController::Parse(std::string str) {
	if (str == "request map") {
		File::GetInstance().SendMap();
	}
	return false;
}
