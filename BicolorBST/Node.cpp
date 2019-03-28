#include "Node.h"

Node::Node(int data, Node * father, Node * left, Node * right)
{
	this->privData = data;
	this->privFather = father;
	this->privLeft = left;
	this->privRight = right;
}

int Node::data()
{
	return privData;
}

void Node::data(int newData)
{
	privData = newData;
}

Node * Node::father()
{
	return privFather;
}

void Node::father(Node * newFather)
{
	privFather = newFather;
}

Node * Node::left()
{
	return privLeft;
}

void Node::left(Node * newLeft)
{
	privLeft = newLeft;
}

Node * Node::right()
{
	return privRight;
}

void Node::right(Node * newRight)
{
	privRight = newRight;
}
