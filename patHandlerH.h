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

class PatientHandler : public Patient
{
	vector<Patient> patient;
	vector<Patient>::iterator patientIt;

public:
	~PatientHandler()
	{	}
	bool pat_Login()
	{
		char ID[defIDLen], PW[defPWLen];
		cout << "���̵� �Է��ϼ��� : ";
		cin.getline(ID, defIDLen);
		cout << "��й�ȣ�� �Է��ϼ��� : ";
		cin.getline(PW, defPWLen);

		for (int i = 0; i < patient.size(); i++) {
			if (strcmp(ID, patient[i].getID()) == 0) {
				if (strcmp(PW, patient[i].getPW()) == 0) {
					cout << "'ȯ��' �������� �α��� �Ǿ����ϴ�." << endl;
					return true;
				}
				cout << "�߸��� PW �Է�" << endl;
				return false;
			}
		}
		cout << "�߸��� ID �Է�" << endl;
		return false;
	}
	void pat_Signin() {
		char name[defNameLen], ID[defIDLen], PW[defPWLen];
		string address;
		int YY, MM, DD;

		cout << "ȸ�������� �����մϴ�." << endl;
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
		cout << "ȸ������ ���� ���" << endl;
		cout << "==============================================" << endl;
		for (int i = 0; i < patient.size(); i++) {
			patient[i].showPat();
		}
	}
	void pat_Find() {
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
				}
			}
			if (!found)
				cout << name << "���� ��ȸ���� �ʽ��ϴ�. " << endl;
		}
	}
	//void savePatient() // ���������� ���� �� save
	//{
	//	const char* file = patfile;

	//	ofstream fout(patfile, ios::out | ios::binary);
	//	if (!fout)
	//	{
	//		cout << "ȯ�� ����Ʈ ���� stream ���� !!!\n";
	//		exit(-1);
	//	}

	//	//fout.write(�迭 / ������ũ��);

	//	fout.close();

	//	cout << patfile << "save !!!";
	//}
	//void loadPatient() // ���������� load
	//{
	//	const char* file = patfile;

	//	ifstream fin(patfile, ios::in | ios::binary);
	//	if (!fin)
	//	{
	//		cout << "ȯ�� ����Ʈ ���� open ���� !!!\n";
	//		exit(-1);
	//	}
	//	fin.close();
	//	cout << patfile << "load !!!";
	//}
	//void admin_Input(const int _PK, const char* _name, const char* _ID, const int _birth)
	//{
	//	int _PK = 0;
	//	char name[20], ID[20], birth[20];

	//	for (; _PK < ; _PK++)
	//	{
	//		cout << "ȯ�� �̸�(����)�� �Է����ּ���. : ";
	//		cin >> name;

	//		if (strcmp(name, "end") == 0) {
	//			break;


	//			cout << "ID�� �Է����ּ���. : ";
	//			cin >> ID;
	//			cout << "��������� �Է����ּ���.(ex.890101) : ";
	//			cin >> birth;
	//		}
	//	}
	//}

	static const char* getPatName(int _PK) {
		//PK�� ���ؼ� name
		return "hhh";
	}
};
#endif