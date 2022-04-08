#ifndef patientH
#define patientH

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#include "personH.h"
//#include "docHandlerH.h"

class Patient : public Person
{
	static int patPK;//환자 고유번호
	string address;//환자 주소(string 타입)
	char *toDoc;//환자 담당 의사의 고유 번호

public:
	Patient() {
		address = "";
		toDoc = NULL;
	}
	Patient(const Patient& ref) {
		Person::setInfo(ref.name, ref.ID, ref.PW, ref.YY, ref.MM, ref.DD);
		address = ref.address;
		PK = ref.PK;
		toDoc = ref.toDoc;
	}
	~Patient()
	{
		delete[] name;
		delete[] ID;
		delete[] PW;
		delete[] toDoc;
	}
	// 정보 입력
	void setInfo(const char* _name, const char* _ID, const char* _PW, int _YY, int _MM, int _DD, string _address) {
		Person::setInfo(_name, _ID, _PW, _YY, _MM, _DD);

		address = _address;
		PK = patPK;
		patPK++;
	}
	void setDocName(char *_name) {
		toDoc = new char[strlen(_name)+1];
		strcpy(toDoc, _name);
	}
	void showDocList()// 담당의사 정보 출력
	{
		if (toDoc == NULL)
			cout << "없음";
		else
			cout << toDoc;
	}
	void showPat()//환자 자신의 정보
	{
		cout << "==============================================" << endl;
		cout << "                 회원가입 정보                 " << endl;
		cout << "==============================================" << endl;
		cout << "이름 : " << name << "\t"
			<< ", ID : " << ID << "\t"
			<< ", 생년월일 : " << YY << " / " << MM << " / " << DD << endl;
		cout << "주소 : " << address << endl;
		cout << endl;
	}
	void showPatBref()//환자에게 보여지는 담당의사 정보
	{
		cout << "  " << PK << "\t" << name
			<< "\t" << YY << " / " << MM << " / " << DD << "\t\t";
		showDocList(); // 담당의사 정보 들어가는 곳
		cout << endl;
	}
	char* getToDoc() {
		return toDoc;
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
	int getPK() {
		return PK;
	}
	int getYY() {
		return YY;
	}
	int getMM() {
		return MM;
	}
	int getDD() {
		return DD;
	}
	string getAddr() {
		return address;
	}

	//void SOS()
	//{}// 위급 여부
};
#endif