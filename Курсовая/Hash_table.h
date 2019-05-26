#pragma once
#include <string>
#include "Patient.h"
class Hash_table
{
private:
	const int N = 50;
	Patient* table;
	int collision(int,string);
	int collision(int);
	void in_data(string*&, int&);//��� ����������
	void in_data(string&, int);//��� ������
	int hasher(std::string);
	
public:
	void add();
	int search(int=1);
	void del();
	void show_all();
	void del_all();
	Hash_table();
	~Hash_table();
};

