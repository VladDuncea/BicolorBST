#pragma once
#include <iostream>
class Node
{
protected:
	int privData;
	Node *privFather, *privLeft, *privRight;

public:
	Node(int data,Node *father=NULL,Node *left=NULL,Node *right=NULL);
	Node(const Node & n);
	~Node();

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

	Node&  operator=(const Node &n);
	virtual void display(std::ostream &os) const;
};

std::ostream& operator<<(std::ostream &os,const Node &n);