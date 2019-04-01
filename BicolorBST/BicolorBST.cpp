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
			inorder();
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
			inorder();
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
	//This is the root node, there is nothing to be done
	if (n->father() == NULL)
		return;

	//The node is well placed
	if (((NodeRedBlack *)n->father())->color() == NRB::black)
		return;
	//Get base the father of the father of n
	NodeRedBlack * base = (NodeRedBlack *)n->father()->father();

	//The tree is only 2 levels high
	if (base == NULL)
	{
		privRoot->color(NRB::black);
		std::cout << "Nodul:" << privRoot->data() << " caz radacina\n";
		return;
	}

	//Get left and right of base for convenience
	NodeRedBlack * left = (NodeRedBlack *)base->left();
	NodeRedBlack * right = (NodeRedBlack *)base->right();

	//Check for case 1 (both children of 'base' are red and they exist)
	if (left != NULL && right != NULL && left->color() == NRB::red && right->color() == NRB::red)
	{
		privCaseOne(base, left, right);
	}
	//Case two (the node is on the exterior- right side)
	else if (base->left() == n->father() && left->left() == n)
	{
		//Call case two
	}
	//TO DO...

	//Recursively arrange the tree
	privCheckRules(base);
}

void BicolorBST::privCaseOne(NodeRedBlack * base, NodeRedBlack * left, NodeRedBlack * right)
{
	base->color(NRB::red);
	left->color(NRB::black);
	right->color(NRB::black);
	std::cout << "Nodul:" << base->data() << " caz 1\n";
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
	privEmpty(privRoot);
}

void BicolorBST::inorder() const
{
	if (privRoot)
		priv_printSRD(privRoot, std::cout);
	std::cout << std::endl;
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
