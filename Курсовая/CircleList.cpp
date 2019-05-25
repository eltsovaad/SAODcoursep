#include "CircleList.h"
#include<string>
#include <iostream>
using namespace std;


/*void add();
void ret();
void search();
void del_all();*/


CircleList::CircleList()
{
	head = nullptr;
	n = 0;
}

CircleList::CircleList(string data[], bool stat)
{
	add( data,  stat);
}


CircleList::~CircleList()
{
	if (head != nullptr) {
		while (head->next != head) {
			order* temp = head->next;
			head->next = temp->next;
			delete temp;
			temp = NULL;
		}
		delete head;
		head = nullptr;
	}
}

void CircleList::add(string data[], bool stat) {
	if (head == nullptr) {
		head = new order;
		head->number = data[0];
		head->date = data[2];
		head->time = data[3];
		head->fio = data[1];
		head->prev = head;
		head->next = head;
	}
	else {
		order* temp;
		temp = new order;
		temp->next = head;
		temp->prev = head->prev;
		head->prev = temp;
		temp->number = data[0];
		temp->date = data[2];
		temp->time = data[3];
		temp->fio = data[1];
	}
	n++;
	cout << "Запись успешно добавлена!" << endl;
}

void CircleList::del(string number) {
	order* temp = head;
	order* del = nullptr;
	do {
		if (temp->number == number) {
			del = temp;
			break;
		}
		else {
			temp = temp->next;
		}
	}
	while (temp != head);
	if (head->next != head) {
		if (del == head) {
			head = head->next;
		}
		del->next->prev = del->prev;
		del->prev->next = del->next;
		delete del;
		del = nullptr;
		n--;
	}
	else {
		delete head;
		head = nullptr;
		n--;
	}
}

void CircleList::search() {

}