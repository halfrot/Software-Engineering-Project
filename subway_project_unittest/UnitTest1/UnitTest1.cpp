
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
			string command = "3 /a ������";
			string answer = "/a";
			CommandController* cc = new CommandController;
			cc->Parse(command);
			Assert::AreEqual(cc->ut[0], answer);
			delete cc;
		}

		TEST_METHOD(Test_command_controller_Right3)
		{
			string command = "3 /z ������";
			string answer = "/z";
			CommandController* cc = new CommandController;
			cc->Parse(command);
			Assert::AreEqual(cc->ut[0], answer);
			delete cc;
		}
		TEST_METHOD(Test_command_controller_Right4)
		{
			string command = "4 /b ֪��· �йش�";
			string answer = "/b";
			CommandController* cc = new CommandController;
			cc->Parse(command);
			Assert::AreEqual(cc->ut[0], answer);
			delete cc;
		}

		TEST_METHOD(Test_command_controller_Wrong)
		{
			string command = "5 ֪��· �йش�";
			string answer = "incorrect input";
			CommandController* cc = new CommandController;
			cc->Parse(command);
			Assert::AreEqual(cc->ut[0], answer);
			delete cc;
		}

		TEST_METHOD(Test_Shortest_Right1)
		{
			utstr = "";
			string answer = "֪��·��������ֱ��  ����2���߻�ˮ̶��¥���  ����8���߱���ʲɲ���������  ����6���߶��ĳ�����  ����2���߽�����  ����1�����������ó";
			User::GetInstance().Command("4 /b ֪��· ��ó");
			Assert::AreEqual(utstr, answer);

		}
		TEST_METHOD(Test_Shortest_Right2)
		{
			utnum = 0;
			int answer = 2;
			User::GetInstance().Command("4 /b ֪��· �����");
			Assert::AreEqual(utnum, answer);
		}


		TEST_METHOD(Test_All_Right1)
		{
			utnum = 0;
			int answer = 757;
			User::GetInstance().Command("3 /a ֪��·");
			Assert::AreEqual(utnum, answer);
		}

		TEST_METHOD(Test_All_Right2)
		{
			utnum = 0;
			int answer = 761;
			User::GetInstance().Command("3 /a �йش�");
			Assert::AreEqual(utnum, answer);
		}


		TEST_METHOD(Test_Line_Right1)
		{
			utstr = "";
			string answer = "�����ű���������ԷԲ��԰������ѧ�����йش庣���ׯ�����ѧκ�������ͼ��ݶ���԰��ֱ���½ֿ�ƽ���������龳��ͬ���������Ų��п���Ȼͤ������վ��ұ���������������";
			User::GetInstance().Command("2 4");
			Assert::AreEqual(utstr, answer);
		}
		TEST_METHOD(Test_Line_Right2)
		{
			utstr = "";
			string answer = "������վ���Ӵ��Ӫ�㰲���ڲ��пڻ��������п���������ڹ������ڹ����������ɽ��ͤ�����廯����¥��ׯ���ֹȾ�����ͷ˫�Ͻ������Ƴ�����ׯ��ׯ����ʢ����ʢ��Ⱥ����¥��ׯ����ȼ���";
			User::GetInstance().Command("2 7");
			Assert::AreEqual(utstr, answer);
		}
		TEST_METHOD(Test_Line_Right3)
		{
			utstr = "";
			string answer = "����ׯ��֪·ƽ���������۶���ֻ�Ӫ������С����̩ׯ������ɭ�ֹ�԰���Ű���ƥ�˹�԰�������ı����ǰ����Ű����ﱱ�ֹ�¥���ʲɲ����������й�������";
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
