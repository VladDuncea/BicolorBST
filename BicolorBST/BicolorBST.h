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
	int privDepth(NodeRedBlack *n, int blackNr);

protected:
	void protecPrintSRD(Node *n, std::ostream& os) const;
public:
	BicolorBST();
	BicolorBST(NodeRedBlack *root);
	~BicolorBST();

	//Tree functions
	int treeDepth();
	void inorder() const;
	void test();
	void insert(int data);
	//TODO: create a remove node function
	void removeNode(int) {};
};

