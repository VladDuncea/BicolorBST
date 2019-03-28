#pragma once
#include "NodeRedBlack.h"
#include "Tree.h"

class BicolorBST: private Tree
{
	NodeRedBlack *privRoot;
	void priv_printSRD(const Node *n, std::ostream &os) const;
	void privEmpty(Node *n);

public:
	BicolorBST();
	BicolorBST(NodeRedBlack *root);
	~BicolorBST();

	void inorder() const;
	void insert(int data);
	void removeNode(int) {};
	int nrNodes();
};

