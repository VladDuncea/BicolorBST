#pragma once
#include "NodeRedBlack.h"
#include "Tree.h"

class BicolorBST: public Tree
{
	NodeRedBlack *privRoot;
	void privInsert(NodeRedBlack *n, int data);
	void privCheckRules(NodeRedBlack *n);
	void privCaseOne(NodeRedBlack *base, NodeRedBlack *left, NodeRedBlack *right);
	NodeRedBlack * privCaseTwo(NodeRedBlack *base, NodeRedBlack *left, NodeRedBlack *right,bool reversed);
	NodeRedBlack * privCaseThree(NodeRedBlack *base, NodeRedBlack *left, NodeRedBlack *right,bool reversed);
	void privEmpty(NodeRedBlack *n);
protected:
	void protecPrintSRD(Node *n, std::ostream& os) const;
public:
	BicolorBST();
	BicolorBST(NodeRedBlack *root);
	~BicolorBST();

	//Tree functions
	void inorder() const;
	void insert(int data);
	void removeNode(int) {};
};

