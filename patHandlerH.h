#ifndef patHandlerH
#define patHandlerH

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "patientH.h"
#define patfile "patient_list.dat"

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
		char name[20], ID[20], PW[20];
		string address;
		int YY, MM, DD;

		cout << "ȸ�������� �����մϴ�." << endl;
		cout << "�̸��� ? ";
		cin >> name;
		cout << "���̵�� ? ";
		cin >> ID;
		cout << "��й�ȣ�� ? ";
		cin >> PW;
		cout << "�¾ ������ ? ";
		cin >> YY;
		cout << "�¾ ���� ? ";
		cin >> MM;
		cout << "�¾ ���� ? ";
		cin >> DD;
		cout << "�ּҸ� �Է��ϼ���."; // �ּҴ� ���Ⱑ ���� getline���� �Է� �ޱ� ���ؼ� stringw �ڷ��� ���
		getline(cin, address);

		Patient new_patient;
		new_patient.setInfo(name, ID, PW, YY, MM, DD);
		patient.push_back(new_patient);
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

<<<<<<< HEAD
	//	//fout.write(�迭 / ������ũ��);
=======
		/*fout.write(�迭 / ������ũ��);
>>>>>>> a4a2d33a128b0207a27df36de802554f426ee137

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
};
#endif