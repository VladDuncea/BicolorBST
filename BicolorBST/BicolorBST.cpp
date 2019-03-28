#include "BicolorBST.h"

void BicolorBST::priv_printSRD(const Node * n, std::ostream & os) const
{
	if (n == NULL)
		return;
	priv_printSRD(n->left(), os);
	os << n->data() << " ";
	priv_printSRD(n->right(), os);
}

void BicolorBST::privEmpty(Node* n)
{
	if (n == NULL)
		return;
	privEmpty(n->left());
	privEmpty(n->right());
	delete n;
	
}

BicolorBST::BicolorBST()
{
	privRoot = NULL;
}

BicolorBST::BicolorBST(NodeRedBlack * root)
{
	privRoot = root;
}


BicolorBST::~BicolorBST()
{
}

void BicolorBST::inorder() const
{
	if (privRoot)
		priv_printSRD(privRoot, std::cout);
}
