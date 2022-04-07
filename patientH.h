#ifndef patientH
#define patientH

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#include "personH.h"

class Patient : public Person
{
	static int patPK;
	string address;
	vector<int> patient;

public:
	Patient() {}
	~Patient()
	{
		delete name;
		delete ID;
		delete PW;
	}
	// 정보 입력
	void setInfo(const char* _name, const char* _ID, const char* _PW, int _YY, int _MM, int _DD) {
		Person::setInfo(_name, _ID, _PW, _YY, _MM, _DD);

		PK = patPK;
		patPK++;
	}
	void setAddr(string adress) {

	}
	// 환자 자신의 정보 삭제
	void removePat(int _pk) {
		patient.erase(remove(patient.begin(), patient.end(), _pk), patient.end());
	}
	// 환자 자신의 정보 출력
	void showAll()
	{
		cout << "이름 : " << name << ", ID : " << ID << ", PW : " << PW << ", 생년월일 : " << YY << "/" << MM << "/" << DD << endl;
		cout << "주소 : " << address << endl;
	}
	//void SOS()
	//{}// 위급 여부
};
#endif