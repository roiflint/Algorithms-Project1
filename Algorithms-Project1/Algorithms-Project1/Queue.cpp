#include "Queue.h"

Queue::Queue(int item)
{
	head = new Node(value);
	tail = head;
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
		current = temp->next;
		delete temp;
	}
	delete current;
}

int Queue::IsEmpty()
{
	return (head == tail)
}

int Queue::Front(void)
{
	if (IsEmpty())
	{
		//Handle Error
	}

	return (head->next->data);
}

void Queue::EnQueue(int item)
{
	Node* newnode = new Node(item);
	tail->setNext(newnode);
	tail = newnode;

}

int Queue::DeQueue()
{
	if (isEmpty())
	{
		// Handle Error
	}

	Node* temp = this->head;
	int item = temp->data;
	this->head = temp->next;
	if (tail == temp)
	{
		tail = head;
	}

	delete temp;
	return item;
}







