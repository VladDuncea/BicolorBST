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

int BST::privDepth(Node * n, int depth)
{
	if (n == NULL)
		return depth - 1;
	int ld = privDepth(n->left(), depth + 1);
	int rd = privDepth(n->right(), depth + 1);
	return ld > rd ? ld : rd;
}

void BST::privRemoveNode(Node * n, int x)
{
	//The node with value x is not in the BST
	if (n == NULL)
		return;

	//Found the node
	if (n->data() == x)
	{
		//The node has at most one child
		if (n->left() == NULL || n->right() == NULL)
		{
			//The node has no children
			if (n->left() == NULL && n->right() == NULL)
			{
				//The node is the last one in the BST
				if (n == privRoot)
				{
					privRoot = NULL;
					delete n;
					return;
				}
				//Break the node from its father
				if (n->father()->data() < n->data())
					n->father()->right(NULL);
				else
					n->father()->left(NULL);
				//Free the memory
				delete n;
				return;
			}

			//The node has one child
			Node *child = (n->left() == NULL) ? n->right() : n->left();
			//Link the father of the node to the child
			if (n->data() < n->father()->data())
				n->father()->left(child);
			else
				n->father()->right(child );
			//Link the child to the new father
			child->father(n->father());
			//Free memory
			delete n;
			return;
		}

		//The node has both children
		//Find the minimal node greather than this
		Node *aux = n->right();
		while (aux->left() != NULL)
			aux = aux->left();
		//Set the found node in place of the removed one
		n->data(aux->data());
		//Remove the found node
		privRemoveNode(aux, aux->data());
		return;
	}

	//Search for the node
	if (n->data() < x)
		privRemoveNode(n->right(), x);
	else
		privRemoveNode(n->left(), x);
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

BST::BST(BST & bst):Tree(bst)
{
	//TODO copy constructor
}

BST::~BST()
{
	//Dealocate all the nodes
	privEmpty(privRoot);
}

int BST::treeDepth()
{
	return privDepth(privRoot, 1);
}

void BST::inorder() const
{
	if (privRoot)
		protecPrintSRD(privRoot, std::cout);
	else
		std::cout << "Arbore gol!";
	std::cout << std::endl;
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

void BST::removeNode(int x)
{
	privRemoveNode(privRoot, x);
}

BST & BST::operator=(BST & bst)
{
	//If this tree has nodes delete them first
	if (privRoot != NULL)
		privEmpty(privRoot);
	//Copy private variables
	privNrNodes = bst.privNrNodes;
	privRoot = bst.privRoot;
	//TODO: Finish operator =
	return *this;
}
