#include <iostream>
#include<locale>
#include "string.h"
#include "stdio.h"
#include <cctype>
#include "CircleList.h"
#include "Tree.h"
#include "Hash_table.h"

using namespace std;

int check_menu(int menu, int num) {
	int flag = 1;
	for (int i = 1; i <= num; i++) {
		if (menu == i) {
			flag = 0;
			break;
		}
	}

	while (cin.fail() || (flag == 1)) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Неверный ввод. Повторите: ";
		cin >> menu;
		for (int i = 1; i <= num; i++) {
			if (menu == i) {
				flag = 0;
				break;
			}
		}
	}
	return menu;
}

string* in_data(int);

void podmenu(int flag, Tree doctors, CircleList dirs, Hash_table hash) {
	int menu = 0;
	if (flag != 0) {
		cout << endl << "Выберете дальнейшее действие:" << endl;
		cout << "1. Pегистрация нового "; if(flag==1){ cout << "пациента" << endl; }else{ cout << "врача" << endl; }
		cout << "2. Поиск "; if (flag == 1) { cout << "пациента" << endl; }else { cout << "врача" << endl; }
		cout << "3. Просмотр всех"; if (flag == 1) { cout << "пациентов" << endl; }else { cout << "врачей" << endl; }
		cout << "4. Удаление"; if (flag == 1) { cout << "пациента" << endl; }else { cout << "врача" << endl; }
		cout << "Ваш выбор: ";
		cin >> menu;
		menu = check_menu(menu, 4);
		switch (menu) {
		case 1: {
			if (flag == 1) {
				string* a;
				a=in_data(1);
				hash.add();
			}
			else {
				doctors.add();
				break;
			}
		}
		case 2: {

			break;
		}
		case 3: {
			break;
		}
		case 4: {
			break;
		}
		}
	}
	else {

	}
}

int main() {
	setlocale(LC_ALL, "rus");
	int menu = 0;
	bool flag_break = 0;
	Tree tree();
	CircleList dirs();//направления
	CircleList patients();//пациенты
	Hash_table hashtable();
	while (true) {
		cout << endl << "Выберите категорию:" << endl;
		cout << "1. Направления" << endl;
		cout << "2. Пациенты" << endl;
		cout << "3. Врачи" << endl;
		cout << "4. Выход" << endl;
		cout << "Ваш выбор: ";
		cin >> menu;
		menu = check_menu(menu, 4);
		system("cls");

		switch (menu) {
		case 1: {

			break;
		}
		case 2: {

			break;
		}
		case 3: {

			break;
		}
		case 4: {
			cout << "Завершение работы..." << endl;
			flag_break = 1;
			break;
		}
		}
		if (flag_break == 1) {
			break;
		}
	}

	system("pause");
	return 0;
}