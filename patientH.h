#ifndef patientH
#define patientH

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#include "personH.h"
//#include "docHandlerH.h"

class Patient : public Person
{
	static int patPK;//ȯ�� ������ȣ
	string address;//ȯ�� �ּ�(string Ÿ��)
	char *toDoc;//ȯ�� ��� �ǻ��� ���� ��ȣ

public:
	Patient() {
		address = "";
		toDoc = NULL;
	}
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
		delete[] toDoc;
	}
	// ���� �Է�
	void setInfo(const char* _name, const char* _ID, const char* _PW, int _YY, int _MM, int _DD, string _address) {
		Person::setInfo(_name, _ID, _PW, _YY, _MM, _DD);

		address = _address;
		PK = patPK;
		patPK++;
	}
	void setDocName(char *_name) {
		toDoc = new char[strlen(_name)+1];
		strcpy(toDoc, _name);
	}
	void showDocList()// ����ǻ� ���� ���
	{
		if (toDoc == NULL)
			cout << "����";
		else
			cout << toDoc;
	}
	void showPat()//ȯ�� �ڽ��� ����
	{
		cout << "==============================================" << endl;
		cout << "                 ȸ������ ����                 " << endl;
		cout << "==============================================" << endl;
		cout << "�̸� : " << name << "\t"
			<< ", ID : " << ID << "\t"
			<< ", ������� : " << YY << " / " << MM << " / " << DD << endl;
		cout << "�ּ� : " << address << endl;
		cout << endl;
	}
	void showPatBref()//ȯ�ڿ��� �������� ����ǻ� ����
	{
		cout << "  " << PK << "\t" << name
			<< "\t" << YY << " / " << MM << " / " << DD << "\t\t";
		showDocList(); // ����ǻ� ���� ���� ��
		cout << endl;
	}
	char* getToDoc() {
		return toDoc;
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
	int getPK() {
		return PK;
	}
	int getYY() {
		return YY;
	}
	int getMM() {
		return MM;
	}
	int getDD() {
		return DD;
	}
	string getAddr() {
		return address;
	}

	//void SOS()
	//{}// ���� ����
};
#endif