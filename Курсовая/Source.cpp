#include <iostream>
#include<locale>
#include "string.h"
#include "stdio.h"
#include <cctype>
#include "CircleList.h"
#include "Tree.h"
#include "Hash_table.h"
#include "Windows.h"

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

void podmenu(int flag, CircleList &dirs, Hash_table &hash, Tree &doctors) {
	int menu = 0;
	if (flag != 0) {
		cout << endl << "Выберете дальнейшее действие:" << endl;
		cout << "1. Pегистрация нового "; if(flag==1){ cout << "пациента" << endl; }else{ cout << "врача" << endl; }
		cout << "2. Поиск "; if (flag == 1) { cout << "пациента" << endl; }else { cout << "врача" << endl; }
		cout << "3. Просмотр всех "; if (flag == 1) { cout << "пациентов" << endl; }else { cout << "врачей" << endl; }
		cout << "4. Удаление "; if (flag == 1) { cout << "пациента" << endl; }else { cout << "врача" << endl; }
		cout << "5. Удаление всех "; if (flag == 1) { cout << "пациентов" << endl; }else { cout << "врачей" << endl; }
		cout << "Ваш выбор: ";
		cin >> menu;
		menu = check_menu(menu, 5);
		switch (menu) {
		case 1: {
			if (flag == 1) {
				hash.add();
				break;
			}
			else {
				doctors.add();
				break;
			}
		}
		case 2: {
			if (flag == 1) {
				hash.search(dirs);
			}
			else {
				doctors.search(dirs);
				break;
			}
			break;
		}
		case 3: {
			if (flag == 1) {
				hash.show_all();
			}
			else {
				doctors.show_all();
				break;
			}
			break;
		}
		case 4: {
			if (flag == 1) {
				hash.del(dirs);
			}
			else {
				doctors.del();
				break;
			}
			break;
		}
		case 5: {
			if (flag == 1) {
				hash.del_all();
			}
			else {
				doctors.del_all();
				break;
			}
			break;
		}
		}
	}
	else {

	}
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int menu = 0;
	bool flag_break = 0;
	Tree tree;
	CircleList dirs;//направления
	Hash_table hashtable;
	Tree docs;
	while (true) {
		cout <<  "Выберите категорию:" << endl;
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
			int p_menu = 0;
			string fio;
			string number;
			string data[4];
			cout << "Выберите дальнейшее действие: " << endl;
			cout << "1. Новое направление" << endl;
			cout << "2. Возврат направления" << endl;
			cout << "Ваш выбор: ";
			cin >> p_menu;
			p_menu = check_menu(p_menu, 2);
			if (p_menu == 1) {
				fio = docs.search(dirs,1);
				if (fio != "") {
					number = hashtable.search_list();
					if (number != "") {
						data[0] = number;
						data[1] = fio;
						cout << "Введите дату приема: " << endl;
						cin >> data[2];
						cout << "Введите время приема: " << endl;
						cin >> data[3];
						dirs.add(data);
					}
				}
			}
			else {
				string doc = "";
				string pat = "";
				cout << "Введите фамилию врача: " << endl;
				cin >> doc;
				cout << "Введите регистрационный номер пациента: " << endl;
				cin >> pat;
				dirs.del(pat, doc);
				cout << "Удаление произошло успешно!" << endl;
			}
			break;
		}
		case 2: {
			podmenu(1, dirs, hashtable,docs);
			break;
		}
		case 3: {
			podmenu(2, dirs, hashtable, docs);
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