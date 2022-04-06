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
	int birth;
};

#endif