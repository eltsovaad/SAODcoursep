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
	void sort();
	order* head;
	int n;

public:
	void add(string[]);
	void del(string,string);
	void view_doc(string);
	void view_pat(string);
	CircleList();
	~CircleList();
};

