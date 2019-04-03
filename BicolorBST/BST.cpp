#include "BST.h"

void BST::priv_insert(Node * father, int data)
{
	//The node belongs to the left
	if (data <= father->data())
	{
		//There is a left son
		if (father->left() != NULL)
		{
			priv_insert(father->left(), data);
		}
		else
		{
			//We place the node as the left son of father
			Node *add = new Node(data, father);
			father->left(add);
		}
		return;
	}

	//The node belongs to the right
	if (data > father->data())
	{	
		//There is a right son
		if (father->right() != NULL)
		{
			priv_insert(father->right(), data);
		}
		else
		{
			//We place the node as the right son of father
			Node *add = new Node(data, father);
			father->right(add);
		}
		return;
	}

	
}

void BST::privEmpty(Node * n)
{
	if (n == NULL)
		return;
	privEmpty(n->left());
	privEmpty(n->right());
	delete n;

}

BST::BST()
{
	privRoot = NULL;
}

BST::BST(Node * root)
{
	if(root)
		privRoot = root;
	else {
		std::cerr << "Cant initialize BST with NULL root"<<std::endl;
		exit(-1);
	}
}

BST::~BST()
{
	//Dealocate all the nodes
	privEmpty(privRoot);
}

void BST::inorder() const
{
	if(privRoot)
		protecPrintSRD(privRoot, std::cout);
}

void BST::insert(int data)
{
	//The tree has no nodes
	if (privRoot == NULL)
	{
		privRoot = new (std::nothrow) Node{ data,NULL };
		if (privRoot == NULL)
			exit(-1);
	}
	else
		priv_insert(privRoot, data);

	//Add 1 to the nr of nodes
	privNrNodes++;
}
