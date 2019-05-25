#include "Tree.h"
#include<iostream>
#include<string>
#include <algorithm>


Tree::Tree()
{
	root = nullptr;
}


Tree::~Tree()
{
	//del_all_tree();
}

void Tree::add_tree(tree* prev, string el[])
{
	setlocale(LC_ALL, "rus");
	if (root != nullptr) {
		tree* temp;
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
	}
	cout << "Информация о враче успешно добавлена! " << endl;
}

void Tree::add_list(tree* el)
{
	if (head != nullptr) {
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
	//tmp - предок добавляемого и удаленного
	tree* temp = el;
	int flag = 0;
	int l_h, r_h;//высота левого и правого поддеревьев основного
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
					//лбв
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
								cout << "Ошибка распада!" << endl;
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
					//лмв
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
								cout << "Ошибка распада!" << endl;
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
					//пбв
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
								cout << "Ошибка распада!" << endl;
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
					//пмв
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
								cout << "Ошибка распада!" << endl;
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
						cout << "Вы меня сломали :(" << endl;
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
					add_list(NULL);//интересно зачем
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

						cout << "Ошибка распада!" << endl;
					}
				}
			}
			ret = del->prev;
		}
		else {
			if (del->right != NULL) {
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
							cout << "Ошибка распада!" << endl;
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
				del->right->prev = leftest;
				ret = leftest;
			}
			else {
				if (del->left != NULL) {
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
							cout << "Ошибка распада!" << endl;
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
		cout << "Дерево не задано!" << endl;

	}
	return ret;
}

Tree::tree* Tree::searcher(int flag, string in) {
	setlocale(LC_ALL, "rus");
	//flag==0 - обычный поиск, ==1 - с добавлением, 2 - по должности
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
								cout << "Такой элемент уже существует в дереве" << endl;
								temp = NULL;
								flag_end = 1;
							}
						}
						else {
							cout << "Вы меня сломали :(" << endl;
							flag_end = 1;
						}
					}
				}
			}
			else {
				if (prev != NULL) {
					if (flag == 0) {
						cout << "Элемент не найден!" << endl;
						temp = NULL;
						flag_end = 1;
					}
					else {
						temp = prev;
						flag_end = 1;
					}
				}
				else {
					cout << "Дерево не задано!" << endl;
					temp = NULL;
					flag_end = 1;
				}
			}
		}
	}
	else {
		temp = NULL;
		cout << "Дерево не задано!" << endl;
	}
	return temp;
}

string* Tree::in_data(int){
	string *f= NULL;
	return f;
}
void Tree::show_one(tree*){}

void Tree::search() {
	setlocale(LC_ALL, "rus");
	int menu = 0;
	string* s;
	cout << "Введите вид поиска:" << endl;
	cout << "1. По фамилии врача" << endl;
	cout << "2. По должности" << endl;
	cout << "Ваш выбор";
	cin >> menu;
	switch (menu) {
	case 1: {
		s = in_data(1);
		string ser = s[0];
		tree* temp = searcher(0,ser);
		show_one(temp);
		break;
	}
	case 2: {
		s = in_data(1);
		string ser = s[0];
		tree* temp = searcher(2, ser);
		show_one(temp);
		break;
	}
	}
}