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

int Doctor::docPK = 1;

int main() {

	AdminHandler admin_handler;
	DoctorHandler doc_handler;
	PatientHandler pat_handler;
<<<<<<< HEAD
=======

	/*Doctor d1;
>>>>>>> a4a2d33a128b0207a27df36de802554f426ee137

	Doctor d1;
	d1.setInfo("ÇýÁ¤", "yu", "1234", 97, 7, 24);
	d1.showAll();

	Doctor d2;
	d2.setInfo("»óÈÆ", "hoon", "1234", 97, 7, 24);
<<<<<<< HEAD
	d2.showAll();
=======
	d2.showAll();*/

	doc_handler.doc_Signin();
	doc_handler.doc_Signin();
	cout << endl;
	doc_handler.doc_List();


	

>>>>>>> a4a2d33a128b0207a27df36de802554f426ee137
}