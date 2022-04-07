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
	static int patPK;//ȯ�� ������ȣ
	string address;//ȯ�� �ּ�(string Ÿ��)
	int toDoc;//ȯ�� ��� �ǻ��� ���� ��ȣ

public:
	Patient() {}
	Patient(const Patient& ref) {
		Person::setInfo(ref.name, ref.ID, ref.PW, ref.YY, ref.MM, ref.DD);
		address = ref.address;
		PK = ref.PK;
		toDoc = ref.toDoc;
	}
	~Patient()
	{
		delete[] name;
		delete[] ID;
		delete[] PW;
	}
	// ���� �Է�
	void setInfo(const char* _name, const char* _ID, const char* _PW, int _YY, int _MM, int _DD, string _address) {
		Person::setInfo(_name, _ID, _PW, _YY, _MM, _DD);

		address = _address;
		toDoc = 0;
		PK = patPK;
		patPK++;
	}
	// ȯ�� �ڽ��� ���� ����
	/*void removePat(int _pk) {
		patient.erase(remove(patient.begin(), patient.end(), _pk), patient.end());
	}*/
	//void showDocList()// ����ǻ� ���� ���
	//{
	//	for (int i = 0; i < lengthDoc() - 1; i++) {
	//		cout << DoctorHandler::getDocName(toDoc) << ", ";
	//		//PK ���� �ش��ϴ� �ǻ� �̸� ���
	//	}
	//	cout << DoctorHandler::getDocName(toDoc);
	//}
	void showPat()//ȯ�� �ڽ��� ����
	{
		cout << "�̸� : " << name
			<< ", ID : " << ID
			<< ", PW : " << PW
			<< ", ������� : " << YY << " / " << MM << " / " << DD << endl;
		cout << "�ּ� : " << address << endl;
		cout << endl;
	}
	void showAll()//ȯ�ڿ��� �������� ����ǻ� ����
	{
		cout << "  " << name 
			<< "      " << YY << " / " << MM << " / " << DD << "\t\t"
			<< endl; // ����ǻ� ���� �Ѿ�� ��
	}
	char* getID() 
	{
		return ID;
	}
	char* getPW()
	{
		return PW;
	}
	char* getName()
	{
		return name;
	}
	//void SOS()
	//{}// ���� ����
};
#endif