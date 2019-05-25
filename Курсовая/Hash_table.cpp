#include "Hash_table.h"
#include "Patient.h"
#include<string>
#include<iostream>
using namespace std;


Hash_table::Hash_table()
{
}


Hash_table::~Hash_table()
{

}

void Hash_table::add() {
	string data[4];
	string *p_data= &data[0];
	int b;
	in_data(p_data, b);
	Patient temp;
	temp.setter(data, b);
	int adr = hasher(temp.getnumber());
	if ((table[adr].getstatus() == 0) || (table[adr].getstatus() == 2)) {
		table[adr] = temp;
		table[adr].set_st(1);
		cout << "������� ������� ��������! " << endl;
		cout << endl;
	}
	else {
		adr = collision(adr);
		if (adr != -10) {
			table[adr] = temp;
			cout << "������� ������� ��������! " << endl;
			cout << endl;
		}
	}
}

Patient Hash_table::search(int notdel=1) {
	Patient found;
	string data;
	int flag = 1;
	int menu;
	if(notdel == 1) {
		cout << "�������� ����� ������: " << endl;
		cout << "1. �� ������ �����������" << endl;
		cout << "2. �� �������" << endl;
		cout << "��� �����: ";
		cin >> menu; 
	}
	else {
		menu == 1;
	}
	while (flag) {
		switch (menu) {
		case 1: {
			//����� �� ��� ������
			in_data(data, 1);
			int adr = hasher(data);
			if (adr != -10) {
				found = table[adr];
				//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!�������� ������ � ������� �������
			}
			else {
				found.set_st(4);
			}
			flag = 0;
			break;
		}
		case 2: {
			//����� �� ���
			int flag_found = 0;//���� ����, ��� ���� ������� ���
			cout << "������ ��������� ���������: " << endl;
			in_data(data, 2);
			for (int i = 0; i < N; i++) {
				if (data == table[i].getfio()) {
					flag_found++;
					string num = table[i].getnumber();
					cout << num << " " << data << endl;
				}	
			}
			if (flag_found == 0) {
				cout << "�� ������ ������� �� ���� ������� ���������" << endl;
			}
			flag = 0;
			break;
		}
		default: {
			cin.clear();
			cin.ignore();
			cout << "�������� ���� ������ ����! ���������: ";
			cin >> menu;
		}
		}
	}
	return found;
}

int Hash_table::hasher(string number) {
	int a = number[0]+number[1]+number[3]+number[4]+number[5]+number[6] +number[7] + number[8];
	int b = a;
	int k = 0;
	a = a * a;
	while (true) {
		b = b / 10;
		k++;
		if (b == 0) {
			break;
		}
	}
	a = a % ((int)pow(10, k - 1));
	a = a / 10;
	while (true) {
		a = a % N;
		if ((a < N) && (a > 0)) {
			break;
		}
	}
	return a;
}

int Hash_table:: collision(int adr, string search_num) {
	//�����
	int step = 1;
	while (true) {
		if (step > N) {
			cout << "������� �� ������!" << endl;
			adr = -10;
			break;
		}
		adr = (adr+(3*step))%50;
		if (table[adr].getstatus() == 1) {
			if (table[adr].getnumber() == search_num) {
				break;
			}
		}
		step++;
	}
	return adr;
}

int Hash_table::collision(int adr) {
	//����������
	int step = 1;
	while (true) {
		if (step > N) {
			cout << "������������ �������!" << endl;
			adr = -10;
			break;
		}
		int flag_eq = 0;
		adr = (adr + (3 * step)) % 50;
		if ((table[adr].getstatus() == 0) || (table[adr].getstatus() == 2)) {
			break;
		}
		else {
			step++;
		}
		}
	return adr;
}