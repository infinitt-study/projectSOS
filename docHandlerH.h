#ifndef docHandlerH
#define docHandlerH

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

#include "doctorH.h"

#define docfile "doctor_list.dat"

class DoctorHandler : public Doctor
{
	vector<Doctor> doctor;
	vector<Doctor>::iterator doctorIt;
	int Count;

public:
	bool doc_Login()
	{
		// 작성하기
		cout << "'의사' 권한으로 로그인 되었습니다." << endl;
		return true;
	}
	void doc_Signin() {
		char name[20], ID[20], PW[20];
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
	}
	void doc_Save()
	{
		const char* file = docfile;

		ofstream fout;
		fout.open(file, ios::out | ios::binary); // 읽기모드

		if (!fout)
		{
			cout << "saveDoctor() 파일 열기 오류";
			exit(-1);
		}

		/*fout.write((char*)&Count, sizeof(Count));

		for (int i = 0; i < Count; i++)
			fout.write((char*)(doctor[i]), sizeof(Doctor));*/

		fout.close();

		printf(docfile);
		printf(" Save !!! \n");
	}

	void doc_Load()
	{
		const char* file = docfile;

		ifstream fin;
		fin.open(file, ios::in | ios::binary); // 읽기모드

		if (!fin)
		{
			cout << "emp_load() 파일 열기 오류";
			exit(-1);
		}

		/*fin.read((char*)&Count, sizeof(Count));

		for (int i = 0; i < Count; i++)
		{
			doctor[i] = new EMPLOYEE;
			fin.read((char*)(empPtr[i]), sizeof(EMPLOYEE));
		}*/
		fin.close();

		printf(docfile);
		printf(" Load!!! \n");
	}
};


#endif