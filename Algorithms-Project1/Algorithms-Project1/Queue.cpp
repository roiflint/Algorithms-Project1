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
	return (head == tail);
}

int Queue::Front(void)
{
	if (IsEmpty())
	{
		//Handle Error
	}

	return (head->getNext()->getValue());
}

void Queue::EnQueue(int item)
{
	Node* newnode = new Node(item);
	tail->setNext(newnode);
	tail = newnode;

}

int Queue::DeQueue()
{
	if (IsEmpty())
	{
		// Handle Error
	}

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







