#ifndef patientH
#define patientH

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#include "personH.h"

class Patient : public Person
{
public:
	// ���� �Է�
	void setInfo(const char* _name, const char* _ID, const char* _PW, int _YY, int _MM, int _DD) {
		Person::setInfo(_name, _ID, _PW, _YY, _MM, _DD);
	}
	// ȯ�� �ڽ��� ���� ���

	// ȯ�� �ڽ��� ���� ����

	void SOS()
	{}// ���� ����
	void inputPatient()
	{}// �������� �Է�
	void chargedDoctor()
	{}// ����ǻ�
};
#endif
