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
	void del_list();
	list* sons_finder(int flag);
	void high_changer( tree* temp);
	int get_height(tree*el);
	void in_data(string&, int);//����= 1-���, 2 - ���������
	void in_data(string*&, int&);//add
	void show_one(tree*);

public:
	Tree();
	~Tree();
	void add();
	void search();
	void del();
	void show_all();
	void del_all_tree();
};

