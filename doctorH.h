#ifndef doctorH
#define doctorH

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#include "personH.h"

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
	}
	void setInfo(const char* _name, const char* _ID, const char* _PW, int _YY, int _MM, int _DD) {
		Person::setInfo(_name, _ID, _PW, _YY, _MM, _DD);
		//toPatList.push_back(1);
		PK = docPK;
		docPK++;
	}
	void addPat(int _pat_pk) {
		if (find(toPatList.begin(), toPatList.end(), _pat_pk) == toPatList.end()) {// 1 명만 넣기
			toPatList.push_back(_pat_pk);
			cout << _pat_pk << "번 환자를 담당환자로 추가했습니다.." << endl;
		}
		else
			cout << _pat_pk << "번 환자는 이미 담당하고 있습니다." << endl;
		// 환자 객체에 의사 PK 넣는법 구현하기!!
	}
	void removePat(int _pat_pk) {
		toPatList.erase(remove(toPatList.begin(), toPatList.end(), _pat_pk), toPatList.end());
		cout << _pat_pk << "번 환자를 담당환자에서 삭제했습니다." << endl;
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
	int getYY() {
		return YY;
	}
	int getMM() {
		return MM;
	}
	int getDD() {
		return DD;
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
	vector<int> getToPatList() {
		return toPatList;
	}
	// 환자 class 필요
	void showPatList() {// 담당한 환자 PK 리스트 띄우기
		if (toPatList.size() != 0) {
			int i;
			for (i = 0; i < toPatList.size() - 1; i++) {
				cout << toPatList[i] << "번, ";
				// PK 값에 해당하는 환자 이름 출력
			}
			cout << toPatList[i] << "번";
		}
		else
			cout << "없음";
	}
	void showDoc() {
		cout << "이름 : " << name << "\t";
		cout << "생년월일 : " << YY << '/' << MM << '/' << DD << "\t";
		cout << "ID : " << ID << endl;
		cout << "담당환자 : ";
		showPatList();
		cout << endl;
	}
	void showDocBref() {
		cout << "  "  << PK << "\t" << name << "\t" << ID << "\t"
			<< YY << '/' << MM << '/' << DD << "\t\t" << toPatList.size() << endl;
	}
};
#endif