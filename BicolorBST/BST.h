#pragma once
#include "Tree.h"
#include "Node.h"

class BST :private Tree
{
	Node * privRoot;

	void priv_printSRD(const Node *n, std::ostream &os) const;
	void priv_insert(Node *n, int data);
public:
	BST();
	BST(Node *root);
	~BST();

	//Tree functions
	void inorder() const;
	void insert(int data);
	void removeNode(int) {};
	int nrNodes();

};

