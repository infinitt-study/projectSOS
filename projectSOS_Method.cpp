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
	doc_handler.doc_Load();
	pat_handler.pat_Load();

	//�α��� Ȯ��
	re_login_main:
	while (!login) {
		cout << "===========================================================================" << endl;
		cout << "���� ���� [ 1 : ������(admin), 2 : �ǻ�(doctor), 3 : ȯ��(patient) ] " << endl;
		cout << "\n���� ������ �������ּ��� : ";
		cin >> role;
		
		switch (role) {
		case 1: //admin(������) ����
			re_login_adm:
			login = admin_handler.admin_Login();
			if (!login)
				goto re_login_adm; // �ٽ� �α���/ȸ������ ȭ��
			while (!menu)
			{
				cout << "\n==============================" << endl;
				cout << "1. �ǻ� ����Ʈ ����" << endl;
				cout << "2. ȯ�� ����Ʈ ����" << endl;
				cout << "3. �α׾ƿ�" << endl;
				cout << "\n�޴��� �������ּ��� : ";
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
					goto re_login_main; // �α׾ƿ� �� �ٽ� �α���/ȸ������ ȭ��
					break;
				}
			}
			break;

		case 2: //�ǻ� ����
			while (!menu)
			{
			re_login_doc:
				cout << "\n==============================" << endl;
				cout << "1. �α���" << endl;
				cout << "2. ȸ������" << endl;
				cout << "\n�޴��� �������ּ��� : ";
				cin >> choice;

				switch (choice)
				{
				case 1:
					login = doc_handler.doc_Login();
					if (!login)
						goto re_login_doc; // �ٽ� �α���/ȸ������ ȭ��

					while (!menu)
					{
						cout << "\n==============================" << endl;
						cout << "1. �� �α��� ����" << endl;
						cout << "2. ��� ȯ�� �߰�" << endl;
						cout << "3. ��� ȯ�� ����" << endl;
						cout << "4. �α׾ƿ�" << endl;
						cout << "\n�޴��� �������ּ��� : ";
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
							goto re_login_doc; // �α׾ƿ� �� �ٽ� �α���/ȸ������ ȭ��
							break;
						}
					}
					break;
				case 2: doc_handler.doc_Signin();
					doc_handler.doc_Save();
					pat_handler.pat_Save();
					goto re_login_main; // ȸ������ �� �ٽ� �α���
					break;
				}
			}
			break;

		case 3: //ȯ�� ����
			while (!menu)
			{
			re_login_pat:
				cout << "\n==============================" << endl;
				cout << "1. �α���" << endl;
				cout << "2. ȸ������" << endl;
				cout << "\n�޴��� �������ּ��� : ";
				cin >> choice;

				switch (choice)
				{
				case 1 :
					login = pat_handler.pat_Login();
					if(!login)
						goto re_login_pat; // �ٽ� �α���/ȸ������ ȭ��

					while (!menu)
					{
						cout << "\n==============================" << endl;
						cout << "1. �� �α��� ����" << endl;
						cout << "2. �� ��� �ǻ� ����" << endl;
						cout << "3. �α׾ƿ�" << endl;
						cout << "\n�޴��� �������ּ��� : ";
						cin >> choice;

						switch (choice)
						{
						case 1: pat_handler.myPatptr()->showPat();
							break;
						case 2 : pat_handler.pat_ToDoc(doc_handler);
							break;
						case 3 : login = pat_handler.pat_Logout();
							goto re_login_pat; // �α׾ƿ� �� �ٽ� �α���/ȸ������ ȭ��
							break;
						}
					}
					break;
				case 2: pat_handler.pat_Signin();
					doc_handler.doc_Save();
					pat_handler.pat_Save();
					goto re_login_main; // ȸ������ �� �ٽ� �α���
					break;
				}
			}
			break;

		default:
			cout << endl;
			cout << "\n�߸��� �Է��Դϴ�." << endl;
			cin.clear();
			cin.ignore();
			break;
		}
	}
	// �α��� �Ǿ��� ��� �ۼ�

}