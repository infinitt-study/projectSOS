#ifndef admHandlerH
#define admHandlerH
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

#include "docHandlerH.h"
#include "patHandlerH.h"

class AdminHandler : public DoctorHandler, public PatientHandler
{
public:
	bool admin_Login()
	{
		char _ID[20], _PW[20];
		cout << "ID �Է� : ";
		cin.ignore();
		cin >> _ID;
		cout << "PW �Է� : ";
		cin >> _PW;

		if (strcmp(_ID, "admin") != 0) {
			cout << "�߸��� admin ID �Է�" << endl;
			return false;
		}
		if (strcmp(_PW, "1234") != 0) {
			cout << "�߸��� admin PW �Է�" << endl;
			return false;
		}
		cout << "'������' �������� �α��� �Ǿ����ϴ�." << endl;
		return true;
	}
	/*void admin_Output(const int _PK, const char *_name, const char *_ID, const int birth)
	{
		for (; _PK <  ; _PK++) {
			cout << "ȯ���� �̸�(����) : " << _name << "\n"
				<< _name << " ȯ���� ID : " << _ID << "\n"
				<< "ȯ���� ������� : " << birth;
		}
	}*/
};
#endif