#pragma once
#include <string>
using namespace std;
class Patient
{
private:
	string number;
	string fio;
	string adr;
	string workplace;
	int birth;
	int status;//0-empty, 1-taken, 2-deleted
public:
	Patient();
	~Patient();
	Patient(string[], int);
	string getnumber();
	string getfio();
	int getstatus();
	void setter(string[], int);
	void set_st(int);
};

