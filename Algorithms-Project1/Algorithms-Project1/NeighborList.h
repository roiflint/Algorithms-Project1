#pragma once
#include "Node.h"

/*Implementation of the ADT neighbor list of the graph*/

class NeighborList {
private:
	Node* head;
	Node* tail;

public:
	/*Ctor*/
	NeighborList();
	
	/*Dtor*/
	~NeighborList();

	/*Adds a vertex as a neighbor of current list*/
	void addNeighbor(Node* neighbor);

	/*Removes a vertex from the neighbor list*/
	void removeNeighbor(Node* neighbor);

	/*Gets the head of the neighbor list*/
	Node* getHead();

	/*Gets the tail of the neighbor list*/
	Node* getTail();
};