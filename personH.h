#ifndef personH
#define personH

#include <iostream>
#include <cstring>
using namespace std;

class Person
{
protected:
	int PK;
	char *name;
	char *ID;
	char *PW;
	int YY;
	int MM;
	int DD;
public:
	void setInfo(const char* _name, const char* _ID, const char* _PW, int _YY, int _MM, int _DD) {
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
		ID = new char[strlen(_ID) + 1];
		strcpy(ID, _ID);
		PW = new char[strlen(_PW) + 1];
		strcpy(PW, _PW);
		YY = _YY;
		MM = _MM;
		DD = _DD;
	}
};

#endif