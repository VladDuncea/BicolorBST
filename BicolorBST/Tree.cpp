#include "Tree.h"

void Tree::protecPrintSRD(Node *n, std::ostream & os) const
{
	if (n == NULL)
		return;
	protecPrintSRD(n->left(), os);
	os << n;
	protecPrintSRD(n->right(), os);
}

Tree::Tree()
{
	privNrNodes = 0;
}


Tree::~Tree()
{
}

int Tree::nrNodes()
{
	return privNrNodes;
}
