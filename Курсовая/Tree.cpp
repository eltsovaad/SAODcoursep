#include "Tree.h"
#include<iostream>
#include<string>
#include <algorithm>
#include"CircleList.h"


Tree::Tree()
{
	root = NULL;
}


Tree::~Tree()
{
	del_all();
}

void Tree::add() {
	string data[4];
	string* p_data = &data[0];
	in_data(p_data);
	tree* prev = NULL;
	tree* temp = NULL;
	if (root != NULL) {
		
		prev = searcher(1, p_data[0]);
		if (prev != NULL) {
			temp=add_tree(prev, data);
			high_changer(temp);
			balance(temp);
		}
	}
	else {
		temp=add_tree(prev, data);
		high_changer(temp);
		balance(temp);
	}
	
}

void Tree::in_data(string*& data) {
	setlocale(LC_ALL, "rus");
	locale loc("Russian_Russia.1251");
	cout << "������� ������ ��� ���������� �����: " << endl;
	cout << "������� ���: ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin,data[0], '\n');
	while ((cin.fail() )|| (data[0].length()>=25)) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "��� �� ������ ��������� 25 ��������!" << endl;
		cout << "������� ��� ��������: ";
		getline(cin, data[0], '\n');
	}
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "������� ���������: ";
	getline(cin, data[1], '\n');
	while (cin.fail()||(data[0].length() >= 25)) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "��������� �� ������ ��������� 25 ��������! ������� ��������: ";
		getline(cin, data[1], '\n');
	}
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "������� ����� ��������: ";
	getline(cin, data[2], '\n');
	while (cin.fail()) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "������!������� ����� �������� �������� : ";
		getline(cin, data[2], '\n');
	}
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "������� ������ ������: ";
	getline(cin, data[3], '\n');
	while (cin.fail()) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "������! ������� ������ ������ ��������: ";
		getline(cin, data[3], '\n');
	}
}

void Tree::search_in_text(string sear) {
	head = sons_finder(0);
	list* tmp = head;
	int flag = 0;
	while (tmp != NULL) {
		/*for (int i = 0; i < tmp->leaf->el[1].length(); i++) {
			for (int j = 0; (i + j) < min(sear.length(), tmp->leaf->el[1].length()); j++) {
				if (tmp->leaf->el[1][j + i] == sear[j]) {
					flag++;
				}
			}
			if (flag == sear.length()) {
				flag = 1;
				break;
			}
			else {
				flag = 0;
			}
		}
		if (flag == 1) {
			cout<<tmp->leaf->el[0] << " - " << tmp->leaf->el[1] << endl;
			flag = 0;
		}
		tmp = tmp->next;*/
		int b = 0;
		for (int i = 0; i < tmp->leaf->el[1].length(); i++) {
			for (int j = 0; j < sear.length(); j++) {
				if (tmp->leaf->el[1][i] == sear[j]) {
					flag++;
					if (b == 0) {
						b = i;
					}
					i++;
				}
				else {
					flag = 0;
					break;
				}
			}
			if (flag == sear.length()) {
				i = b;
				b = 0;
				flag = 1;
				break;
			}
			else {
				flag = 0;
			}
		}
		if (flag == 1) {
			cout << tmp->leaf->el[0] << " - " << tmp->leaf->el[1] << endl;
			flag = 0;
		}
		tmp = tmp->next;
	}

	del_list();
}

void Tree::in_data(string& data, int flag) {
	setlocale(LC_ALL, "rus");
	cout << "������� ������ ��� ������ �����: " << endl;
	if (flag == 1) {
		cout << "������� ���: ";
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, data, '\n');
		while ((cin.fail()) || (data.length() >= 25)) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "��� �� ������ ��������� 25 ��������!" << endl;
			cout << "������� ��� ��������: ";
			getline(cin, data, '\n');
		}
	}
	else {
		cout << "������� ���������: ";
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, data, '\n');
		while (cin.fail()) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "������! ������� ��������� ��������: ";
			getline(cin, data, '\n');
		}
	}
}

void Tree::show_one(tree* temp) {
	cout << "�� ������ ������� ���� ����������: " << endl;
	cout << "���: " << temp->el[0] << endl;
	cout << "���������: " << temp->el[1] << endl;
	cout << "������� �����: " << temp->el[2] << endl;
	cout << "������ ������: " << temp->el[3] << endl;
}

