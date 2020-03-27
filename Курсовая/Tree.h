#pragma once
#include<string>
#include"CircleList.h"
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

	tree* add_tree(tree*, string[]);
	void add_list(tree*);
	tree *searcher(int flag, string in);
	void balance(tree* el);
	tree* del_tree(tree* del);
	void del_list();
	list* sons_finder(int flag);
	void high_changer( tree* temp);
	int get_height(tree*el);
	void in_data(string&, int);//флаг= 1-фио, 2 - должность
	void in_data(string*&);//add
	void show_one(tree*);
	void search_in_text(string);

public:
	Tree();
	~Tree();
	void add();
	string search(CircleList&,int=0);
	void del();
	void show_all();
	void del_all();
};

