#include "Node.h"

Node::Node(int value, int weight) {
	this->value = value;
	this->weight = weight;
	this->next = nullptr;
}
Node::~Node() {}
Node* Node::getNext() { return this->next; }
void Node::setNext(Node* next) { this->next = next; }
int Node::getValue() { return this->value; }
void Node::setValue(int value) { this->value = value; }
int Node::getWeight() { return this->weight; }
void Node::setWeight(int weight) { this->weight = weight; }