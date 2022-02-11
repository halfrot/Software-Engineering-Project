#include"pch.h"
#include"user.h"
void Input(int type, char* input, char* output) {
	std::string rawCommandString = "-1";
	switch (type) {
	case 1:
		rawCommandString = "2 " + std::string(input);
		break;
	case 2:
		rawCommandString = "4 /b " + std::string(input);
		break;
	case 3:
		rawCommandString = "3 /a " + std::string(input);
		break;
	case 4:
		rawCommandString = "3 /d " + std::string(input);
		break;
	case 5:
		rawCommandString = "3 /z " + std::string(input);
		break;
	}
	if (rawCommandString != "-1") User::GetInstance().Command(rawCommandString);
	else return;
	User::GetInstance().GetResult(output);
}
