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

void Hash_table::in_data(string*&data, int &b) {//добавление
	setlocale(LC_ALL, "rus");
	cout << "Введите данные для добавления пациента: " << endl;
	cout << "Введите регистрационный номер: ";
	cin >> data[0];
	while (cin.fail()||(data[0][2]!='-')|| (data[0][9] != '\0')) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Регистрационный номер – строка формата «MM-NNNNNN»" << endl;
		cout << "Введите номер повторно: ";
		cin >> data[0];
	}
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "Введите ФИО: ";
	getline(cin,data[1],'\n');
	while (cin.fail()) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Ошибка! Введите ФИО повторно: ";
		getline(cin, data[1], '\n');
	}
	cout << "Введите год рождения: ";
	cin >> b;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Ошибка!Введите год рождения повторно : ";
		cin >> b;
	}
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "Введите адрес: ";
	getline(cin, data[2], '\n');
	while (cin.fail()) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Ошибка! Введите адрес повторно: ";
		getline(cin, data[2], '\n');
	}
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "Введите место работы(учебы): ";
	getline(cin, data[3], '\n');
	while (cin.fail()) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Ошибка! Введите место работы(учебы) повторно: ";
		getline(cin, data[3], '\n');
	}

}

void Hash_table::in_data(string&data, int flag) {//поиск
	setlocale(LC_ALL, "rus");
	cout << "Введите данные для поиска пациента: " << endl;
	if (flag == 1) {
		cout << "Введите регистрационный номер: ";
		cin >> data;
		while (cin.fail() || (data[2] != '-') || (data[9] != '\0')) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Регистрационный номер – строка формата «MM-NNNNNN»" << endl;
			cout << "Введите номер повторно: ";
			cin >> data[0];
		}
	}
	else {
		cout << "Введите ФИО: ";
		getline(cin, data, '\n');
		while (cin.fail()) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Ошибка! Введите ФИО повторно: ";
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
		cout << "Пациент успешно добавлен! " << endl;
		cout << endl;
	}
	else {
		adr = collision(adr);
		if (adr != -10) {
			table[adr] = temp;
			cout << "Пациент успешно добавлен! " << endl;
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
		cout << "Выберите метод поиска: " << endl;
		cout << "1. По номеру регистрации" << endl;
		cout << "2. По фамилии" << endl;
		cout << "Ваш выбор: ";
		cin >> menu; 
	}
	else {
		menu = 1;
	}
	while (flag) {
		switch (menu) {
		case 1: {
			//поиск по рег номеру
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
				cout << "По вашему запросу было обнаружено: " << endl;
				cout << "№ " << found.getnumber() << endl;
				cout << "ФИО: " << found.getfio() << endl;
				cout << "Год рождения: " << found.getbirth() << endl;
				cout << "Адрес: " << found.getadr() << endl;
				cout << "Место работы(учебы): " << found.getwp() << endl;
				//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!добавить врачей к которым записан
			}
			flag = 0;
			break;
		}
		case 2: {
			//поиск по фио
			int flag_found = 0;//флаг того, что были найдены фио
			cout << "Список найденных пациентов: " << endl;
			in_data(data, 2);
			for (int i = 0; i < N; i++) {
				if (data == table[i].getfio()) {
					flag_found++;
					string num = table[i].getnumber();
					cout << num << " " << data << endl;
				}	
			}
			if (flag_found == 0) {
				cout << "По вашему запросу не было найдено пациентов" << endl;
			}
			flag = 0;
			break;
		}
		default: {
			cin.clear();
			cin.ignore();
			cout << "Неверный ввод пункта меню! Повторите: ";
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
	//поиск
	int step = 1;
	while (true) {
		if (step > N) {
			cout << "Пациент не найден!" << endl;
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
	//добавление
	int step = 1;
	while (true) {
		if (step > N) {
			cout << "Переполнение таблицы!" << endl;
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
		cout << "Вы уверены, что хотите удалить выбранного пациента?" << endl;
		cout << "1- Да. 2- Нет. Ваш выбор: ";
		cin >> menu;
		if (menu == 1) {
			table[adr].set_st(2);
			cout << "Удаление произошло успешно!"<<endl;
		}
	}
}

void  Hash_table::show_all() {
	setlocale(LC_ALL, "rus");
	cout << "Список найденных пациентов: " << endl;
	int k = 0;
	for (int i = 0; i < N; i++) {
		if (table[i].getstatus() == 1) {
			cout << table[i].getnumber() << " " << table[i].getfio() << endl;
			k++;
		}
	}
	if (k == 0) {
		cout << "Пациенты не найдены!" << endl;
	}
}