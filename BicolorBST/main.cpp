#include <iostream>
#include "BST.h"
#include "BicolorBST.h"

int main()
{
	BST bst;
	bst.insert(3);
	bst.insert(4);
	bst.insert(5);
	bst.insert(1);
	bst.insert(2);
	bst.insert(7);
	bst.insert(6);
	bst.insert(8);
	bst.inorder();

	bst.removeNode(3);
	bst.removeNode(5);
	bst.removeNode(8);
	bst.removeNode(1);
	bst.removeNode(6);
	bst.removeNode(2);
	bst.removeNode(7);
	bst.removeNode(4);


	bst.inorder();

	std::cout<<bst.treeDepth()<<std::endl;
	//bst.test();
	//bst.inorder();

	//std::cout << bst.nrNodes();

	return 0;
}