string Tree::search(CircleList dirs, int flag) {
	if (root != NULL) {
		setlocale(LC_ALL, "rus");
		int menu = 0;
		string s;
		if (flag == 0) {
			cout << "������� ��� ������:" << endl;
			cout << "1. �� ������� �����" << endl;
			cout << "2. �� ���������" << endl;
			cout << "��� �����: ";
			cin >> menu;
		}
		else {
			menu = 1;
		}
		switch (menu) {
		case 1: {
			in_data(s, 1);
			tree* temp = searcher(0, s);
			if (flag == 0) {
				show_one(temp);
				dirs.view_pat(temp->el[0]);
			}
			else {
				return temp->el[0];
			}
			break;
		}
		case 2: {
			in_data(s, 2);
			search_in_text(s);
			break;
		}
		}
	}
	else {
		cout << "��� ����������� ������!" << endl;
	}
	return "";
}

void Tree:: del() {
	if (root) {
		string a;
		cout << "������� ������� ��� ��������: "<<endl;
		in_data(a,1);
		tree* temp = searcher(0, a);
		if (temp != NULL) {
			temp = del_tree(temp);
			balance(temp);
			cout << "�������� ��������� �������!" << endl;
		}
	}
	else {
		cout << "������ �� ������!" << endl;
	}
}

void Tree:: del_all() {
	if (root) {
		list* head, *temp, *header;
		head = sons_finder(0);
		header = head;
		if (head != NULL) {
			temp = head;
			while (temp->next != NULL) {
				temp = head->next;
				delete (head->leaf);
				head->leaf = NULL;
				head = temp;
			}
			delete (head->leaf);
			head->leaf = NULL;
		}
		del_list();
		root = NULL;
	}
	else {
		cout << "��� ����������� ������!" << endl;
	}
}

void Tree:: del_list() {
	struct list *temp;
	if (head != NULL) {
		temp = head;
		while (temp->next != NULL) {
			temp = head->next;
			delete (head);
			head = temp;
		}
		delete (head);
		head = NULL;
	}
}

void Tree::show_all() {
	if (root) {
		head = sons_finder(0);
		list* tmp = head;
		cout << "��� ������������������ �����:" << endl;
		int a = 1;
		while (tmp != NULL) {
			cout << a << ". " << tmp->leaf->el[0] << " - " << tmp->leaf->el[1] << endl;
			a++;
			tmp = tmp->next;
		}
		del_list();
	}
	else {
		cout << "��� ������!" << endl;
	}
}

Tree::tree* Tree::del_tree(tree* del) {
	setlocale(LC_ALL, "rus");
	tree* ret = NULL;
	if (root != NULL) {
		if ((del->left == NULL) && (del->right == NULL)) {
			if (del->prev != NULL) {
				if (del->prev->left == del) {
					del->prev->left = NULL;
				}
				else {
					if (del->prev->right == del) {
						del->prev->right = NULL;
					}
					else {

						cout << "������ �������!" << endl;
					}
				}
			}
			ret = del->prev;
		}
		else {
			if (del->right != nullptr){
				tree* leftest = del->right;
				while (leftest->left) {
					leftest = leftest->left;
				}
				if (leftest->right) {
					tree* leftest_r_son = leftest->right;
					leftest->prev->left = leftest_r_son;
					leftest_r_son->prev = leftest->prev;
					//leftest_r_son->right = NULL;
				}
				if (del->prev) {
					if (del->prev->left == del) {
						del->prev->left = leftest;
					}
					else {
						if (del->prev->right == del) {
							del->prev->right = leftest;
						}
						else {
							cout << "������ �������!" << endl;
						}
					}
				}
					if (leftest->prev->left == leftest) {
						leftest->prev->left = NULL;
					}
					else {

						leftest->prev->right = NULL;
					}
				leftest->prev = del->prev;
				leftest->left = del->left;
				del->left->prev = leftest;
				leftest->right = del->right;
				//if (leftest != del) {
					del->right->prev = leftest;
				//}
				ret = leftest;
			}
			else {
				if ((del->left != NULL)||(del->left != nullptr)) {
					tree* rightest = del->left;
					while (rightest->right) {
						rightest = rightest->left;
					}
					if (rightest->left) {
						tree* rightest_l_son = rightest->left;
						rightest->prev->right = rightest_l_son;
						rightest_l_son->prev = rightest->prev;
					}
					if (del->prev->left == del) {
						del->prev->left = rightest;
					}
					else {
						if (del->prev->right == del) {
							del->prev->right = rightest;
						}
						else {
							cout << "������ �������!" << endl;
						}
					}
					if (rightest->prev->left == rightest) {
						rightest->prev->left = NULL;
					}
					else {
						rightest->prev->right = NULL;
					}
					rightest->prev = del->prev;
					rightest->left = del->left;
					del->right->prev = rightest;
					rightest->right = del->right;
					del->right->prev = rightest;
					ret = rightest;
				}
			}
		}
		if (del == root) {
			root = ret;
			high_changer(root);
		}
		delete del;
		del = NULL;
	}
	else {
		cout << "������ �� ������!" << endl;

	}
	return ret;
}



