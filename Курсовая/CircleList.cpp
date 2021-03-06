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

void CircleList::add(string data[]) {
	int flag = 0; order*temp = head;
	for (int i = 0; i < n; i++) {
		if ((temp->fio == data[1]) && (temp->date == data[2]) && (temp->time == data[3])) {
			flag++;
		}
	}
	if (flag == 0) {
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
			sort();
		}
		n++;
		cout << "������ ������� ���������!" << endl;
	}
	else {
		cout << "������ ����� �� �������� ��� ������" << endl;
	}
}

void CircleList::del(string number, string doc) {
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

void CircleList::sort() {
	order** tempmass = new order*[n];
	order* temp = head;
	for (int i = 0; i < n; i++) {
		string str = temp->fio;
		int number = 0;
		order* stemp = head;
		for (int j = 0; j < n; j++) {
			if (stemp->fio < str) {
				number++;
			}
		}
		tempmass[number] = temp;
		temp = temp->next;
	}
	head = tempmass[0];
	head->next = tempmass[1];
	head->prev = tempmass[n - 1];
	for (int i = 1; i < n; i++) {
		temp = tempmass[i];
		temp->prev = tempmass[i - 1];
		if (i != n - 1) {
			temp->next = tempmass[i + 1];
		}
		else {
			temp->next = head;
		}
	}
	delete[]tempmass;
	tempmass = NULL;
}

void CircleList::view_doc(string pat) {
	order* temp = head;
	cout << "������� ����� ������ � ��������� ������: " << endl;
	for (int i = 0; i < n; i++) {
		if (pat == temp->number) {
			cout << temp->fio << endl;
		}
	}
}

void CircleList::view_pat(string doc) {
	order* temp = head;
	cout <<"� ����� �������� ��������� ��������: " << endl;
	for (int i = 0; i < n; i++) {
		if (doc == temp->fio) {
			cout << temp->number << endl;
		}
	}
}