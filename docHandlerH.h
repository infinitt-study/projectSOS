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
		return true;
	}
	void saveDoctor()
	{
		const char* file = docfile;

		ofstream fout;
		fout.open(file, ios::out | ios::binary); // 읽기모드

		if (!fout)
		{
			cout << "saveDoctor() 파일 열기 오류";
			exit(-1);
		}

		/*fout.write((char*)&Count, sizeof(Count));

		for (int i = 0; i < Count; i++)
			fout.write((char*)(doctor[i]), sizeof(Doctor));*/

		fout.close();

		printf(docfile);
		printf(" Save !!! \n");
	}

	void loadDoctor()
	{
		const char* file = docfile;

		ifstream fin;
		fin.open(file, ios::in | ios::binary); // 읽기모드

		if (!fin)
		{
			cout << "emp_load() 파일 열기 오류";
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