Tree::tree* Tree::add_tree(tree* prev, string el[])
{
	tree* temp;
	setlocale(LC_ALL, "rus");
	if (root != NULL) {
		temp = new struct tree;
		temp->prev = prev;
		temp->left = NULL;
		temp->right = NULL;
		temp->height = 1;
		for (int i = 0; i < 4; i++) {
			temp->el[i] = el[i];
		}
		if (el[0] > prev->el[0]) {
			prev->right = temp;
		}
		else {
			prev->left = temp;
		}
	}
	else {
		root = new struct tree;
		root->prev = NULL;
		root->left = NULL;
		root->right = NULL;
		root->height = 1;
		for (int i = 0; i < 4; i++) {
			root->el[i] = el[i];
		}
		temp = root;
	}
	cout << "���������� � ����� ������� ���������! " << endl;
	return temp;
}

void Tree::add_list(tree* el)
{
	if (head != NULL) {
		struct list *temp;
		temp = new struct list;
		list* last = head;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = temp;
		temp->next = NULL;
		temp->leaf = el;
	}
	else {
		head = new struct list;
		head->next = NULL;
		head->leaf = el;
	}
}

void Tree::balance(tree* el) {
	setlocale(LC_ALL, "rus");
	//tmp - ������ ������������ � ����������
	tree* temp = el;
	int flag = 0;
	int l_h, r_h;//������ ������ � ������� ����������� ���������
	while (temp != NULL) {
		if (temp == root) {
			flag = 1;
		}
		l_h = get_height(temp->left);
		r_h = get_height(temp->right);
		if (abs(l_h - r_h) >= 2) {
			int sons_l, sons_r;
			tree* temp_son;
			if (l_h > r_h) {
				temp_son = temp->left;
				sons_l = get_height(temp_son->left);
				sons_r = get_height(temp_son->right);
				if (sons_r > sons_l) {
					//���
					tree* a, *b, *c, *M, *N, *R, *L;
					a = temp;
					b = temp_son;
					c = temp_son->right;
					R = temp->right;
					L = temp_son->left;
					M = temp_son->right->left;
					N = temp_son->right->right;
					if (a->prev != NULL) {
						if (a->prev->left == a) {
							a->prev->left = c;
						}
						else {
							if (a->prev->right == a) {
								a->prev->right = c;
							}
							else {
								cout << "������ �������!" << endl;
							}
						}
					}
					c->prev = a->prev;
					if (N != NULL) {
						N->prev = a;
					}
					a->left = N;
					if (M != NULL) {
						M->prev = b;
					}
					b->right = M;
					b->prev = c;
					a->prev = c;
					c->left = b;
					c->right = a;
					if (flag == 1) {
						root = c;
					}
					high_changer(L);
					high_changer(M);
					high_changer(N);
					high_changer(R);
					high_changer( b);
					high_changer(a);
					high_changer(c);
				}
				else {
					//���
					tree* a, *b, *C, *R, *L;
					a = temp;
					b = temp_son;
					R = temp->right;
					L = temp_son->left;
					C = temp_son->right;
					if (a->prev != NULL) {
						if (a->prev->left == a) {
							a->prev->left = b;
						}
						else {
							if (a->prev->right == a) {
								a->prev->right = b;
							}
							else {
								cout << "������ �������!" << endl;
							}
						}
					}
					b->prev = a->prev;
					if (C != NULL) {
						C->prev = a;
					}
					a->left = C;
					a->prev = b;
					b->right = a;
					if (flag == 1) {
						root = b;
					}
					high_changer(C);
					high_changer(R);
					high_changer(L);
					high_changer(a);
					high_changer(b);
				}
			}
			else {
				temp_son = temp->right;
				sons_l = get_height(temp_son->left);
				sons_r = get_height(temp_son->right);
				if (sons_r < sons_l) {
					//���
					tree* a, *b, *c, *M, *N, *R, *L;
					a = temp;
					b = temp_son;
					c = temp_son->left;
					R = temp_son->right;
					L = temp->left;
					M = c->left;
					N = c->right;
					if (a->prev != NULL) {
						if (a->prev->left == a) {
							a->prev->left = c;
						}
						else {
							if (a->prev->right == a) {
								a->prev->right = c;
							}
							else {
								cout << "������ �������!" << endl;
							}
						}
					}
					c->prev = a->prev;
					if (M != NULL) {
						M->prev = a;
					}
					a->right = M;
					if (N != NULL) {
						N->prev = b;
					}
					b->left = N;
					b->prev = c;
					a->prev = c;
					c->left = a;
					c->right = b;
					if (flag == 1) {
						root = c;
					}
					high_changer( L);
					high_changer( M);
					high_changer(N);
					high_changer(R);
					high_changer( b);
					high_changer( a);
					high_changer(c);
				}
				else {
					//���
					tree* a, *b, *C, *R, *L;
					a = temp;
					b = temp_son;
					R = temp_son->right;
					L = temp->left;
					C = temp_son->left;
					if (a->prev != NULL) {
						if (a->prev->left == a) {
							a->prev->left = b;
						}
						else {
							if (a->prev->right == a) {
								a->prev->right = b;
							}
							else {
								cout << "������ �������!" << endl;
							}
						}
					}
					b->prev = a->prev;
					if (C != NULL) {
						C->prev = a;
					}
					a->right = C;
					a->prev = b;
					b->left = a;
					if (flag == 1) {
						root = b;
					}
					high_changer(L);
					high_changer(C);
					high_changer(R);
					high_changer(a);
					high_changer(b);
				}
			}
		}

		temp = temp->prev;
	}
}

