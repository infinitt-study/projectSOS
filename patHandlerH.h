#ifndef patHandlerH
#define patHandlerH

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

#include "patientH.h"

class PatientHandler : public Patient
{
public:
	bool pat_Login()
	{
		return true;
	}

} pat;

#endif