/*
* @Author lai yuhang
* Create Time   : 2022/01/31
* Last Edit Time: 2022/02/11
*/
#include "result_controller.h"
#include"user.h"

void ResultController::PrintMyLog() {
	std::cout << "RC log: " << myLog << std::endl;
}

bool ResultController::Parse(Line line) {
	User::GetInstance().PrintLine(line);
	return false;
}

bool ResultController::Parse(std::string result){
	User::GetInstance().PrintResult(result);
	return false;
}

bool ResultController::Parse(std::string result, std::string forgotStation){
	User::GetInstance().PrintResult(result + "\n" + forgotStation);
	return false;
}

bool ResultController::Parse(std::string result, std::string wrongStation1, std::string wrongStation2){
	User::GetInstance().PrintResult(result + "\n" + wrongStation1 + "\n" + wrongStation2);
	return false;
}

bool ResultController::Parse(std::vector<std::string> vec, bool plusFlag) {
	User::GetInstance().PrintPath(vec, plusFlag);
	return false;
}
