#ifndef patHandlerH
#define patHandlerH

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

#include "patientH.h"
#define patfile "patient_list.dat"

class PatientHandler : public Patient
{
public:
	bool pat_Login()
	{
		return true;
	}
	void savePatient() // ���������� ���� �� save
	{
		const char* file = patfile;

		ofstream fout(patfile, ios::out | ios::binary);
		if (!fout)
		{
			cout << "ȯ�� ����Ʈ ���� stream ���� !!!\n";
			return;
		}

		fout.write(�迭 / ������ũ��);

		fout.close();

		cout << patfile << "save !!!";
	}
	void loadPatient() // ���������� load
	{
		const char* file = patfile;

		ifstream fin(patfile, ios::in | ios::binary);
		if (!fin)
		{
			cout << "ȯ�� ����Ʈ ���� open ���� !!!\n";
			return -1;
		}
		fin.close();
		cout << patfile << "load !!!";
	}
	/*void admin_Input(const int _PK, const char* _name, const char* _ID, const int _birth)
	{
		int _PK = 0;
		char name[20], ID[20], birth[20];

		for (; _PK < ; _PK++)
		{
			cout << "ȯ�� �̸�(����)�� �Է����ּ���. : ";
			cin >> name;

			if (strcmp(name, "end") == 0) {
				break;


			cout << "ID�� �Է����ּ���. : ";
			cin >> ID;
			cout << "��������� �Է����ּ���.(ex.890101) : ";
			cin >> birth;
		}
	}*/
} pat;

#endif