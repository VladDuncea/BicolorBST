#pragma once
#include "Tree.h"
#include "Node.h"

class BST :public Tree
{
	Node * privRoot;

	void priv_insert(Node *n, int data);
	void privEmpty(Node *n);
	int privDepth(Node *n, int depth);
	void privRemoveNode(Node *n, int x);

public:
	BST();
	BST(Node *root);
	BST(BST& bst);
	~BST();

	//Tree functions
	int treeDepth();
	void inorder() const;
	void insert(int data);
	void removeNode(int x);

	BST & operator=(BST& bst);
};

