#pragma once
#include <string>
#include "Patient.h"
#include"CircleList.h"
class Hash_table
{
private:
	const int N = 50;
	Patient* table;
	int collision(int,string);
	int collision(int);
	void in_data(string*&, int&);//для добавления
	void in_data(string&, int);//для поиска
	int hasher(std::string);
	int count;
	
public:
	void add();
	int search(CircleList,int=1);
	void del(CircleList);
	void show_all();
	void del_all();
	string search_list();
	Hash_table();
	~Hash_table();
};

