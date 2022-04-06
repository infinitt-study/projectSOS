//#include<vld.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

#include "docHandlerH.h"
#include "patHandlerH.h"
#include "admHandlerH.h"


int main() {
	int role = 0;
	bool login = false;
	AdminHandler admin_handler;
	DoctorHandler doc_handler;
	PatientHandler pat_handler;

	doc_handler.loadDoctor();


	//로그인 확인
	while (!login) {
		cout << "접근 권한 선택 [ 1 : 관리자(admin), 2 : 환자(patient), 3 : 의사(doctor) ] : ";
		cin >> role;
		
		switch (role) {
		case 1: //admin
			login = admin_handler.admin_Login();
			break;
		case 2:
			login = doc_handler.doc_Login();
			break;
		case 3:
			login = pat_handler.pat_Login();
			break;
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}
		cin.clear(); // 문자열 비우기
		cin.ignore(); // 버퍼 제거
	}

	// 로그인 되었을 경우 작성

}