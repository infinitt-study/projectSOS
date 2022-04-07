//#include<vld.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

//#include "doctorH.h"
#include "docHandlerH.h"
#include "patHandlerH.h"
#include "admHandlerH.h"

int Doctor::docPK = 0;

int main() {

	AdminHandler admin_handler;
	DoctorHandler doc_handler;
	PatientHandler pat_handler;
	Doctor d1;

	d1.setInfo("����", "yu", "1234", 97, 7, 24);
	d1.showAll();

	Doctor d2;
	d2.setInfo("����", "hoon", "1234", 97, 7, 24);
	d2.showAll();


	

}