#include "Queue.h"

Queue::Queue()
{
	head = nullptr;
	tail = nullptr;
}

Queue::~Queue()
{
	MakeEmpty();
}

void Queue::MakeEmpty()
{
	Node* current = this->head;
	while (current != this->tail)
	{
		Node* temp = current;
		current = temp->getNext();
		delete temp;
	}
	delete current;
}

int Queue::IsEmpty()
{
	if (head == nullptr && tail == nullptr)
	{
		return 1;
	}
	else
		return 0;
}

int Queue::Front(void)
{
	return (head->getNext()->getValue());
}

void Queue::EnQueue(int item)
{
	Node* newnode = new Node(item);
	if (tail == nullptr)
	{
		tail = newnode;
		head = newnode;
	}
	
	else
	{
		tail->setNext(newnode);
		tail = newnode;
	}

}

int Queue::DeQueue()
{
	
	Node* temp = this->head;
	int item = temp->getValue();
	this->head = temp->getNext();
	if (tail == temp)
	{
		tail = head;
	}

	delete temp;
	return item;
}
