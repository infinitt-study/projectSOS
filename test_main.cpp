//#include<vld.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

//#include "doctorH.h"
#include "docHandlerH.h"
#include "patHandlerH.h"
#include "admHandlerH.h"

int Doctor::docPK = 1;

int main() {

	AdminHandler admin_handler;
	DoctorHandler doc_handler;
	PatientHandler pat_handler;

	doc_handler.doc_Signin();
	doc_handler.doc_Signin();
	cout << endl;
	doc_handler.doc_List();

	doc_handler.doc_Find();
	bool log = false;
	while (!log) {
		if (doc_handler.doc_Login()) {
			cout << "성공!!" << endl;
			log = true;
		}
		else {
			cout << "로그인 코드 실패!" << endl;
		}
	}

}