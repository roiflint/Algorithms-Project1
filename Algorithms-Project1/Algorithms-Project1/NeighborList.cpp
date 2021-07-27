#include "NeighborList.h"

NeighborList::NeighborList() { this->head = nullptr; this->tail = nullptr; }
NeighborList::~NeighborList() {
	while (head != nullptr){
		Node* tmp = head;
		head = head->getNext();
		delete tmp;
	}
}
void NeighborList::addNeighbor(Node* neighbor) {
	if (this->head==nullptr){
		this->head = neighbor;
		this->tail = neighbor;
	}
	else {
		this->tail->setNext(neighbor);
		this->tail = neighbor;
	}
}
void NeighborList::removeNeighbor(Node* neighbor) {
	Node* tmp = this->head;
	if (this->head == this->tail && this->head == neighbor)
	{
		delete neighbor;
		this->head = nullptr;
		this->tail = nullptr;
		return;
	}
	if (this->head == neighbor)
	{
		this->head = this->head->getNext();
		delete tmp;
		return;
	}
	while (tmp->getNext() != neighbor)
	{
		tmp = tmp->getNext();
	}
	if (tmp->getNext() == this->tail)
	{
		this->tail = tmp;
		this->tail->setNext(nullptr);
		delete neighbor;
		return;
	}
	else {
		tmp->setNext(neighbor->getNext());
		delete neighbor;
		return;
	}
}

Node* NeighborList::getHead() { return this->head; }
Node* NeighborList::getTail() { return this->tail; }