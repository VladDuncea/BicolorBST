#include "Node.h"

Node::Node(int data, Node * father, Node * left, Node * right)
{
	this->privData = data;
	this->privFather = father;
	this->privLeft = left;
	this->privRight = right;
}

Node::Node(const Node & n)
{
	*this = n;
}

Node::~Node()
{
}

int Node::data() const
{
	return privData;
}

void Node::data(int newData)
{
	privData = newData;
}

Node * Node::father() const
{
	return privFather;
}

void Node::father(Node * newFather)
{
	privFather = newFather;
}

Node * Node::left() const
{
	return privLeft;
}

void Node::left(Node * newLeft)
{
	privLeft = newLeft;
}

Node * Node::right() const
{
	return privRight;
}

void Node::right(Node * newRight)
{
	privRight = newRight;
}

Node& Node::operator=(const Node &n)
{
	privData = n.data();
	privFather = n.father();
	privLeft = n.left();
	privRight = n.right();
	return *this;
}

void Node::display(std::ostream & os) const
{
	os << data() << " ";
}

std::ostream& operator<<(std::ostream &os, const Node &n)
{
	n.display(os);
	return os;
}