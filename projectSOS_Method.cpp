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

		cout << "ID �Է� : ";
		cin >> _ID;

		cout << "PW �Է� : ";
		cin >> _PW;

		if (_ID != "admin") {
			cout << "�߸��� ID �Է�" << endl;
			return false;
		}
		
		if (_PW != "1234") {
			cout << "�߸��� PW �Է�" << endl;
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

	//�α��� Ȯ��
	while (!login) {
		cout << "���� ���� ���� : ";
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

	// �α��� �Ǿ��� ��� �ۼ�

}