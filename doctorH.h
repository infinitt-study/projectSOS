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
	vector<int> toPatList; // ���ȯ�� ����Ʈ

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
		toPatList.push_back(1);
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
	vector<int> getToPatList() {
		return toPatList;
	}
	// ȯ�� class �ʿ�
	void showPatList() {// ����� ȯ�� �̸� ����Ʈ ����
		if (lengthPat() != 0) {
			int i;
			for (i = 0; i < lengthPat() - 1; i++) {
				cout << toPatList[i] << "��, ";
				// PK ���� �ش��ϴ� ȯ�� �̸� ���
			}
			cout << toPatList[i] << "��";
		}
		else
			cout << "����";
	}
	void showDoc() {
		cout << "�̸� : " << name << "\t";
		cout << "������� : " << YY << '/' << MM << '/' << DD << "\t";
		cout << "ID : " << ID << endl;
		cout << "���ȯ�� : ";
		showPatList();
		cout << endl;
	}
	void showDocBref() {
		cout << PK << "\t" << name << "\t" << ID << "\t"
			<< YY << '/' << MM << '/' << DD << "\t\t" << lengthPat() << endl;
	}
};
#endif