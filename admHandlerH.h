#ifndef admHandlerH
#define admHandlerH
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

#include "docHandlerH.h"
#include "patHandlerH.h"

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
	/*void admin_Input(const int _PK, const char* _name, const char* _ID, const int _birth)
	{
		int _PK = 0;
		char name[20], ID[20], birth[20];

		for (; _PK < ; _PK++)
		{
			cout << "ȯ�� �̸�(����)�� �Է����ּ���. : ";
			cin >> name;

			if (strcmp(name, "end") == 0) {
				break;


			cout << "ID�� �Է����ּ���. : ";
			cin >> ID;
			cout << "��������� �Է����ּ���.(ex.890101) : ";
			cin >> birth;
		}

	}*/
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
