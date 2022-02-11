/*
* @Author lai yuhang
* Create Time   : 2022/01/31
* Last Edit Time: 2022/02/10
*/
#include"pch.h"
#include"file.h"
#include"send_file_controller.h"
using namespace std;
int File::ReadStationNumber(string name) {
	if (!isSaved) {
		ifstream bjStation(stationNameFilePath);
		int sNumber, sCount;
		string sName;
		while (bjStation >> sNumber >> sName >> sCount) {
			m[sName] = sNumber;
			for (int i = 1; i <= sCount; i++) {
				int temp;
				bjStation >> temp;
			}
		}
		isSaved = true;
	}
	return m[name];
}

Line File::ReadLine(int number) {
	ifstream bjSubway(lineInformationFilePath);
	if (!bjSubway.is_open()) {
		cout << "Error File: ReadLine() bj_subway open file failed" << endl;
		return Line();
	}
	Line ret;
	while (bjSubway >> ret.lineName) {
		int lineNumber, stationCount;
		bjSubway >> lineNumber >> stationCount;
		//cout << "!" << ret.lineName << " " << lineNumber << " " << stationCount << endl;
		if (number != lineNumber) {
			for (int i = 0; i <= stationCount; i++) {
				string str;
				getline(bjSubway, str);
				//cout << i << str << endl;
			}
		}
		else {
			ret.lineNumber = number;
			for (int i = 1; i <= stationCount; i++) {
				Station station;
				bjSubway >> station.stationName >> station.transferCount;
				for (int j = 1; j <= station.transferCount; j++) {
					int x;
					bjSubway >> x;
					station.transferLineNumber.push_back(x);
				}
				ret.stationVec.push_back(station);
			}
			for (auto& station : ret.stationVec) {
				station.stationNumber = ReadStationNumber(station.stationName);
			}
			SendFileController* slc = new SendFileController;
			slc->Parse(ret);
			delete slc;
			return ret;
		}
	}
	//cout << number << endl;
	//cout << "Error File: ReadLine() no such Line" << endl;
	return Line();
}

void File::SendMap() {
	SendFileController* slc = new SendFileController;
	slc->Parse(m);
	delete slc;
}
