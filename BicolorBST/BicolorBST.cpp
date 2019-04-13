#include "BicolorBST.h"

void BicolorBST::privInsert(NodeRedBlack * n, int data)
{
	//Node is to the left
	if (data < n->data())
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
			//inorder(); //Step by step logging
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
			//inorder(); //Step by step logging
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
	//This is the root node or it's already black, there is nothing to be done
	//This check is done to end the recursion
	if (n->father() == NULL || n->color()==NRB::black)
		return;

	//The node is well placed
	if (((NodeRedBlack *)n->father())->color() == NRB::black)
		return;

	//Get base = the father of the father of n
	NodeRedBlack * base = (NodeRedBlack *)n->father()->father();

	//The tree is only 2 levels high
	if (base == NULL)
	{
		privRoot->color(NRB::black);
		//std::cout << "Nodul:" << privRoot->data() << " caz radacina\n";
		return;
	}

	//Create placeholder in case of null left/right
	NodeRedBlack placeholder(NRB::black, -1);

	//Get left and right of base for convenience
	NodeRedBlack * left = (NodeRedBlack *)base->left();
	NodeRedBlack * right = (NodeRedBlack *)base->right();
	if (left == NULL)
		left = &placeholder;
	if (right == NULL)
		right = &placeholder;

	//Check for case 1 (both children of 'base' are red)
	if (left->color() == NRB::red && right->color() == NRB::red)
	{
		privCaseOne(base, left, right);
		//std::cout << "Nodul:" << base->data() << " caz 1\n";
	}
	//Case two (the node is on the exterior - left side)
	else if (base->left() == n->father() && left->left() == n)
	{
		base = privCaseTwo(base, left, right, false);
		//std::cout << "Nodul:" << base->data() << " caz 2\n";
	}
	//Case two (the node is on the exterior - right side)
	else if (base->right() == n->father() && right->right() == n)
	{
		base = privCaseTwo(base, left, right, true);
		//std::cout << "Nodul:" << base->data() << " caz 2'\n";
	}
	//Case three(the node is on the interior - left side
	else if (base->left() == n->father() && left->right() == n)
	{
		base = privCaseThree(base, left, right, false);
		//std::cout << "Nodul:" << base->data() << " caz 3\n";

	}//Case three(the node is on the interior - left side
	else if (base->right() == n->father() && right->left() == n)
	{
		base = privCaseThree(base, left, right, true);
		//std::cout << "Nodul:" << base->data() << " caz 3'\n";
	}
	else
	{
		std::cerr << "\n Unexpected point reached\n";
		exit(-1);
	}
	
	//Recursively check the tree
	privCheckRules(base);
}

void BicolorBST::privCaseOne(NodeRedBlack * base, NodeRedBlack * left, NodeRedBlack * right)
{
	base->color(NRB::red);
	left->color(NRB::black);
	right->color(NRB::black);
}

NodeRedBlack* BicolorBST::privCaseTwo(NodeRedBlack * base, NodeRedBlack * left, NodeRedBlack * right,bool reversed)
{
	NodeRedBlack * father = reversed ? right : left;

	//Color the father of the node in black
	father->color(NRB::black);
	//Color the base in red
	base->color(NRB::red);

	//Rotate the subtree to the right / left
		//Add the new links
	if (!reversed)
		father->right(base);
	else
		father->left(base);

	father->father(base->father());
	base->father(father);
		//Eliminate old links
	if (!reversed)
		base->left(NULL);
	else
		base->right(NULL);

	//Connect the subtree back to the tree
		//Check if the base was the root
	if (base == privRoot)
	{
		father->father(NULL);
		privRoot = father;
		return father;
	}
		//Base is not tree's root
	if (father->father()->left() == base)
		father->father()->left(father);
	else
		father->father()->right(father);
	return father;
}

NodeRedBlack* BicolorBST::privCaseThree(NodeRedBlack * base, NodeRedBlack * left, NodeRedBlack * right, bool reversed)
{
	NodeRedBlack * n;
	//Rotate the small left subtree for not reversed
	if (!reversed)
	{
		n = (NodeRedBlack*)left->right();
		//Link base to n
		base->left(n);
		//Link the initial left to n
		n->left(left);
		//Remove the old left link
		left->right(NULL);
		//Set fathers
		n->father(base);
		left->father(n);
		//Call case 2 for the changed subtree
		return privCaseTwo(base, (NodeRedBlack*)base->left(), right, false);
	}
	//Rotate the small right subtree for reversed
	else
	{
		n = (NodeRedBlack*)right->left();
		//Link base to n
		base->right(n);
		//Link the initial right to n
		n->right(right);
		//Remove the old right link
		right->left(NULL);
		//Set fathers
		n->father(base);
		right->father(n);
		//Call case 2 for the changed subtree
		return privCaseTwo(base,left, (NodeRedBlack*)base->right(), true);
	}
}

