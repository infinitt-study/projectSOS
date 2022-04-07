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

	AdminHandler admin_handler;
	DoctorHandler doc_handler;
	PatientHandler pat_handler;

	//doc_handler.doc_Signin();
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
	cout << "test------------------" << endl;

	//pat_handler.pat_Signin();
	//cout << endl;
	//pat_handler.pat_Info();

	//pat_handler.pat_Find();
	////pat_handler.showDocList();

	//bool log = false;
	//while (!log) {
	//	if (pat_handler.pat_Login()) {
	//		cout << "성공!!" << endl;
	//		log = true;
	//	}
	//	else {
	//		cout << "로그인 코드 실패!" << endl;
	//	}
	//}


	int sosPK = doc_handler.SOS();
	if (sosPK) {
		pat_handler.pat_FindSOSPK(sosPK);
	}

	cout << "test------------------" << endl;

	bool logout_test = doc_handler.doc_Logout();

	sosPK = doc_handler.SOS();
	if (sosPK) {
		pat_handler.pat_FindSOSPK(sosPK);
	}
}