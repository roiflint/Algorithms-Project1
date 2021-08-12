#pragma once
#include "Node.h"

/*Implementation of data structure Queue for the BFS algorithm*/

class Queue
{
private:
	Node* head, * tail;

public:
	Queue();
	~Queue();
	void MakeEmpty();
	int IsEmpty();
	int Front();
	void EnQueue(int item);
	int DeQueue();
};


