#ifndef patHandlerH
#define patHandlerH

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

#include "patientH.h"
#include "defLenFile.h"

class PatientHandler : public Person
{
	vector<Patient> patient;
	vector<Patient>::iterator patientIt;

public:
	//bool pat_Login()
	//{
	//	return true;
	//}
	void pat_Signin() {
		char name[defNameLen], ID[defIDLen], PW[defPWLen];
		string address;
		int YY, MM, DD;

		cout << "ȸ�������� �����մϴ�." << endl;
		cout << "�̸��� ? ";
		cin.getline(name, defNameLen);
		cout << "���̵�� ? ";
		cin.getline(ID, defIDLen);
		// ���̵� �ߺ�Ȯ��
		cout << "��й�ȣ�� ? ";
		cin.getline(PW, defPWLen);
		cout << "�¾ ������ ? ";
		cin >> YY;
		cout << "�¾ ���� ? ";
		cin >> MM;
		cout << "�¾ ���� ? ";
		cin >> DD;
		cout << "�ּҸ� �Է��ϼ���."; // �ּҴ� ���Ⱑ ���� getline���� �Է� �ޱ� ���ؼ� string �ڷ��� ���
		getline(cin, address);

		Patient new_patient;
		new_patient.setInfo(name, ID, PW, YY, MM, DD);
		patient.push_back(new_patient);
	}
	void pat_Find() {
		char name[defNameLen], * getname;
		int i, found;

		while (1)
		{
			cout << "\n�˻��� ���� ? (�˻����� : end) ";
			cin.getline(name, defNameLen);
			if (strcmp(name, "end") == 0)
				break;
			found = 0;
			for (i = 0; i < patient.size(); i++)
			{
				getname = patient[i].getName();
				cout << "�� ���� ���" << endl;
				cout << "�̸�\t" << "ID\t" << "�������\t" << "���ȯ�� ��" << endl;
				if (strcmp(getname, name) == 0)
				{
					found = 1;
					//patient[i].showDoc();
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