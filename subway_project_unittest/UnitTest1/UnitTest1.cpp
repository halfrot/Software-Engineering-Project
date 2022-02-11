
#include "pch.h"
#include "CppUnitTest.h"
#include "../subway_project/command_controller.h"
#include "../subway_project/file.h"
#include "../subway_project/subway.h"
#include "../subway_project/user.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{

	public:
		TEST_METHOD(Test_command_controller_Right1)
		{
			string command = "2 1";
			string answer = "#";
			CommandController* cc = new CommandController;
			cc->Parse(command);
			Assert::AreEqual(cc->ut[0], answer);
			delete cc;
		}

		TEST_METHOD(Test_command_controller_Right2)
		{
			string command = "3 /a 大钟寺";
			string answer = "/a";
			CommandController* cc = new CommandController;
			cc->Parse(command);
			Assert::AreEqual(cc->ut[0], answer);
			delete cc;
		}

		TEST_METHOD(Test_command_controller_Right3)
		{
			string command = "3 /z 大钟寺";
			string answer = "/z";
			CommandController* cc = new CommandController;
			cc->Parse(command);
			Assert::AreEqual(cc->ut[0], answer);
			delete cc;
		}
		TEST_METHOD(Test_command_controller_Right4)
		{
			string command = "4 /b 知春路 中关村";
			string answer = "/b";
			CommandController* cc = new CommandController;
			cc->Parse(command);
			Assert::AreEqual(cc->ut[0], answer);
			delete cc;
		}

		TEST_METHOD(Test_command_controller_Wrong)
		{
			string command = "5 知春路 中关村";
			string answer = "incorrect input";
			CommandController* cc = new CommandController;
			cc->Parse(command);
			Assert::AreEqual(cc->ut[0], answer);
			delete cc;
		}

		TEST_METHOD(Test_Shortest_Right1)
		{
			utstr = "";
			string answer = "知春路大钟寺西直门  换乘2号线积水潭鼓楼大街  换乘8号线北段什刹海南锣鼓巷  换乘6号线东四朝阳门  换乘2号线建国门  换乘1号线永安里国贸";
			User::GetInstance().Command("4 /b 知春路 国贸");
			Assert::AreEqual(utstr, answer);

		}
		TEST_METHOD(Test_Shortest_Right2)
		{
			utnum = 0;
			int answer = 2;
			User::GetInstance().Command("4 /b 知春路 五道口");
			Assert::AreEqual(utnum, answer);
		}


		TEST_METHOD(Test_All_Right1)
		{
			utnum = 0;
			int answer = 757;
			User::GetInstance().Command("3 /a 知春路");
			Assert::AreEqual(utnum, answer);
		}

		TEST_METHOD(Test_All_Right2)
		{
			utnum = 0;
			int answer = 761;
			User::GetInstance().Command("3 /a 中关村");
			Assert::AreEqual(utnum, answer);
		}


		TEST_METHOD(Test_Line_Right1)
		{
			utstr = "";
			string answer = "安河桥北北宫门西苑圆明园北京大学东门中关村海淀黄庄人民大学魏公村国家图书馆动物园西直门新街口平安里西四灵境胡同西单宣武门菜市口陶然亭北京南站马家堡角门西公益西桥";
			User::GetInstance().Command("2 4");
			Assert::AreEqual(utstr, answer);
		}
		TEST_METHOD(Test_Line_Right2)
		{
			utstr = "";
			string answer = "北京西站湾子达官营广安门内菜市口虎坊桥珠市口桥湾磁器口广渠门内广渠门外九龙山大郊亭百子湾化工南楼梓庄欢乐谷景区垡头双合焦化厂黄厂郎辛庄黑庄户万盛西万盛东群芳高楼金花庄环球度假区";
			User::GetInstance().Command("2 7");
			Assert::AreEqual(utstr, answer);
		}
		TEST_METHOD(Test_Line_Right3)
		{
			utstr = "";
			string answer = "朱辛庄育知路平西府回龙观东大街霍营育新西小口永泰庄林萃桥森林公园南门奥林匹克公园奥体中心北土城安华桥安德里北街鼓楼大街什刹海南锣鼓巷中国美术馆";
			User::GetInstance().Command("2 8");
			Assert::AreEqual(utstr, answer);
		}
		TEST_METHOD(Test_Line_Wrong)
		{
			utstr = "";
			string answer = "";
			User::GetInstance().Command("2 30");
			Assert::AreEqual(utstr, answer);
		}
	};
}
