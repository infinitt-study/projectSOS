#ifndef docHandlerH
#define docHandlerH

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

#include "doctorH.h"
#include "defLenFile.h"


class DoctorHandler : public Doctor
{
	vector<Doctor> doctor;
	vector<Doctor>::iterator doctorIt;

public:
<<<<<<< HEAD
	//bool doc_Login()
	//{
	//	// �ۼ��ϱ�
	//	cout << "'�ǻ�' �������� �α��� �Ǿ����ϴ�." << endl;
	//	return true;
	//}
=======
	~DoctorHandler() {

	}
	bool doc_Login()
	{
		// �ۼ��ϱ�
		cout << "'�ǻ�' �������� �α��� �Ǿ����ϴ�." << endl;
		return true;
	}
>>>>>>> a4a2d33a128b0207a27df36de802554f426ee137
	void doc_Signin() {
		char name[defNameLen], ID[defIDLen], PW[defPWLen];
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

		Doctor new_doctor;
		new_doctor.setInfo(name, ID, PW, YY, MM, DD);
		doctor.push_back(new_doctor);
	}
<<<<<<< HEAD
	//void doc_Save()
	//{
	//	const char* file = docfile;
=======
	void doc_List() {
		cout << endl;
		cout << "�ǻ� ����Ʈ ���" << endl;
		cout << "����\t" << "�̸�\t" << "ID\t" << "�������\t" << "���ȯ�� ��" << endl;
		for (int i = 0; i < doctor.size(); i++) {
			doctor[i].showAll();
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
					//doctor[i].showDoc();
				}
			}
			if (!found)
				cout << name << "���� ��ȸ���� �ʽ��ϴ�. " << endl;
		}
	}
	void doc_Save()
	{
		const char* file = docfile;
>>>>>>> a4a2d33a128b0207a27df36de802554f426ee137

	//	ofstream fout;
	//	fout.open(file, ios::out | ios::binary); // �б���

	//	if (!fout)
	//	{
	//		cout << "saveDoctor() ���� ���� ����";
	//		exit(-1);
	//	}

	//	/*fout.write((char*)&Count, sizeof(Count));

	//	for (int i = 0; i < Count; i++)
	//		fout.write((char*)(doctor[i]), sizeof(Doctor));*/

	//	fout.close();

	//	printf(docfile);
	//	printf(" Save !!! \n");
	//}

	//void doc_Load()
	//{
	//	const char* file = docfile;

	//	ifstream fin;
	//	fin.open(file, ios::in | ios::binary); // �б���

	//	if (!fin)
	//	{
	//		cout << "emp_load() ���� ���� ����";
	//		exit(-1);
	//	}

	//	/*fin.read((char*)&Count, sizeof(Count));

	//	for (int i = 0; i < Count; i++)
	//	{
	//		doctor[i] = new EMPLOYEE;
	//		fin.read((char*)(empPtr[i]), sizeof(EMPLOYEE));
	//	}*/
	//	fin.close();

	//	printf(docfile);
	//	printf(" Load!!! \n");
	//}
};


#endif