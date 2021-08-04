#include "Node.h"

Node::Node(int value) {
	this->value = value;
	this->next = nullptr;
}
Node::~Node() {}
Node* Node::getNext() { return this->next; }
void Node::setNext(Node* next) { this->next = next; }
int Node::getValue() { return this->value; }
void Node::setValue(int value) { this->value = value; }