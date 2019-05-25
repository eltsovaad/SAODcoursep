#pragma once
#include<string>
using namespace std;
class CircleList
{
private:
	struct order
	{
		string number;
		string fio;
		string date;
		string time;
		struct order* next;//указатель на следующий элемент
		struct order* prev;
	};



	order* head;
	int n;
public:
	void add(string[], bool);
	void search();
	void del(string);
	CircleList();
	CircleList( string[], bool);
	~CircleList();
};

