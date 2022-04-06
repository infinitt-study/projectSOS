#ifndef patHandlerH
#define patHandlerH

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

#include "patientH.h"
#define patfile "patient_list.dat"

class PatientHandler : public Patient
{
public:
	bool pat_Login()
	{
		return true;
	}
	void savePatient() // 이진데이터 연결 및 save
	{
		const char* file = patfile;

		ofstream fout(patfile, ios::out | ios::binary);
		if (!fout)
		{
			cout << "환자 리스트 파일 stream 실패 !!!\n";
			return;
		}

		fout.write(배열 / 데이터크기);

		fout.close();

		cout << patfile << "save !!!";
	}
	void loadPatient() // 이진데이터 load
	{
		const char* file = patfile;

		ifstream fin(patfile, ios::in | ios::binary);
		if (!fin)
		{
			cout << "환자 리스트 파일 open 실패 !!!\n";
			return -1;
		}
		fin.close();
		cout << patfile << "load !!!";
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
} pat;

#endif