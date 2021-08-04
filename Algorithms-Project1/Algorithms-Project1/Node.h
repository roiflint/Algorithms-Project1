#pragma once

class Node {
private:
	int value;
	Node* next;

public:
	Node(int value);
	~Node();
	void setValue(int value);
	int getValue();
	Node* getNext();
	void setNext(Node* next);
};
