//#include<vld.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;
//
//class Person
//{
//protected:
//	int PK;
//	char *name;
//	char *ID;
//	char *PW;
//	int birth;
//};
//
//class MainHandler
//{
//
//};
//
//class Patient : Person
//{
//
//};
//
//class PatientHandler
//{
//	pat_Login()
//	{
//
//	}
//
//	pat_Input()
//	{
//
//	}
//
//	pat_Output()
//	{
//
//	}
//} pat;
//
//class Doctor : Person
//{
//
//};
//
//class DoctorHandler
//{
//	doc_Login()
//	{
//
//	}
//} doc;
//
//class Admin : Person
//{
//	
//};

class AdminHandler
{
public:
	bool admin_Login()
	{
		char _ID[20], _PW[20];

		cout << "ID 입력 : ";
		cin >> _ID;

		cout << "PW 입력 : ";
		cin >> _PW;

		if (_ID != "admin") {
			cout << "잘못된 ID 입력" << endl;
			return false;
		}
		
		if (_PW != "1234") {
			cout << "잘못된 PW 입력" << endl;
			return false;
		}
		return true;
	}

	admin_Input(const int _PK, const char *_name, const char *_ID, const int _birth)
	{

	}

	admin_Output(PK, name, ID, birth)
	{

	}
};

int main() {
	int role = 0;
	bool login = false;
	AdminHandler admin_handler;

	//로그인 확인
	while (!login) {
		cout << "접근 권한 선택 : ";
		cin >> role;
		
		switch (role) {
		case 1: //admin
			login = admin_handler.admin_Login();
			break;
		case 2: //pat
			break;
		case 3: //doc
			break;
		}
	}

	// 로그인 되었을 경우 작성

}