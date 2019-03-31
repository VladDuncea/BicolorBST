#include "BicolorBST.h"

void BicolorBST::priv_printSRD(const NodeRedBlack * n, std::ostream & os) const
{
	if (n == NULL)
		return;
	priv_printSRD((NodeRedBlack *) n->left(), os);
	os << n->data() << (n->color() == NRB::black ? " black" : " red") << " ";
	priv_printSRD((NodeRedBlack *) n->right(), os);
}

void BicolorBST::privInsert(NodeRedBlack * n, int data)
{
	//Node is to the left
	if (data <= n->data())
	{
		//Found position
		if (n->left() == NULL)
		{
			n->left(new (std::nothrow) NodeRedBlack(NRB::red,data,n));
			if (n->left() == NULL)
			{
				std::cerr << "Eroare alocare memorie" << std::endl;
				exit(-1);
			}
			//Check if new node is corectly placed and colored
			privCheckRules((NodeRedBlack *) n->left());
		}
		else
		{
			//Recursively search for position
			privInsert((NodeRedBlack *)n->left(), data);
		}
	}
	else
	{
		//Found position
		if (n->right() == NULL)
		{
			n->right(new (std::nothrow) NodeRedBlack(NRB::red, data, n));
			if (n->right() == NULL)
			{
				std::cerr << "Eroare alocare memorie" << std::endl;
				exit(-1);
			}
			//Check if new node is corectly placed and colored
			privCheckRules((NodeRedBlack *) n->right());
		}
		else
		{
			//Recursively search for position
			privInsert((NodeRedBlack *)n->right(), data);
		}
	}
}

void BicolorBST::privCheckRules(NodeRedBlack * n)
{

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

void BicolorBST::insert(int data)
{
	if (privRoot == NULL)
	{
		privRoot = new (std::nothrow) NodeRedBlack(NRB::red, data);
		if (privRoot == NULL)
		{
			std::cerr << "Memory alocation error !" << std::endl;
			exit(-1);
		}
	}
	else
		privInsert(privRoot, data);

	privNrNodes++;
}
