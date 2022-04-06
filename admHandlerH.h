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

		cout << "ID 입력 : ";
		cin >> _ID;
		cout << "PW 입력 : ";
		cin >> _PW;

		if (strcmp(_ID, "admin") != 0) {
			cout << "잘못된 admin ID 입력" << endl;
			return false;
		}
		if (strcmp(_PW, "1234") != 0) {
			cout << "잘못된 admin PW 입력" << endl;
			return false;
		}
		cout << "'관리자' 권한으로 로그인 되었습니다." << endl;
		return true;
	}
	/*void admin_Input(const int _PK, const char* _name, const char* _ID, const int _birth)
	{
		int _PK = 0;
		char name[20], ID[20], birth[20];

		for (; _PK < ; _PK++)
		{
			cout << "환자 이름(성명)을 입력해주세요. : ";
			cin >> name;

			if (strcmp(name, "end") == 0) {
				break;


			cout << "ID를 입력해주세요. : ";
			cin >> ID;
			cout << "생년월일을 입력해주세요.(ex.890101) : ";
			cin >> birth;
		}

	}*/
	/*void admin_Output(const int _PK, const char *_name, const char *_ID, const int birth)
	{
		for (; _PK <  ; _PK++) {
			cout << "환자의 이름(성명) : " << _name << "\n"
				<< _name << " 환자의 ID : " << _ID << "\n"
				<< "환자의 생년월일 : " << birth;
		}
	}*/
};

#endif
