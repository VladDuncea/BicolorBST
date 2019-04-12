#pragma once
#include "Node.h"

namespace NRB
{
	enum Color
	{
		red = 0,
		black = 1
	};
}

class NodeRedBlack :public Node
{
	//The color of the node
	NRB::Color privColor;

public:
	
	NodeRedBlack(NRB::Color color,int data,Node *root = NULL,Node *left=NULL,Node *right=NULL);
	NodeRedBlack(const NodeRedBlack &n);
	~NodeRedBlack();

	//Setter and getter functions for the node color
	void color(const NRB::Color &color);
	NRB::Color color() const;

	//Operators
	NodeRedBlack& operator=(const NodeRedBlack& n);
	void display(std::ostream &os) const;
};