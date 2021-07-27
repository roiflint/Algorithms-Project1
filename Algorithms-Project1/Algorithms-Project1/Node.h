#pragma once

class Node {
private:
	int value;
	int weight;
	Node* next;

public:
	Node(int value, int weight);
	~Node();
	void setValue(int value);
	int getValue();
	Node* getNext();
	void setNext(Node* next);
	int getWeight();
	void setWeight(int weight);
};
