#include <iostream>
#include "BST.h"
int main()
{
	BST bst;
	bst.insert(5);
	bst.insert(2);
	bst.insert(6);
	bst.insert(1);
	bst.inorder();

	std::cout << bst.nrNodes();

	return 0;
}