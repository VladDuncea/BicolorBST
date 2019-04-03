#pragma once
#include "NodeRedBlack.h"
#include "Tree.h"

class BicolorBST: public Tree
{
	NodeRedBlack *privRoot;
	void priv_printSRD(const NodeRedBlack *n, std::ostream &os) const;
	void privInsert(NodeRedBlack *n, int data);
	void privCheckRules(NodeRedBlack *n);
	void privCaseOne(NodeRedBlack *base, NodeRedBlack *left, NodeRedBlack *right);
	void privCaseTwo(NodeRedBlack *base, NodeRedBlack *left, NodeRedBlack *right,bool reversed);
	void privEmpty(Node *n);

public:
	BicolorBST();
	BicolorBST(NodeRedBlack *root);
	~BicolorBST();

	//Tree functions
	void inorder() const;
	void insert(int data);
	void removeNode(int) {};
};

