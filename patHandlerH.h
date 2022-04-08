#ifndef patHandlerH
#define patHandlerH

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "patientH.h"
#include "defLenFile.h"
class DoctorHandler;

class PatientHandler : public Patient
{
	static int size_st;
	int myPK;
	vector<Patient> patient;
	vector<Patient>::iterator patientIt;
	Patient *myPat = NULL;

public:
	Patient* myPatptr() {
		return myPat;
	}
	bool pat_Login()
	{
		char ID[defIDLen], PW[defPWLen];
		cout << "\n==============================" << endl;
		cout << "���̵� �Է��ϼ��� : ";
		cin.ignore();
		cin.getline(ID, defIDLen);
		cout << "��й�ȣ�� �Է��ϼ��� : ";
		cin.getline(PW, defPWLen);

		for (int i = 0; i < patient.size(); i++) {
			if (strcmp(ID, patient[i].getID()) == 0) {
				if (strcmp(PW, patient[i].getPW()) == 0) {
					myPK = patient[i].getPK();
					myPat = &patient[i];
					
					cout << endl;
					cout << patient[i].getName() << "�� �α��� �Ǿ����ϴ�." << endl;
					return true;
				}
				cout << "�߸��� PW �Է�" << endl;
				return false;
			}
		}
		cout << "�߸��� ID �Է�" << endl;
		return false;
	}
	bool pat_Logout() {
		cout << endl;
		cout << myPat->getName() << "�� �α׾ƿ� �Ǿ����ϴ�." << endl;
		myPat = NULL;
		return false;
	}
	void pat_Signin() {
		char name[defNameLen], ID[defIDLen], PW[defPWLen];
		string address;
		int YY, MM, DD;

		cout << "\n==============================" << endl;
		cout << "ȸ�������� �����մϴ�." << endl;
		cin.ignore();
		cout << "==============================" << endl;
<<<<<<< HEAD
=======

>>>>>>> e1105fe750cbaba286f8c9e434d4c226b733ddd2
		cout << "�̸��� ? ";
		cin.getline(name, defNameLen);
		tryAgainID: // ���̵� �ߺ�Ȯ��
		cout << "���̵�� ? ";
		cin.getline(ID, defIDLen);
		for (int i = 0; i < patient.size(); i++) 
		{
			if (strcmp(ID, patient[i].getID()) == 0)
			{
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
		cout << "�ּҴ� ? "; // �ּҴ� ���Ⱑ ���� getline���� �Է� �ޱ� ���ؼ� string �ڷ��� ���
		getline(cin, address);

		Patient new_patient;
		new_patient.setInfo(name, ID, PW, YY, MM, DD, address);
		patient.push_back(new_patient);
	}
	void pat_Info()
	{
		cout << "==============================================" << endl;
		cout << "                 ȸ������ ����                 " << endl;
		cout << "==============================================" << endl;
		for (int i = 0; i < patient.size(); i++) {
			patient[i].showPat();
		}
	}
	void pat_ToDoc(DoctorHandler& doc_handler); // main���� ����
	// ����ǻ� �̸� ��������

	void pat_List() {
		cout << endl;
		cout << "ȯ�� ����Ʈ ���" << endl;
		cout << "==============================================" << endl;
		cout << "  ����\t" << "�̸�\t" << "�������\t" << "����ǻ�" << endl;
		cout << "==============================================" << endl;
		for (int i = 0; i < patient.size(); i++) {
			patient[i].showPatBref();
		}

		cout << "==============================================" << endl;
		cout << "�� ȯ�� �� : " << patient.size() << endl;
		cout << "==============================================" << endl;
	}

	void pat_Find() { // �̸����� ȯ�� ��ȸ
		char name[defNameLen], * getname;
		int i, found;

		while (1)
		{
			cout << "\n�˻��� ���� ? (�˻�����:end) ";
			cin.getline(name, defNameLen);
			if (strcmp(name, "end") == 0)
				break;
			found = 0;
			for (i = 0; i < patient.size(); i++)
			{
				getname = patient[i].getName();
				if (strcmp(getname, name) == 0)
				{
					found = 1;
					patient[i].showPat();
					cout << "==============================================" << endl;
					cout << "  ����\t"<< "�̸�\t" << "�������\t" << "����ǻ�" << endl;
					cout << "==============================================" << endl;
					patient[i].showPatBref();
				}
			}
			if (!found)
				cout << name << "���� ��ȸ���� �ʽ��ϴ�. " << endl;
		}
	}
	void pat_FindPK() { // ��ȣ�� ȯ����ȸ
		char name[defNameLen], * getname;
		int PK, getPK;
		int i, found;

		while (1)
		{
			cout << "\n�˻��� ȯ�� ��ȣ�� ? (�˻�����: -1) ";
			cin >> PK;
			if (PK == -1)
				break;
			found = 0;
			for (i = 0; i < patient.size(); i++)
			{
				if (PK == patient[i].getPK())
				{
					found = 1;
					patient[i].showPat();
				}
			}
			if (!found)
				cout << PK << "�� ȯ���� ��ȸ���� �ʽ��ϴ�. " << endl;
			cin.ignore();
		}
	}
	void pat_FindSOSPK(int PK) { // ��ȣ�� SOS ��û�� ȯ�� ��ȸ
		int i, found = 0;
		for (i = 0; i < patient.size(); i++)
		{
			if (PK == patient[i].getPK())
			{
				found = 1;
				patient[i].showPat();
			}
		}
		if (!found)
			cout << PK << "�� ȯ���� ��ȸ���� �ʽ��ϴ�. " << endl;
	}

	void pat_Save()
	{

		ofstream fout(patfile);

		if (!fout)
		{
			cout << patfile << " ���� ���� ����";
			return;
		}

		fout << patient.size() << endl;
		cout << "gkgkgkgkkgkg" << endl;
		for (int i = 0; i < patient.size(); i++) {
			fout << "test" << endl;
			fout << patient[i].getName() << " ";
			fout << patient[i].getID() << " ";
			fout << patient[i].getPW() << " ";
			fout << patient[i].getYY() << " ";
			fout << patient[i].getMM() << " ";
			fout << patient[i].getDD() << " ";
			fout << patient[i].getAddr() << " ";
			if(patient[i].getToDoc() == NULL)
				fout << "non" << " ";
			else
				fout << patient[i].getToDoc()<< " ";
			fout << patient[i].getPK() << endl;
		}

		fout.close();

		printf("\n=====ȯ�� ������ �����߽��ϴ�!!! \n");
	}

	void pat_Load()
	{
		ifstream fin(patfile);

		if (!fin)
		{
			cout << patfile << " ���� ���� ����";
			return;
		}

		int n, PK, YY, MM, DD;
		char Name[defNameLen], ID[defIDLen], PW[defPWLen], ToDoc[defNameLen];
		string Addr;
		Patient newPat;

		fin >> n;

		for (int i = 0; i < n; i++) {
			fin >> Name;
			fin >> ID;
			fin >> PW;
			fin >> YY;
			fin >> MM;
			fin >> DD;
			fin >> Addr;
			fin >> ToDoc;
			fin >> PK;

			newPat.setInfo(Name, ID, PW, YY, MM, DD, Addr);
			if (strcmp(name, "non") != 0)
				newPat.setDocName(ToDoc);
			patient.push_back(newPat);
		}

		fin.close();

		printf("\n=====ȯ�� ������ �ҷ��Խ��ϴ�!!! \n");
	}

};
#endif