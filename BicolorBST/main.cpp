#include <iostream>
#include "BST.h"
#include "BicolorBST.h"

int main()
{
	BicolorBST bst;
	bst.insert(3);
	bst.insert(4);
	bst.insert(5);
	bst.insert(1);
	bst.insert(2);
	bst.insert(7);
	bst.insert(6);
	bst.insert(8);

	bst.test();
	//bst.inorder();

	//std::cout << bst.nrNodes();

	return 0;
}