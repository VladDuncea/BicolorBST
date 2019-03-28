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

class NodeRedBlack :private Node
{
public:
	
	NodeRedBlack(NRB::Color color,int data,Node *root = NULL,Node *left=NULL,Node *right=NULL);
	~NodeRedBlack();

	//Setter and getter functions for the node color
	void color(NRB::Color &color);
	NRB::Color color();

private:
	NRB::Color privColor;

};

