#ifndef doctorH
#define doctorH

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#include "personH.h"
#include "patHandlerH.h"

class Doctor : public Person
{
	static int docPK;
	vector<int> toPatList; // 담당환자 리스트

public:
	Doctor() { }
	Doctor(const Doctor& ref) {
		Person::setInfo(ref.name, ref.ID, ref.PW, ref.YY, ref.MM, ref.DD);
		PK = ref.PK;
		toPatList = ref.toPatList;
	}
	~Doctor() {
		delete[] name;
		delete[] ID;
		delete[] PW;
		//cout << PK << ": this is clear" << endl;
	}
	void setInfo(const char* _name, const char* _ID, const char* _PW, int _YY, int _MM, int _DD) {
		Person::setInfo(_name, _ID, _PW, _YY, _MM, _DD);
		toPatList.push_back(1);
		PK = docPK;
		docPK++;
	}
	void addPat(int _pat_pk) {
		if (find(toPatList.begin(), toPatList.end(), _pat_pk) == toPatList.end()) // 1 명만 넣기
			toPatList.push_back(_pat_pk);
		// 환자 객체에 의사 PK 넣는법 구현하기!!
	}
	void removePat(int _pat_pk) {
		toPatList.erase(remove(toPatList.begin(), toPatList.end(), _pat_pk), toPatList.end());
	}
	int showPat(int i) {
		return toPatList[i];
	}
	int lengthPat() {
		return toPatList.size();
	}
	void sortPat() {
		sort(toPatList.begin(), toPatList.end());
	}
	int getPK() {
		return PK;
	}
	char* getName() {
		return name;
	}
	char* getID() {
		return ID;
	}
	char* getPW() {
		return PW;
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
	vector<int> getToPatList() {
		return toPatList;
	}
	// 환자 class 필요
	void showPatList() {// 담당한 환자 이름 리스트 띄우기
		int i;
		for(i = 0;i<lengthPat()-1; i++){
			cout << PatientHandler::getPatName(toPatList[i]) << ", ";
			// PK 값에 해당하는 환자 이름 출력
		}
		cout << PatientHandler::getPatName(toPatList[i]);
	}
	void showDoc() {
		cout << "이름 : " << name << "\t";
		cout << "생년월일 : " << YY << '/' << MM << '/' << DD << "\t";
		cout << "ID : " << ID << endl;
		cout << "담당환자 : ";
		showPatList();
		cout << endl;
	}
	void showAll() {
		cout << PK << "\t" << name << "\t" << ID << "\t"
			<< YY << '/' << MM << '/' << DD << "\t\t" << lengthPat() << endl;

	}
};
#endif