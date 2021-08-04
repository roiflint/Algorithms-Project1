#pragma once
#include "Node.h"

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


