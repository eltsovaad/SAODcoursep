#include "Patient.h"
#include <string>
using namespace std;


Patient::Patient()
{
	number = "";
	fio = "";
	adr = "";
	workplace = "";
	birth = 0;
	status = 0;
}


Patient::~Patient()
{
	
}

Patient::Patient(string data[], int in_birth)
{
	number = data[0];
	fio = data[1];
	adr = data[2];
	workplace = data[3];
	birth = in_birth;
	status = 1;
}

string Patient::getnumber() {
	return number;
}

string Patient::getfio() {
	return fio;
}

string Patient::getwp() {
	return workplace;
}

string Patient::getadr() {
	return adr;
}

int Patient::getstatus() {
	return status;
}

int Patient::getbirth() {
	return birth;
}

void Patient::setter(string data[], int in_birth) {
	number = data[0];
	fio = data[1];
	adr = data[2];
	workplace = data[3];
	birth = in_birth;
	status = 1;
}

void Patient::set_st(int in_st) {
	status = in_st;
}

