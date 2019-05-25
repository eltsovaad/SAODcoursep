#pragma once
#include <string>
#include "Patient.h"
class Hash_table
{
private:
	const int N = 50;
	Patient table[50];
	int collision(int,string);
	int collision(int);
	void in_data(string*,int);
	void in_data(string, int);
	int hasher(std::string);
	
public:
	void add();
	Patient search(int);
	void del();
	void show_all();
	Hash_table();
	~Hash_table();
};

