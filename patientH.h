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
	// 정보 입력
	void setInfo(const char* _name, const char* _ID, const char* _PW, int _YY, int _MM, int _DD) {
		Person::setInfo(_name, _ID, _PW, _YY, _MM, _DD);
	}
	// 환자 자신의 정보 출력

	// 환자 자신의 정보 삭제

	void SOS()
	{}// 위급 여부
	void inputPatient()
	{}// 개인정보 입력
	void chargedDoctor()
	{}// 담당의사
};
#endif
