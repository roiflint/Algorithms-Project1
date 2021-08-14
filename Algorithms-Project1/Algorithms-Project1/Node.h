#pragma once

/*Implementation of node class for the linked list*/

class Node {
private:
	int value;
	Node* next;

public:

	/*Ctor & Dtor*/
	Node(int value);
	~Node();

	/*Set the value of the node*/
	void setValue(int value);

	/*Return the value of the node*/
	int getValue();

	/*Get the next node*/
	Node* getNext();

	/*Set the next node*/
	void setNext(Node* next);
};
