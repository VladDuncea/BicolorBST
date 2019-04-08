#pragma once
#include "Node.h"
class  Tree
{
protected:
	int privNrNodes;
	virtual void protecPrintSRD(Node *n, std::ostream& os) const; 
	
public:
	Tree();
	Tree(Tree &t);
	virtual ~Tree() = 0;
	
	virtual int nrNodes();
	virtual int treeDepth() = 0;
	virtual void insert(int) = 0;
	virtual void inorder() const = 0;
	virtual void removeNode(int) = 0;
};