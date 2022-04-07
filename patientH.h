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
	int toDoc;

public:
	Patient() {}
	Patient(const Patient& ref) {
		Person::setInfo(ref.name, ref.ID, ref.PW, ref.YY, ref.MM, ref.DD);
		address = ref.address;
		PK = ref.PK;
		toDoc = ref.toDoc;
	}
	~Patient()
	{
		delete name;
		delete ID;
		delete PW;
	}
	// 정보 입력
	void setInfo(const char* _name, const char* _ID, const char* _PW, int _YY, int _MM, int _DD, string _address) {
		Person::setInfo(_name, _ID, _PW, _YY, _MM, _DD);

		address = _address;
		toDoc = 0;
		PK = patPK;
		patPK++;
	}
	// 환자 자신의 정보 삭제
	/*void removePat(int _pk) {
		patient.erase(remove(patient.begin(), patient.end(), _pk), patient.end());
	}*/

	void showPat()// 환자 자신의 정보 출력
	{
		cout << "이름 : " << name
			<< ", ID : " << ID
			<< ", PW : " << PW
			<< ", 생년월일 : " << YY << " / " << MM << " / " << DD << endl;
		cout << "주소 : " << address << endl;
		cout << endl;
	}
	char* getID() 
	{
		return ID;
	}
	char* getPW()
	{
		return PW;
	}
	char* getName()
	{
		return name;
	}
	//void SOS()
	//{}// 위급 여부
};
#endif