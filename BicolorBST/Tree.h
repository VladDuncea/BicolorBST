#pragma once
#include "Node.h"
class  Tree
{
protected:
	int privNrNodes;
	virtual void protecPrintSRD(Node *n, std::ostream& os) const; //Se poate face ceva cu afisarea sa fie virtuala ??
public:
	Tree();
	~Tree();
	
	virtual int nrNodes();

	virtual void insert(int) = 0;
	virtual void inorder() const = 0;
	virtual void removeNode(int) = 0;
};

