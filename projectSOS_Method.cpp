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
			// doc_handler.doctor[i].showPat(j) : ��� ȯ��PK
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

	//�α��� Ȯ��
	while (!login) {
		cout << "���� ���� ���� [ 1 : ������(admin), 2 : �ǻ�(doctor), 3 : ȯ��(patient) ] : ";
		cin >> role;
		
		switch (role) {
		case 1: //admin(������)
			login = admin_handler.admin_Login();
			cin.clear(); // ���ڿ� ����
			cin.ignore(); // ���� ����
			break;

		case 2: //�ǻ�
			break;

		case 3: //ȯ��
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
				cout << "\n1. �α���" << endl;
				cout << "2. ȸ������" << endl;
				cout << "2. ���� ���� �˻�" << endl;
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
			cout << "�߸��� �Է��Դϴ�." << endl;
			cin.clear();
			cin.ignore();
			break;
		}
	}
	// �α��� �Ǿ��� ��� �ۼ�

}