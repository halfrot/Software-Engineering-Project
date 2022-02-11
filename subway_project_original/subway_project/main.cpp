/*
* @Author lai yuhang
* Create Time   : 2022/01/31
* Last Edit Time: 2022/02/11
*/
#include"user.h"
#include"file.h"
#include"subway.h"
int main(int argc, char* argv[]) {
	User::GetInstance().CommandLine(argc, argv);
	while (1) {
		User::GetInstance().ReadRawCommand();
	}
	return 0;
}