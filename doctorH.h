#ifndef _doctorH
#define _doctorH

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#include "personH.h"

class Doctor : public Person
{
	static int docPK;
	vector<int> toPatList; // ���ȯ�� ����Ʈ

public:
	Doctor() {}
	~Doctor() {
		delete name;
		delete ID;
		delete PW;
		cout << PK << ": this is clear" << endl;
	}
	void setInfo(const char* _name, const char* _ID, const char* _PW, int _YY, int _MM, int _DD) {
		Person::setInfo(_name, _ID, _PW, _YY, _MM, _DD);
		PK = docPK;
		docPK++;
	}
	void addPat(int _pat_pk) {
		if (find(toPatList.begin(), toPatList.end(), _pat_pk) == toPatList.end()) // 1 �� �ֱ�
			toPatList.push_back(_pat_pk);
		// ȯ�� ��ü�� �ǻ� PK �ִ¹� �����ϱ�!!
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
	char* getName() {
		return name;
	}
	void showAll() {
		cout << PK << ": " << name << "// " << docPK << endl;
	}
};
#endif