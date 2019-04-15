#pragma once
#include "NodeRedBlack.h"
#include "Tree.h"

class BicolorBST: public Tree
{
	NodeRedBlack *privRoot;
	void privInsert(NodeRedBlack *n, int data);
	//Function to check insertion rules
	void privCheckRules(NodeRedBlack *n);
	//The cases for insertion
	void privCaseOne(NodeRedBlack *base, NodeRedBlack *left, NodeRedBlack *right);
	NodeRedBlack * privCaseTwo(NodeRedBlack *base, NodeRedBlack *left, NodeRedBlack *right,bool reversed);
	NodeRedBlack * privCaseThree(NodeRedBlack *base, NodeRedBlack *left, NodeRedBlack *right,bool reversed);
	int privDepth(NodeRedBlack *n, int blackNr);
	NodeRedBlack * privCopy(NodeRedBlack * father, const NodeRedBlack * toCopy);
	//Function to delete node with x value
	void privRemoveNode(Node *n, int x);
	//Functions to resolve a double black node
	void privDoubleBlack(NodeRedBlack *n);
	void privLeftRotate(NodeRedBlack *n);
	void privRightRotate(NodeRedBlack *n);
	//Function to dealocate all nodes
	void privEmpty(NodeRedBlack *n);
	

protected:
	void protecPrintSRD(Node *n, std::ostream& os) const;
public:
	BicolorBST();
	BicolorBST(NodeRedBlack *root);
	BicolorBST(BicolorBST &bst);
	~BicolorBST();

	//Tree functions
	int treeDepth();
	void inorder() const;
	void test();
	void insert(int data);
	void removeNode(int x);

	BicolorBST & operator=(const BicolorBST& bst);
};

