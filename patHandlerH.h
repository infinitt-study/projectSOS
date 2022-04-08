#ifndef patHandlerH
#define patHandlerH

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "patientH.h"
#include "defLenFile.h"
class DoctorHandler;

class PatientHandler : public Patient
{
	static int size_st;
	int myPK;
	vector<Patient> patient;
	vector<Patient>::iterator patientIt;
	Patient *myPat = NULL;

public:
	Patient* myPatptr() {
		return myPat;
	}
	bool pat_Login()
	{
		char ID[defIDLen], PW[defPWLen];
		cout << "\n==============================" << endl;
		cout << "아이디를 입력하세요 : ";
		cin.ignore();
		cin.getline(ID, defIDLen);
		cout << "비밀번호를 입력하세요 : ";
		cin.getline(PW, defPWLen);

		for (int i = 0; i < patient.size(); i++) {
			if (strcmp(ID, patient[i].getID()) == 0) {
				if (strcmp(PW, patient[i].getPW()) == 0) {
					myPK = patient[i].getPK();
					myPat = &patient[i];
					
					cout << endl;
					cout << patient[i].getName() << "님 로그인 되었습니다." << endl;
					return true;
				}
				cout << "잘못된 PW 입력" << endl;
				return false;
			}
		}
		cout << "잘못된 ID 입력" << endl;
		return false;
	}
	bool pat_Logout() {
		cout << endl;
		cout << myPat->getName() << "님 로그아웃 되었습니다." << endl;
		myPat = NULL;
		return false;
	}
	void pat_Signin() {
		char name[defNameLen], ID[defIDLen], PW[defPWLen];
		string address;
		int YY, MM, DD;

		cout << "\n==============================" << endl;
		cout << "회원가입을 진행합니다." << endl;
		cin.ignore();
		cout << "==============================" << endl;
<<<<<<< HEAD
=======

>>>>>>> e1105fe750cbaba286f8c9e434d4c226b733ddd2
		cout << "이름은 ? ";
		cin.getline(name, defNameLen);
		tryAgainID: // 아이디 중복확인
		cout << "아이디는 ? ";
		cin.getline(ID, defIDLen);
		for (int i = 0; i < patient.size(); i++) 
		{
			if (strcmp(ID, patient[i].getID()) == 0)
			{
				cout << "현재 사용하고 있는 아이디입니다." << endl;
				cout << "다른 아이디를 입력해주세요." << endl;
				goto tryAgainID;
			}
		}
		cout << "비밀번호는 ? ";
		cin.getline(PW, defPWLen);
		cout << "태어난 연도는 ? ";
		cin >> YY;
		cout << "태어난 월은 ? ";
		cin >> MM;
		cout << "태어난 일은 ? ";
		cin >> DD;

		cin.ignore();
		cout << "주소는 ? "; // 주소는 띄어쓰기가 많아 getline으로 입력 받기 위해서 string 자료형 사용
		getline(cin, address);

		Patient new_patient;
		new_patient.setInfo(name, ID, PW, YY, MM, DD, address);
		patient.push_back(new_patient);
	}
	void pat_Info()
	{
		cout << "==============================================" << endl;
		cout << "                 회원가입 정보                 " << endl;
		cout << "==============================================" << endl;
		for (int i = 0; i < patient.size(); i++) {
			patient[i].showPat();
		}
	}
	void pat_ToDoc(DoctorHandler& doc_handler); // main에서 선언
	// 담당의사 이름 가져오기

	void pat_List() {
		cout << endl;
		cout << "환자 리스트 출력" << endl;
		cout << "==============================================" << endl;
		cout << "  순번\t" << "이름\t" << "생년월일\t" << "담당의사" << endl;
		cout << "==============================================" << endl;
		for (int i = 0; i < patient.size(); i++) {
			patient[i].showPatBref();
		}

		cout << "==============================================" << endl;
		cout << "총 환자 수 : " << patient.size() << endl;
		cout << "==============================================" << endl;
	}

	void pat_Find() { // 이름으로 환자 조회
		char name[defNameLen], * getname;
		int i, found;

		while (1)
		{
			cout << "\n검색할 성명 ? (검색종료:end) ";
			cin.getline(name, defNameLen);
			if (strcmp(name, "end") == 0)
				break;
			found = 0;
			for (i = 0; i < patient.size(); i++)
			{
				getname = patient[i].getName();
				if (strcmp(getname, name) == 0)
				{
					found = 1;
					patient[i].showPat();
					cout << "==============================================" << endl;
					cout << "  순번\t"<< "이름\t" << "생년월일\t" << "담당의사" << endl;
					cout << "==============================================" << endl;
					patient[i].showPatBref();
				}
			}
			if (!found)
				cout << name << "님은 조회되지 않습니다. " << endl;
		}
	}
	void pat_FindPK() { // 번호로 환자조회
		char name[defNameLen], * getname;
		int PK, getPK;
		int i, found;

		while (1)
		{
			cout << "\n검색할 환자 번호는 ? (검색종료: -1) ";
			cin >> PK;
			if (PK == -1)
				break;
			found = 0;
			for (i = 0; i < patient.size(); i++)
			{
				if (PK == patient[i].getPK())
				{
					found = 1;
					patient[i].showPat();
				}
			}
			if (!found)
				cout << PK << "번 환자은 조회되지 않습니다. " << endl;
			cin.ignore();
		}
	}
	void pat_FindSOSPK(int PK) { // 번호로 SOS 요청한 환자 조회
		int i, found = 0;
		for (i = 0; i < patient.size(); i++)
		{
			if (PK == patient[i].getPK())
			{
				found = 1;
				patient[i].showPat();
			}
		}
		if (!found)
			cout << PK << "번 환자은 조회되지 않습니다. " << endl;
	}

	void pat_Save()
	{

		ofstream fout(patfile);

		if (!fout)
		{
			cout << patfile << " 파일 열기 오류";
			return;
		}

		fout << patient.size() << endl;
		cout << "gkgkgkgkkgkg" << endl;
		for (int i = 0; i < patient.size(); i++) {
			fout << "test" << endl;
			fout << patient[i].getName() << " ";
			fout << patient[i].getID() << " ";
			fout << patient[i].getPW() << " ";
			fout << patient[i].getYY() << " ";
			fout << patient[i].getMM() << " ";
			fout << patient[i].getDD() << " ";
			fout << patient[i].getAddr() << " ";
			if(patient[i].getToDoc() == NULL)
				fout << "non" << " ";
			else
				fout << patient[i].getToDoc()<< " ";
			fout << patient[i].getPK() << endl;
		}

		fout.close();

		printf("\n=====환자 정보를 저장했습니다!!! \n");
	}

	void pat_Load()
	{
		ifstream fin(patfile);

		if (!fin)
		{
			cout << patfile << " 파일 열기 오류";
			return;
		}

		int n, PK, YY, MM, DD;
		char Name[defNameLen], ID[defIDLen], PW[defPWLen], ToDoc[defNameLen];
		string Addr;
		Patient newPat;

		fin >> n;

		for (int i = 0; i < n; i++) {
			fin >> Name;
			fin >> ID;
			fin >> PW;
			fin >> YY;
			fin >> MM;
			fin >> DD;
			fin >> Addr;
			fin >> ToDoc;
			fin >> PK;

			newPat.setInfo(Name, ID, PW, YY, MM, DD, Addr);
			if (strcmp(name, "non") != 0)
				newPat.setDocName(ToDoc);
			patient.push_back(newPat);
		}

		fin.close();

		printf("\n=====환자 정보를 불러왔습니다!!! \n");
	}

};
#endif