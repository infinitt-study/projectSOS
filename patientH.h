#ifndef patientH
#define patientH

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#include "personH.h"

class Patient : public Person
{
	static int patPK;
	string address;
	vector<int> patient;

public:
	Patient() {}
	~Patient()
	{
		delete name;
		delete ID;
		delete PW;
	}
	// ���� �Է�
	void setInfo(const char* _name, const char* _ID, const char* _PW, int _YY, int _MM, int _DD) {
		Person::setInfo(_name, _ID, _PW, _YY, _MM, _DD);

		PK = patPK;
		patPK++;
	}
	void setAddr(string adress) {

	}
	// ȯ�� �ڽ��� ���� ����
	void removePat(int _pk) {
		patient.erase(remove(patient.begin(), patient.end(), _pk), patient.end());
	}
	// ȯ�� �ڽ��� ���� ���
	void showAll()
	{
		cout << "�̸� : " << name << ", ID : " << ID << ", PW : " << PW << ", ������� : " << YY << "/" << MM << "/" << DD << endl;
		cout << "�ּ� : " << address << endl;
	}
	//void SOS()
	//{}// ���� ����
};
#endif