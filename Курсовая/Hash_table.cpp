#include "Hash_table.h"
#include "Patient.h"
#include<string>
#include<iostream>
using namespace std;



Hash_table::Hash_table()
{
	table = new Patient[50];
}


Hash_table::~Hash_table()
{
	delete[]table;
	cout << "Dest" << endl;
}

void Hash_table::in_data(string*&data, int &b) {//����������
	setlocale(LC_ALL, "rus");
	cout << "������� ������ ��� ���������� ��������: " << endl;
	cout << "������� ��������������� �����: ";
	cin >> data[0];
	while (cin.fail()||(data[0][2]!='-')|| (data[0][9] != '\0')) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "��������������� ����� � ������ ������� �MM-NNNNNN�" << endl;
		cout << "������� ����� ��������: ";
		cin >> data[0];
	}
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "������� ���: ";
	getline(cin,data[1],'\n');
	while (cin.fail()) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "������! ������� ��� ��������: ";
		getline(cin, data[1], '\n');
	}
	cout << "������� ��� ��������: ";
	cin >> b;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "������!������� ��� �������� �������� : ";
		cin >> b;
	}
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "������� �����: ";
	getline(cin, data[2], '\n');
	while (cin.fail()) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "������! ������� ����� ��������: ";
		getline(cin, data[2], '\n');
	}
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "������� ����� ������(�����): ";
	getline(cin, data[3], '\n');
	while (cin.fail()) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "������! ������� ����� ������(�����) ��������: ";
		getline(cin, data[3], '\n');
	}

}

void Hash_table::in_data(string&data, int flag) {//�����
	setlocale(LC_ALL, "rus");
	cout << "������� ������ ��� ������ ��������: " << endl;
	if (flag == 1) {
		cout << "������� ��������������� �����: ";
		cin >> data;
		while (cin.fail() || (data[2] != '-') || (data[9] != '\0')) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "��������������� ����� � ������ ������� �MM-NNNNNN�" << endl;
			cout << "������� ����� ��������: ";
			cin >> data[0];
		}
	}
	else {
		cout << "������� ���: ";
		getline(cin, data, '\n');
		while (cin.fail()) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "������! ������� ��� ��������: ";
			getline(cin, data, '\n');
		}
	}
}

void Hash_table::add() {
	setlocale(LC_ALL, "rus");
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

int Hash_table::search(int notdel) {
	setlocale(LC_ALL, "rus");
	Patient found;
	string data;
	int flag = 1;
	int menu;
	int adr = -1;
	if(notdel == 1) {
		cout << "�������� ����� ������: " << endl;
		cout << "1. �� ������ �����������" << endl;
		cout << "2. �� �������" << endl;
		cout << "��� �����: ";
		cin >> menu; 
	}
	else {
		menu = 1;
	}
	while (flag) {
		switch (menu) {
		case 1: {
			//����� �� ��� ������
			in_data(data, 1);
			adr = hasher(data);
			if (table[adr].getstatus()==1) {
				found = table[adr];
			}
			else {
				adr = collision(adr, data);
				found = table[adr];
				if (adr == -10) {
					found.set_st(4);
				}
			}
			if ((adr != -10)) {
				cout << "�� ������ ������� ���� ����������: " << endl;
				cout << "� " << found.getnumber() << endl;
				cout << "���: " << found.getfio() << endl;
				cout << "��� ��������: " << found.getbirth() << endl;
				cout << "�����: " << found.getadr() << endl;
				cout << "����� ������(�����): " << found.getwp() << endl;
				//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!�������� ������ � ������� �������
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
	return adr;
}

int Hash_table::hasher(string number) {
	int a = number[0]+number[1]+number[3]+number[4]+number[5]+number[6] +number[7] + number[8];
	int k = 0;
	a = a * a;
	int b = a;
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
	setlocale(LC_ALL, "rus");
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
	setlocale(LC_ALL, "rus");
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

void Hash_table::del() {
	setlocale(LC_ALL, "rus");
	Patient* del;
	int adr;
	adr=search(0);
	if (table[adr].getstatus() != 4) {
		int menu;
		cout << "�� �������, ��� ������ ������� ���������� ��������?" << endl;
		cout << "1- ��. 2- ���. ��� �����: ";
		cin >> menu;
		if (menu == 1) {
			table[adr].set_st(2);
			cout << "�������� ��������� �������!"<<endl;
		}
	}
}

void  Hash_table::show_all() {
	setlocale(LC_ALL, "rus");
	cout << "������ ��������� ���������: " << endl;
	int k = 0;
	for (int i = 0; i < N; i++) {
		if (table[i].getstatus() == 1) {
			cout << table[i].getnumber() << " " << table[i].getfio() << endl;
			k++;
		}
	}
	if (k == 0) {
		cout << "�������� �� �������!" << endl;
	}
}