int Tree::get_height(tree*el) {
	int h = 0;
	if (el == NULL) {
		h = 0;
	}
	else {
		h = el->height;
	}
	return h;
}

void Tree:: high_changer(tree* temp) {
	while (temp != NULL) {
		if ((temp->left != NULL) && (temp->right != NULL)) {
			temp->height = max(temp->left->height, temp->right->height) + 1;
		}
		else {
			if ((temp->left == NULL) && (temp->right == NULL)) {
				temp->height = 1;
			}
			else {
				if (temp->left == NULL) {
					temp->height = (temp->right->height) + 1;
				}
				else {
					if (temp->right == NULL) {
						temp->height = (temp->left->height) + 1;
					}
					else {
						setlocale(LC_ALL, "rus");
						cout << "�� ���� ������� :(" << endl;
					}
				}
			}
		}
		temp = temp->prev;
	}
}

Tree::list* Tree::sons_finder(int flag) {
	list* temp, *last;
	add_list(root);
	temp = last = head;
	while (temp != NULL) {
		if (temp->leaf) {
			if (flag == 0) {
				if (temp->leaf->left != NULL) {
					add_list(temp->leaf->left);
				}
				if (temp->leaf->right != NULL) {
					add_list(temp->leaf->right);
				}
			}
			else {
				if (temp->leaf->left != NULL) {
					add_list(temp->leaf->left);
				}
				else {
					add_list(NULL);//��������� �����
				}
				if (temp->leaf->right != NULL) {
					add_list(temp->leaf->right);
				}
				else {
					add_list(NULL);
				}
			}
		}
		temp = temp->next;
	}
	return head;
}



Tree::tree* Tree::searcher(int flag, string in) {
	setlocale(LC_ALL, "rus");
	//flag==0 - ������� �����, ==1 - � �����������
	tree* temp, *prev;
	if (root != NULL) {
		int k = 0;
		temp = root;
		prev = NULL;
		int flag_end = 0;
		while (flag_end == 0) {
			if (temp != NULL) {
				if (in > temp->el[0]) {
					prev = temp;
					temp = temp->right;
					k++;
				}
				else {
					if (in < temp->el[0]) {
						prev = temp;
						temp = temp->left;
						k++;
					}
					else {
						if (in == temp->el[0]) {
							k++;
							if (flag == 0) {
								flag_end = 1;
							}
							else {
								cout << "����� ������� ��� ���������� � ������" << endl;
								temp = NULL;
								flag_end = 1;
							}
						}
						else {
							cout << "�� ���� ������� :(" << endl;
							flag_end = 1;
						}
					}
				}
			}
			else {
				if (prev != NULL) {
					if (flag == 0) {
						cout << "������� �� ������!" << endl;
						temp = NULL;
						flag_end = 1;
					}
					else {
						temp = prev;
						flag_end = 1;
					}
				}
				else {
					cout << "������ �� ������!" << endl;
					temp = NULL;
					flag_end = 1;
				}
			}
		}
	}
	else {
		temp = NULL;
		if (flag != 1) {
			cout << "������ �� ������!" << endl;
		}
	}
	return temp;
}

