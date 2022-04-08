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

	bool doc_Login()
	{
		char ID[defIDLen], PW[defPWLen];
		cout << "���̵� �Է��ϼ��� : ";
		cin.ignore();
		cin.getline(ID, defIDLen);
		cout << "��й�ȣ�� �Է��ϼ��� : ";
		cin.getline(PW, defPWLen);

		for (int i = 0; i < doctor.size(); i++) {
			if (strcmp(ID, doctor[i].getID()) == 0) {
				if (strcmp(PW, doctor[i].getPW()) == 0) {
					myPK = doctor[i].getPK();
					myDoc = &doctor[i];

					cout << doctor[i].getName() << "�� �α��� �Ǿ����ϴ�." << endl;
					return true;
				}
				cout << "�߸��� PW �Է�" << endl;
				return false;
			}
		}
		cout << "�߸��� ID �Է�" << endl;
		return false;
	}
	bool doc_Logout() {
		cout << myDoc->getName() << "�� �α׾ƿ� �Ǿ����ϴ�." << endl;
		myDoc = NULL;
		return false;
	}
	void doc_Signin() {
		char name[defNameLen], ID[defIDLen], PW[defPWLen];
		int YY, MM, DD;

		cout << "ȸ�������� �����մϴ�." << endl;
		cout << "�̸��� ? ";
		cin.getline(name, defNameLen);
		tryAgainID:
		cout << "���̵�� ? ";
		cin.getline(ID, defIDLen);
		for (int i = 0; i < doctor.size(); i++) {
			if (strcmp(ID, doctor[i].getID()) == 0) {
				cout << "���� ����ϰ� �ִ� ���̵��Դϴ�." << endl;
				cout << "�ٸ� ���̵� �Է����ּ���." << endl;
				goto tryAgainID;
			}
		}
		cout << "��й�ȣ�� ? ";
		cin.getline(PW, defPWLen);
		cout << "�¾ ������ ? ";
		cin >> YY;
		cout << "�¾ ���� ? ";
		cin >> MM;
		cout << "�¾ ���� ? ";
		cin >> DD;
		cin.ignore();

		Doctor new_doctor;
		new_doctor.setInfo(name, ID, PW, YY, MM, DD);
		doctor.push_back(new_doctor);
	}
	void doc_List() {
		cout << endl;
		cout << "�ǻ� ����Ʈ ���" << endl;
		cout << "==============================================" << endl;
		cout << "  ����\t" << "�̸�\t" << "ID\t" << "�������\t" << "���ȯ�� ��" << endl;
		cout << "==============================================" << endl;
		for (int i = 0; i < doctor.size(); i++) {
			doctor[i].showDocBref();
		}
		
		cout << "==============================================" << endl;
		cout << "�� �ǻ� �� : " << doctor.size() << endl;
		cout << "==============================================" << endl;
	}
	void doc_Find() {
		char name[defNameLen], * getname;
		int i, found;

		while (1)
		{
			cout << "\n�˻��� ���� ? (�˻�����:end) ";
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
				cout << name << "���� ��ȸ���� �ʽ��ϴ�. " << endl;
		} // main���� ȯ�� ����Ʈ �����ֱ�
	}
	void doc_SetAddPat() { // ���ȯ�� �߰�
		// main���� pat_handler.pat_List(); �� ȯ�� ����Ʈ ����ϱ�
		cout << endl << "ȯ�� ����Ʈ���� �߰��� ����ϴ� ȯ�� ������ �Է����ּ���." << endl;
		cout << "���ȯ�� ������ ? " << endl;
		int PK;
		cin >> PK;
		myDoc->addPat(PK);
		cout << "���� ���ȯ�� : ";
		myDoc->showPatList();
		cout << endl;
		// main ���� PatientHandler::pat_ToDoc ��������� ȯ�� �������� �ݿ� ����
	}
	void doc_SetRemovePat() { // ���ȯ�� ����
		// main���� pat_handler.pat_List(); �� ȯ�� ����Ʈ ����ϱ�
		cout << endl << "ȯ�� ����Ʈ���� ������ ����ϴ� ȯ�� ������ �Է����ּ���." << endl;
		cout << "���ȯ�� ������ ? " << endl;
		int PK;
		cin >> PK;
		myDoc->addPat(PK);
		cout << "���� ���ȯ�� : ";
		myDoc->showPatList();
		cout << endl;
		// main ���� PatientHandler::pat_ToDoc ��������� ȯ�� �������� �ݿ� ����
	}
	void doc_Save()
	{
		const char* file = docfile;

		ofstream fout;
		fout.open(file, ios::out | ios::binary); // �б���

		if (!fout)
		{
			cout << "saveDoctor() ���� ���� ����";
			exit(-1);
		}

		/*fout.write((char*)&Count, sizeof(Count));

		for (int i = 0; i < Count; i++)
			fout.write((char*)(doctor[i]), sizeof(Doctor));*/

		fout.close();

		printf(docfile);
		printf(" Save !!! \n");
	}

	void doc_Load()
	{
		const char* file = docfile;

		ifstream fin;
		fin.open(file, ios::in | ios::binary); // �б���

		if (!fin)
		{
			cout << "emp_load() ���� ���� ����";
			exit(-1);
		}

		/*fin.read((char*)&Count, sizeof(Count));

		for (int i = 0; i < Count; i++)
		{
			doctor[i] = new EMPLOYEE;
			fin.read((char*)(empPtr[i]), sizeof(EMPLOYEE));
		}*/
		fin.close();

		printf(docfile);
		printf(" Load!!! \n");
	}
	int SOS() {

		int PK;
		ifstream fin(SOSfile);

		if (!fin) {
			cout << "���Ͽ��� ����!!!" << endl;
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
					cout << PK << "�� ȯ�ڰ� SOS ��ȣ�� ���½��ϴ�" << endl;
					cout << "==============================================" << endl;
					cout << "==============================================" << endl;
					cout << endl;
					cout << endl;
					return PK;

				}
			}
			cout << PK << "�� ȯ�ڰ� ���������� ��� ȯ�ڰ� �ƴմϴ�" << endl;
			return 0;

		}
		return 0;
	}

	friend void PatientHandler::pat_ToDoc(DoctorHandler& doc_handler);

};


#endif