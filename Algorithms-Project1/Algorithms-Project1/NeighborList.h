#pragma once
#include "Node.h"
class NeighborList {
private:
	Node* head;
	Node* tail;

public:
	NeighborList();
	~NeighborList();
	void addNeighbor(Node* neighbor);
	void removeNeighbor(Node* neighbor);
	Node* getHead();
	Node* getTail();
};