void BicolorBST::privEmpty(NodeRedBlack* n)
{
	if (n == NULL)
		return;
	privEmpty((NodeRedBlack*)n->left());
	privEmpty((NodeRedBlack*)n->right());
	delete n;
	
}

int BicolorBST::privDepth(NodeRedBlack * n, int blackNr)
{
	if (n == NULL)
		return blackNr;
	NodeRedBlack * nrb = (NodeRedBlack*)n;
	//Count only the black nodes
	return privDepth((NodeRedBlack*)n->left(), nrb->color() == NRB::black ? blackNr + 1 : blackNr);
}

NodeRedBlack * BicolorBST::privCopy(NodeRedBlack * father,const NodeRedBlack * toCopy)
{
		if (toCopy == NULL)
			return NULL;
		NodeRedBlack *copyN = new NodeRedBlack(toCopy->color(),toCopy->data(), father);
		copyN->left(privCopy(copyN,(NodeRedBlack *) toCopy->left()));
		copyN->right(privCopy(copyN, (NodeRedBlack *)toCopy->right()));
		return copyN;
}

void BicolorBST::privRemoveNode(Node * n, int x)
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

				//Check if the node is red
				if (((NodeRedBlack*)n)->color() == NRB::red)
				{
					//Break the node from its father
					if (n->data() < n->father()->data())
						n->father()->left(NULL);
					else
						n->father()->right(NULL);
				}
				else
				{
					//A black node was deleted
					privDoubleBlack((NodeRedBlack*)n);
				}
				//Free the memory
				delete n;
				return;
			}

			//The node has one child
			//Get the child
			NodeRedBlack *child = (NodeRedBlack*)(n->left() == NULL ? n->right() : n->left());

			//Check for double black case but only for non root nodes
			if (((NodeRedBlack*)n)->color() == NRB::black&& n != privRoot)
			{
				if (child->color() == NRB::red)
					child->color(NRB::black);
				else
					child->color(NRB::doubleBlack); //TODO this should not exist
			}
			//Link the father of the node to the child
			//This is not the root
			if (n->father() != NULL)
			{
				//Link the father of the node to the child
				if (n->data() < n->father()->data())
					n->father()->left(child);
				else
					n->father()->right(child);
			}
			//This is the root => update the root
			else
			{
				privRoot = (NodeRedBlack*)child;
				//Make the root black (this also solves deleting a black root
				privRoot->color(NRB::black);
			}

			//Link the child to the new father
			child->father(n->father());
			//Free memory
			delete n;

			//Check for double black
			privDoubleBlack(child);
			
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

