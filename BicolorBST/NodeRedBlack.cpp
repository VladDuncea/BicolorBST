#include "NodeRedBlack.h"

NodeRedBlack::NodeRedBlack(NRB::Color color, int data, Node * root, Node * left, Node * right):Node(data,root,left,right)
{
	privColor = color;
}

NodeRedBlack::NodeRedBlack(const NodeRedBlack & n):Node(n)
{
	privColor = n.color();
}

NodeRedBlack::~NodeRedBlack()
{
}

void NodeRedBlack::color(const NRB::Color &color)
{
	privColor = color;
}

NRB::Color NodeRedBlack::color() const
{
	return privColor;
}

NodeRedBlack& NodeRedBlack::operator=(const NodeRedBlack &n)
{
	(Node)*this = (Node) n;
	privColor = n.color();
	return *this;
}

std::ostream & operator<<(std::ostream & os, const NodeRedBlack &n)
{
	os << n.data() << "-" << (n.color() == NRB::black ? "black" : "red") << " ";
	return os;
}
