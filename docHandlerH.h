#ifndef docHandlerH
#define docHandlerH

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

#include<time.h>
using namespace std;

#include "doctorH.h"
#include "patHandlerH.h"
#include "defLenFile.h"


class DoctorHandler : public Doctor
{
	int myPK;
	vector<Doctor> doctor;
	vector<Doctor>::iterator doctorIt;
	Doctor *myDoc = NULL;

public:
	Doctor* myDocptr() {
		return myDoc;
	}
	bool doc_Login()
	{
		char ID[defIDLen], PW[defPWLen];
		cout << "\n==============================" << endl;
		cout << "아이디를 입력하세요 : ";
		cin.ignore();
		cin.getline(ID, defIDLen);
		cout << "비밀번호를 입력하세요 : ";
		cin.getline(PW, defPWLen);

		for (int i = 0; i < doctor.size(); i++) {
			if (strcmp(ID, doctor[i].getID()) == 0) {
				if (strcmp(PW, doctor[i].getPW()) == 0) {
					myPK = doctor[i].getPK();
					myDoc = &doctor[i];

					cout << endl;
					cout << doctor[i].getName() << "님 로그인 되었습니다." << endl;
					return true;
				}
				cout << "잘못된 PW 입력" << endl;
				cin.ignore();
				return false;
			}
		}
		cout << "잘못된 ID 입력" << endl;
		cin.ignore();
		return false;
	}
	bool doc_Logout() {
		cout << endl;
		cout << myDoc->getName() << "님 로그아웃 되었습니다." << endl;
		myDoc = NULL;
		return false;
	}
	void doc_Signin() {
		char name[defNameLen], ID[defIDLen], PW[defPWLen];
		int YY, MM, DD;

		cout << "\n==============================" << endl;
		cout << "회원가입을 진행합니다." << endl;
		cin.ignore();
		cout << "==============================" << endl;
		cout << "이름은 ? ";
		cin.getline(name, defNameLen);
		tryAgainID:
		cout << "아이디는 ? ";
		cin.getline(ID, defIDLen);
		for (int i = 0; i < doctor.size(); i++) {
			if (strcmp(ID, doctor[i].getID()) == 0) {
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

		Doctor new_doctor;
		new_doctor.setInfo(name, ID, PW, YY, MM, DD);
		doctor.push_back(new_doctor);
	}
	void doc_List() {
		cout << endl;
		cout << "의사 리스트 출력" << endl;
		cout << "==============================================" << endl;
		cout << "  순번\t" << "이름\t" << "ID\t" << "생년월일\t" << "담당환자 수" << endl;
		cout << "==============================================" << endl;
		for (int i = 0; i < doctor.size(); i++) {
			doctor[i].showDocBref();
		}
		
		cout << "==============================================" << endl;
		cout << "총 의사 수 : " << doctor.size() << endl;
		cout << "==============================================" << endl;
	}
	void doc_Find() {
		char name[defNameLen], * getname;
		int i, found;

		while (1)
		{
			cout << "\n검색할 성명 ? (검색종료:end) ";
			cin.getline(name, defNameLen);
			if (strcmp(name, "end") == 0)
				break;
			found = 0;
			for (i = 0; i < doctor.size(); i++)
			{
				getname = doctor[i].getName();
				if (strcmp(getname, name) == 0)
				{
					found = 1;
					doctor[i].showDoc();
				}
			}
			if (!found)
				cout << name << "님은 조회되지 않습니다. " << endl;
		} // main에서 환자 리스트 보여주기
	}
	void doc_SetAddPat() { // 담당환자 추가
		// main에서 pat_handler.pat_List(); 로 환자 리스트 출력하기
		cout << endl << "환자 리스트에서 추가할 담당하는 환자 순번을 입력해주세요." << endl;
		cout << "담당환자 순번은 ? " << endl;
		int PK;
		cin >> PK;
		myDoc->addPat(PK);
		cout << "현재 담당환자 : ";
		myDoc->showPatList();
		cout << endl;
		// main 에서 PatientHandler::pat_ToDoc 실행해줘야 환자 정보까지 반영 가능
	}
	void doc_SetRemovePat() { // 담당환자 삭제
		// main에서 pat_handler.pat_List(); 로 환자 리스트 출력하기
		cout << endl << "환자 리스트에서 삭제할 담당하는 환자 순번을 입력해주세요." << endl;
		cout << "담당환자 순번은 ? " << endl;
		int PK;
		cin >> PK;
		myDoc->addPat(PK);
		cout << "현재 담당환자 : ";
		myDoc->showPatList();
		cout << endl;
		// main 에서 PatientHandler::pat_ToDoc 실행해줘야 환자 정보까지 반영 가능
	}
	void doc_Save()
	{
		
		ofstream fout(docfile);

		if (!fout)
		{
			cout << docfile << " 파일 열기 오류";
			return;
		}

		fout << doctor.size() << endl;

		for (int i = 0; i < doctor.size(); i++) {
			fout << doctor[i].getName() << " ";
			fout << doctor[i].getID() << " ";
			fout << doctor[i].getPW() << " ";
			fout << doctor[i].getYY() << " ";
			fout << doctor[i].getMM() << " ";
			fout << doctor[i].getDD() << " ";
			fout << doctor[i].getToPatList().size() << " ";
			for (int j = 0; j < doctor[i].getToPatList().size(); j++) {
				fout << doctor[i].showPat(j) << " ";
			}
			fout << doctor[i].getPK() << endl;
		}

		fout.close();

		printf("\n=====의사 정보를 저장했습니다!!! \n");
	}

	void doc_Load()
	{
		ifstream fin(docfile);

		if (!fin)
		{
			cout << docfile << " 파일 열기 오류";
			return;
		}

		int n, m, PK, YY, MM, DD, toPat;
		char Name[defNameLen], ID[defIDLen], PW[defPWLen];
		vector<int> toPatList;
		Doctor newDoc;

		fin >> n;

		for (int i = 0; i < n; i++) {
			fin >> Name;
			fin >> ID;
			fin >> PW;
			fin >> YY;
			fin >> MM;
			fin >> DD;
			fin >> m;
			for (int j = 0; j < m; j++) {
				fin >> toPat;
				toPatList.push_back(toPat);
			}
			fin >> PK;

			newDoc.setInfo(Name, ID, PW, YY, MM, DD);
			doctor.push_back(newDoc);
		}

		fin.close();

		printf("\n=====의사 정보를 불러왔습니다!!! \n");
	}
	int SOS() {

		int PK;
		ifstream fin(SOSfile);

		if (!fin) {
			cout << "파일열기 실패!!!" << endl;
			return 0;
		}
		fin >> PK;

		fin.close();
		if ((PK != 0) & (myDoc!=NULL)) {
			for (int i = 0; i < myDoc->lengthPat(); i++) {
				if (PK == myDoc->showPat(i)) {
					cout << endl;
					cout << endl;
					cout << "==============================================" << endl;
					cout << "==============================================" << endl;
					cout << PK << "번 환자가 SOS 신호를 보냈습니다" << endl;
					cout << "==============================================" << endl;
					cout << "==============================================" << endl;
					cout << endl;
					cout << endl;
					return PK;

				}
			}
			cout << PK << "번 환자가 위급하지만 담당 환자가 아닙니다" << endl;
			return 0;

		}
		return 0;
	}

	friend void PatientHandler::pat_ToDoc(DoctorHandler& doc_handler);

};


#endif