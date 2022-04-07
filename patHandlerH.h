#ifndef patHandlerH
#define patHandlerH

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

#include "patientH.h"
#include "defLenFile.h"

class PatientHandler : public Person
{
	vector<Patient> patient;
	vector<Patient>::iterator patientIt;

public:
	//bool pat_Login()
	//{
	//	return true;
	//}
	void pat_Signin() {
		char name[defNameLen], ID[defIDLen], PW[defPWLen];
		string address;
		int YY, MM, DD;

		cout << "회원가입을 진행합니다." << endl;
		cout << "이름은 ? ";
		cin.getline(name, defNameLen);
		cout << "아이디는 ? ";
		cin.getline(ID, defIDLen);
		// 아이디 중복확인
		cout << "비밀번호는 ? ";
		cin.getline(PW, defPWLen);
		cout << "태어난 연도는 ? ";
		cin >> YY;
		cout << "태어난 월은 ? ";
		cin >> MM;
		cout << "태어난 일은 ? ";
		cin >> DD;
		cout << "주소를 입력하세요."; // 주소는 띄어쓰기가 많아 getline으로 입력 받기 위해서 string 자료형 사용
		getline(cin, address);

		Patient new_patient;
		new_patient.setInfo(name, ID, PW, YY, MM, DD);
		patient.push_back(new_patient);
	}
	void pat_Find() {
		char name[defNameLen], * getname;
		int i, found;

		while (1)
		{
			cout << "\n검색할 성명 ? (검색종료 : end) ";
			cin.getline(name, defNameLen);
			if (strcmp(name, "end") == 0)
				break;
			found = 0;
			for (i = 0; i < patient.size(); i++)
			{
				getname = patient[i].getName();
				cout << "내 정보 출력" << endl;
				cout << "이름\t" << "ID\t" << "생년월일\t" << "담당환자 수" << endl;
				if (strcmp(getname, name) == 0)
				{
					found = 1;
					//patient[i].showDoc();
				}
			}
			if (!found)
				cout << name << "님은 조회되지 않습니다. " << endl;
		}
	}
	//void savePatient() // 이진데이터 연결 및 save
	//{
	//	const char* file = patfile;

	//	ofstream fout(patfile, ios::out | ios::binary);
	//	if (!fout)
	//	{
	//		cout << "환자 리스트 파일 stream 실패 !!!\n";
	//		exit(-1);
	//	}

	//	//fout.write(배열 / 데이터크기);

	//	fout.close();

	//	cout << patfile << "save !!!";
	//}
	//void loadPatient() // 이진데이터 load
	//{
	//	const char* file = patfile;

	//	ifstream fin(patfile, ios::in | ios::binary);
	//	if (!fin)
	//	{
	//		cout << "환자 리스트 파일 open 실패 !!!\n";
	//		exit(-1);
	//	}
	//	fin.close();
	//	cout << patfile << "load !!!";
	//}
	//void admin_Input(const int _PK, const char* _name, const char* _ID, const int _birth)
	//{
	//	int _PK = 0;
	//	char name[20], ID[20], birth[20];

	//	for (; _PK < ; _PK++)
	//	{
	//		cout << "환자 이름(성명)을 입력해주세요. : ";
	//		cin >> name;

	//		if (strcmp(name, "end") == 0) {
	//			break;


	//			cout << "ID를 입력해주세요. : ";
	//			cin >> ID;
	//			cout << "생년월일을 입력해주세요.(ex.890101) : ";
	//			cin >> birth;
	//		}
	//	}
	//}

	static const char* getPatName(int _PK) {
		//PK을 통해서 name
		return "hhh";
	}
};
#endif