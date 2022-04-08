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

	//pat_handler.pat_ToDoc(doc_handler);
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
	doc_handler.doc_Load();
	pat_handler.pat_Load();

	//로그인 확인
	re_login_main:
	while (!login) {
		cout << "===========================================================================" << endl;
		cout << "접근 권한 [ 1 : 관리자(admin), 2 : 의사(doctor), 3 : 환자(patient) ] " << endl;
		cout << "\n접근 권한을 설정해주세요 : ";
		cin >> role;
		
		switch (role) {
		case 1: //admin(관리자) 권한
			re_login_adm:
			login = admin_handler.admin_Login();
			if (!login)
				goto re_login_adm; // 다시 로그인/회원가입 화면
			while (!menu)
			{
				cout << "\n==============================" << endl;
				cout << "1. 의사 리스트 보기" << endl;
				cout << "2. 환자 리스트 보기" << endl;
				cout << "3. 로그아웃" << endl;
				cout << "\n메뉴를 선택해주세요 : ";
				cin >> choice;

				switch (choice)
				{
				case 1: doc_handler.doc_List();
					break;
				case 2:
					pat_handler.pat_List();
					break;
				case 3:
					login = false;
					goto re_login_main; // 로그아웃 후 다시 로그인/회원가입 화면
					break;
				}
			}
			break;

		case 2: //의사 권한
			while (!menu)
			{
			re_login_doc:
				cout << "\n==============================" << endl;
				cout << "1. 로그인" << endl;
				cout << "2. 회원가입" << endl;
				cout << "\n메뉴를 선택해주세요 : ";
				cin >> choice;

				switch (choice)
				{
				case 1:
					login = doc_handler.doc_Login();
					if (!login)
						goto re_login_doc; // 다시 로그인/회원가입 화면

					while (!menu)
					{
						cout << "\n==============================" << endl;
						cout << "1. 내 로그인 정보" << endl;
						cout << "2. 담당 환자 추가" << endl;
						cout << "3. 담당 환자 삭제" << endl;
						cout << "4. 로그아웃" << endl;
						cout << "\n메뉴를 선택해주세요 : ";
						cin >> choice;

						switch (choice)
						{
						case 1: doc_handler.myDocptr()->showDoc();
							break;
						case 2: doc_handler.doc_SetAddPat();
							pat_handler.pat_List();
							pat_handler.pat_ToDoc(doc_handler);
							break;
						case 3 : doc_handler.doc_SetRemovePat();
							doc_handler.doc_SetRemovePat();
							pat_handler.pat_ToDoc(doc_handler);
							break;
						case 4 : login = doc_handler.doc_Logout();
							goto re_login_doc; // 로그아웃 후 다시 로그인/회원가입 화면
							break;
						}
					}
					break;
				case 2: doc_handler.doc_Signin();
					doc_handler.doc_Save();
					pat_handler.pat_Save();
					goto re_login_main; // 회원가입 후 다시 로그인
					break;
				}
			}
			break;

		case 3: //환자 권한
			while (!menu)
			{
			re_login_pat:
				cout << "\n==============================" << endl;
				cout << "1. 로그인" << endl;
				cout << "2. 회원가입" << endl;
				cout << "\n메뉴를 선택해주세요 : ";
				cin >> choice;

				switch (choice)
				{
				case 1 :
					login = pat_handler.pat_Login();
					if(!login)
						goto re_login_pat; // 다시 로그인/회원가입 화면

					while (!menu)
					{
						cout << "\n==============================" << endl;
						cout << "1. 내 로그인 정보" << endl;
						cout << "2. 내 담당 의사 정보" << endl;
						cout << "3. 로그아웃" << endl;
						cout << "\n메뉴를 선택해주세요 : ";
						cin >> choice;

						switch (choice)
						{
						case 1: pat_handler.myPatptr()->showPat();
							break;
						case 2 : pat_handler.pat_ToDoc(doc_handler);
							break;
						case 3 : login = pat_handler.pat_Logout();
							goto re_login_pat; // 로그아웃 후 다시 로그인/회원가입 화면
							break;
						}
					}
					break;
				case 2: pat_handler.pat_Signin();
					doc_handler.doc_Save();
					pat_handler.pat_Save();
					goto re_login_main; // 회원가입 후 다시 로그인
					break;
				}
			}
			break;

		default:
			cout << endl;
			cout << "\n잘못된 입력입니다." << endl;
			cin.clear();
			cin.ignore();
			break;
		}
	}
	// 로그인 되었을 경우 작성

}