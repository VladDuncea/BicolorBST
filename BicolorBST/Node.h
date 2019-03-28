#pragma once
#include <iostream>
class Node
{
	int privData;
	Node *privFather, *privLeft, *privRight;

	//Nodes cant be copied
	Node(Node &n) {};
public:
	Node(int data,Node *father=NULL,Node *left=NULL,Node *right=NULL);
	~Node() {};

	//Setter and getter for info variable
	int data();
	void data(int newData);
	//Setter and getter for father variable
	Node* father();
	void father(Node *newFather);
	//Setter and getter for left variable
	Node* left();
	void left(Node *newLeft);
	//Setter and getter for right variable
	Node* right();
	void right(Node *newRight);
};

