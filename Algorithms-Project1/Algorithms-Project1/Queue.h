#pragma once
#include "Node.h"

/*Implementation of data structure Queue for the BFS algorithm*/

class Queue
{
private:
	Node* head, * tail;

public:

	/*Ctor & Dtor*/
	Queue();
	~Queue();

	/*Empty the queue*/
	void MakeEmpty();

	/*Check if queue is empty*/
	int IsEmpty();

	/*Returns the head of the queue*/
	int Front();

	/*Enter the item into the queue*/
	void EnQueue(int item);

	/*Remove the item from the queue*/
	int DeQueue();
};


