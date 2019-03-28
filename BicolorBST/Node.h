#pragma once
#include <iostream>
class Node
{
	//Nodes cant be copied
	Node(const Node &n) {};
protected:
	int privData;
	Node *privFather, *privLeft, *privRight;

public:
	Node(int data,Node *father=NULL,Node *left=NULL,Node *right=NULL);
	~Node() {};

	//Getter for data variable
	int data() const;
	//Setter for data variable
	void data(int newData);

	//Getter for father variable
	Node* father() const;
	//Setter for father variable
	void father(Node *newFather);

	//Getter for left variable
	Node* left() const;
	//Setter for left variable
	void left(Node *newLeft);

	//Getter for right variable
	Node* right() const;
	//Setter for right variable
	void right(Node *newRight);
};