void BicolorBST::privDoubleBlack(NodeRedBlack * n)
{
	//Check for end of recursion
	if (n == privRoot)
	{
		n->color(NRB::black);
		return;
	}

	//Find sibling and node position
	NodeRedBlack * sibling, *parent;
	NodeRedBlack *sLeft, *sRight;
	parent = (NodeRedBlack*)n->father();

	//Get the sibling
	if (parent->left() == n)
	{
		sibling = (NodeRedBlack*)parent->right();
	}
	else
	{
		sibling = (NodeRedBlack*)parent->left();
	}

	//No sibling, go up
	if (sibling == NULL)
	{
		privDoubleBlack(parent);
		return;
	}

	//Get siblings children
	sLeft = (NodeRedBlack*)sibling->left();
	sRight = (NodeRedBlack*)sibling->right();
	
	//The sibling is black
	if (sibling->color() == NRB::black)
	{
		//We are on the left
		if (parent->left() == n)
		{
			//The sibling is on the left has at least one red child
			if (sRight != NULL && sRight->color() == NRB::red)
			{
				//Put the sibling as this subtrees father
				if (parent->father()->left() == parent)
					parent->father()->left(sibling);
				else
					parent->father()->right(sibling);

				sibling->father(parent->father());
				sibling->left(parent);
				parent->father(sibling);

				//Make siblings right child black
				sRight->color(NRB::black);

				//Relink left and right of old parent
				parent->left(NULL);
				parent->right(sLeft);
				if (sLeft != NULL)
					sLeft->father(parent);
			}
			else if (sLeft != NULL && sLeft->color() == NRB::red)
			{
				//Make siblings left child black
				sLeft->color(NRB::black);

				//Make sLeft the new parent of this subtree
				if (parent->father()->left() == parent)
					parent->father()->left(sLeft);
				else
					parent->father()->right(sLeft);

				sLeft->father(parent->father());
				sLeft->left(parent);
				parent->father(sLeft);
				sLeft->right(sibling);
				sibling->father(sLeft);

				//Empty parents children
				parent->left(NULL);
				parent->right(NULL);

				//Empty siblings children
				sibling->left(NULL);
			}
			else
			{
				//The case where the sibling has no red children
				//Make the sibling red
				sibling->color(NRB::red);
				//Color the parent of subtree black/doubleblack
				if (parent->color() == NRB::black)
				{
					privDoubleBlack(parent);
					return;
				}
				else
					parent->color(NRB::black);
			}
		}
		else
		{
			//The sibling is on the left and has at least one red child
			if (sLeft != NULL && sLeft->color() == NRB::red)
			{
				//Put the sibling as this subtrees father
				if (parent->father()->left() == parent)
					parent->father()->left(sibling);
				else
					parent->father()->right(sibling);

				sibling->father(parent->father());
				sibling->right(parent);
				parent->father(sibling);

				//Make siblings left child black
				sLeft->color(NRB::black);

				//Relink left and right of old parent
				parent->right(NULL);
				parent->left(sRight);
				if (sLeft != NULL)
					sLeft->father(parent);
			}
			else if (sRight != NULL && sRight->color() == NRB::red)
			{
				//Make siblings left child black
				sRight->color(NRB::black);

				//Make sLeft the new parent of this subtree
				if (parent->father()->left() == parent)
					parent->father()->left(sLeft);
				else
					parent->father()->right(sLeft);

				sRight->father(parent->father());
				sRight->right(parent);
				parent->father(sRight);
				sLeft->left(sibling);
				sibling->father(sRight);

				//Empty parents children
				parent->left(NULL);
				parent->right(NULL);

				//Empty siblings children
				sibling->right(NULL);
			}
			else
			{
				//The case where the sibling has no red children
				//Make the sibling red
				sibling->color(NRB::red);
				//Color the parent of subtree black/doubleblack
				if (parent->color() == NRB::black)
				{
					privDoubleBlack(parent);
					return;
				}
				else
					parent->color(NRB::black);
			}
		}
	}
	else
	{
		//The sibling is red
		//n is on the left
		if (parent->left() == n)
		{
			//Change the colors
			sibling->color(NRB::black);
			sLeft->color(NRB::red);

			//Place sibling as new parent of subtree
			if (parent->father()->left() == parent)
				parent->father()->left(sibling);
			else
				parent->father()->right(sibling);

			sibling->father(parent->father());
			sibling->left(parent);
			parent->father(sibling);
			sibling->right(sRight);
			sRight->father(sibling);
			
			//Link parents children
			parent->left(NULL);
			parent->right(sLeft);
			sLeft->father(parent);
		}
		else
		{
			//Change the colors
			sibling->color(NRB::black);
			sRight->color(NRB::red);

			//Place sibling as new parent of subtree
			if (parent->father()->left() == parent)
				parent->father()->left(sibling);
			else
				parent->father()->right(sibling);

			sibling->father(parent->father());
			sibling->right(parent);
			parent->father(sibling);
			sibling->left(sLeft);
			sLeft->father(sibling);

			//Link parents children
			parent->right(NULL);
			parent->left(sRight);
			sRight->father(parent);
		}
	}
}

void BicolorBST::protecPrintSRD(Node * n, std::ostream & os) const
{
	if (n == NULL)
		return;
	protecPrintSRD(n->left(), os);
	os << *((NodeRedBlack*) n);
	protecPrintSRD(n->right(), os);
}

BicolorBST::BicolorBST()
{
	privRoot = NULL;
}

BicolorBST::BicolorBST(NodeRedBlack * root)
{
	privRoot = root;
}

BicolorBST::BicolorBST(BicolorBST & bst)
{
	//Set root to null for operator=
	privRoot = NULL;
	*this = bst;
}

BicolorBST::~BicolorBST()
{
	privEmpty(privRoot);
}

int BicolorBST::treeDepth()
{
	return privDepth(privRoot, 0);
}

void BicolorBST::inorder() const
{
	if (privRoot)
		protecPrintSRD(privRoot, std::cout);
	std::cout << std::endl;
}

void BicolorBST::test()
{
	NodeRedBlack n = *((NodeRedBlack*) privRoot->left());
	std::cout << n << std::endl;
	Node a = *privRoot;
	std::cout << a << std::endl;
	a = n;
	std::cout << a << std::endl;
}

void BicolorBST::insert(int data)
{
	if (privRoot == NULL)
	{
		privRoot = new (std::nothrow) NodeRedBlack(NRB::black, data);
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

void BicolorBST::removeNode(int x)
{
	privRemoveNode(privRoot, x);
}

BicolorBST & BicolorBST::operator=(const BicolorBST & bst)
{
	//If this tree has nodes delete them first
	if (privRoot != NULL)
		privEmpty(privRoot);
	//Copy private variables
	privNrNodes = bst.privNrNodes;
	//Create the root
	NodeRedBlack *newRoot = new NodeRedBlack(bst.privRoot->color(),bst.privRoot->data(), NULL);
	//Set the root
	privRoot = newRoot;
	//Recursively copy each node and link them properly
	privRoot->left(privCopy(privRoot, (NodeRedBlack*)bst.privRoot->left()));
	privRoot->right(privCopy(privRoot, (NodeRedBlack*)bst.privRoot->right()));
	return *this;
}
