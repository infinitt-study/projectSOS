#ifndef patHandlerH
#define patHandlerH

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "patientH.h"
#define patfile "patient_list.dat"

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
		char name[20], ID[20], PW[20];
		string address;
		int YY, MM, DD;

		cout << "회원가입을 진행합니다." << endl;
		cout << "이름은 ? ";
		cin >> name;
		cout << "아이디는 ? ";
		cin >> ID;
		cout << "비밀번호는 ? ";
		cin >> PW;
		cout << "태어난 연도는 ? ";
		cin >> YY;
		cout << "태어난 월은 ? ";
		cin >> MM;
		cout << "태어난 일은 ? ";
		cin >> DD;
		cout << "주소를 입력하세요."; // 주소는 띄어쓰기가 많아 getline으로 입력 받기 위해서 stringw 자료형 사용
		getline(cin, address);

		Patient new_patient;
		new_patient.setInfo(name, ID, PW, YY, MM, DD);
		patient.push_back(new_patient);
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

<<<<<<< HEAD
	//	//fout.write(배열 / 데이터크기);
=======
		/*fout.write(배열 / 데이터크기);
>>>>>>> a4a2d33a128b0207a27df36de802554f426ee137

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
};
#endif