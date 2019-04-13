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

void NodeRedBlack::display(std::ostream & os) const
{
	os << data() << "-";
	switch (color())
	{
	case NRB::black:
			std::cout << "black";
			break;
	case NRB::doubleBlack:
		std::cout << "doubleBlack";
		break;
	case NRB::red:
		std::cout << "red";
		break;
	default:
		std::cout << "unknown color";
		break;
	}
	std::cout << " ";
}

