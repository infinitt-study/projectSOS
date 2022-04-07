#ifndef docHandlerH
#define docHandlerH

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

#include "doctorH.h"

#define docfile "doctor_list.dat"

class DoctorHandler : public Doctor
{
	vector<Doctor> doctor;
	vector<Doctor>::iterator doctorIt;
	int Count;

public:
	bool doc_Login()
	{
		// �ۼ��ϱ�
		cout << "'�ǻ�' �������� �α��� �Ǿ����ϴ�." << endl;
		return true;
	}
	void doc_Signin() {
		char name[20], ID[20], PW[20];
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
};


#endif