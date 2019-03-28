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
	//Hide copy constructor
	NodeRedBlack(NodeRedBlack &n) :Node(0) {};
	
	//The color of the node
	NRB::Color privColor;

public:
	
	NodeRedBlack(NRB::Color color,int data,Node *root = NULL,Node *left=NULL,Node *right=NULL);
	~NodeRedBlack();

	//Setter and getter functions for the node color
	void color(NRB::Color &color);
	NRB::Color color() const;
};

