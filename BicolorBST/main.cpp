#include <iostream>
#include "BST.h"
#include "BicolorBST.h"

int main()
{
	Tree * trees[2];
	trees[0] = new BST;
	trees[1] = new BicolorBST;
	for (auto t : trees)
	{
		t->insert(3);
		t->insert(4);
		t->insert(5);
		t->insert(1);
		t->insert(2);
		t->insert(7);
		t->insert(6);
		t->insert(8);
		t->inorder();
		std::cout <<"Adancime: "<< t->treeDepth() << std::endl;
		
	}

	BicolorBST bst = *((BicolorBST*)trees[1]);
	bst.inorder();
	bst.insert(9);
	bst.inorder();
	bst = *((BicolorBST*)trees[1]);
	bst.inorder();
	
	
	/*
	bst.removeNode(3);
	bst.removeNode(5);
	bst.removeNode(8);
	bst.removeNode(1);
	bst.removeNode(6);
	bst.removeNode(2);
	bst.removeNode(7);
	bst.removeNode(4);
	*/

	//bst.inorder();

	
	//bst.test();
	//bst.inorder();

	//std::cout << bst.nrNodes();

	return 0;
}