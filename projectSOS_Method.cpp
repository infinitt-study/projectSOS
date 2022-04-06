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


	//�α��� Ȯ��
	while (!login) {
		cout << "���� ���� ���� [ 1 : ������(admin), 2 : ȯ��(patient), 3 : �ǻ�(doctor) ] : ";
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
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}
		cin.clear(); // ���ڿ� ����
		cin.ignore(); // ���� ����
	}

	// �α��� �Ǿ��� ��� �ۼ�

}