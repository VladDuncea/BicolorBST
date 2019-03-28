#pragma once

class  Tree
{
protected:
	int privNrNodes;
	
public:
	Tree();
	~Tree();
	

	virtual void insert(int) = 0;
	virtual void inorder() const = 0;
	virtual void removeNode(int) = 0;
	virtual int nrNodes() = 0;
};

