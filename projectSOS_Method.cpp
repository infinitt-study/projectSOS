//#include<vld.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include<time.h>

using namespace std;

//#include "doctorH.h"
#include "docHandlerH.h"
#include "patHandlerH.h"
#include "admHandlerH.h"

int Doctor::docPK = 1;
int Patient::patPK = 1;

void PatientHandler::pat_ToDoc(DoctorHandler& doc_handler) {
	for (int i = 0; i < doc_handler.doctor.size(); i++) {
		for (int j = 0; j < doc_handler.doctor[i].lengthPat(); j++) {
			// doc_handler.doctor[i].showPat(j) : 담당 환자PK
			for (int k = 0; k < patient.size(); k++) {
				if (patient[k].getPK() == doc_handler.doctor[i].showPat(j))
					patient[k].setDocName(doc_handler.doctor[i].getName());
			}
		}
	}
}

int main() {
	int role, menu = 0;
	int choice = 1;
	bool login = false;
	AdminHandler admin_handler;
	DoctorHandler doc_handler;
	PatientHandler pat_handler;

	//doc_handler.doc_Load();

	//로그인 확인
	while (!login) {
		cout << "접근 권한 선택 [ 1 : 관리자(admin), 2 : 의사(doctor), 3 : 환자(patient) ] : ";
		cin >> role;
		
		switch (role) {
		case 1: //admin(관리자)
			login = admin_handler.admin_Login();
			cin.clear(); // 문자열 비우기
			cin.ignore(); // 버퍼 제거
			break;

		case 2: //의사
			break;

		case 3: //환자
			/*re_login:
			login = pat_handler.pat_Login();
			cin.clear();
			cin.ignore();
			
			if (!login) {
				pat_handler.pat_Signin();
				goto re_login;
			}*/

			while (!menu)
			{
				cout << "\n1. 로그인" << endl;
				cout << "2. 회원가입" << endl;
				cout << "2. 가입 정보 검색" << endl;
				cout << "Select (1 ~ 4) ";
				cin >> choice;

				switch (choice)
				{
				case 1 : pat_handler.pat_Login();
					break;
				case 2: pat_handler.pat_Signin();
					break;
				case 3: pat_handler.pat_Info();
					break;
				case 4: pat_handler.pat_Find();
					break;
				case 5: menu = 0;
					break;
				}
			}
			break;

		default:
			cout << "잘못된 입력입니다." << endl;
			cin.clear();
			cin.ignore();
			break;
		}
	}
	// 로그인 되었을 경우 작성

}