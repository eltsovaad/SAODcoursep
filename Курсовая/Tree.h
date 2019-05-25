#pragma once
#include<string>
using namespace std;
class Tree
{
private:
	struct tree
	{
		string el[4];
		int height;
		tree* prev;
		tree* left;
		tree* right;
	};

	struct list
	{
		tree* leaf;
		list* next;
	};
	
	tree* root;
	list* head;

	void add_tree(tree*, string[]);
	void add_list(tree*);
	tree *searcher(int flag, string in);
	void balance(tree* el);
	tree* del_tree(tree* del);
	void del_all_tree();
	void del_list(list* head);
	list* sons_finder(int flag);
	void high_changer( tree* temp);
	int get_height(tree*el);
	string* in_data(int);//флаг=0 при всех полях, 1-фио, 2 - должность
	void show_one(tree*);
public:
	Tree();
	~Tree();
	void add();
	void search();

};

