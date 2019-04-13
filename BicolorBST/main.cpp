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
	for(auto t :trees)
	{
		
		t->removeNode(4);
		t->inorder();
		t->removeNode(5);
		t->removeNode(7);
		t->removeNode(6);
		t->inorder();
		t->removeNode(3);
		t->removeNode(8);
		t->removeNode(1);
		t->removeNode(2);
		t->inorder();
	}
	
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