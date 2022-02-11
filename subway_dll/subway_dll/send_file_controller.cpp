/*
* @Author lai yuhang
* Create Time   : 2022/01/31
* Last Edit Time: 2022/02/08
*/
#include"pch.h"
#include"send_file_controller.h"
#include"subway.h"
void SendFileController::PrintMyLog() {
	std::cout << "SLC log: " << myLog << std::endl;
}

bool SendFileController::Parse(Line line) {
	Subway::GetInstance().SaveLine(line);
	return true;
}

bool SendFileController::Parse(const std::map<std::string, int>& m) {
	Subway::GetInstance().SaveStationNameMap(m);
	return false;
}
