#include "Graph.h"
#include "NeighborList.h"
#include "Node.h"
#include <iostream>
using namespace std;

Graph::Graph() { this->n = 0; this->graph = nullptr;}

Graph::~Graph() {
	for (int i = 0; i < n+1; i++)
	{
		delete this->graph[i];
	}
	delete[] this->graph;
}

void Graph::MakeEmptyGraph(int n) {
	*this->graph = new NeighborList[n+1];
	for (int i = 0; i < n+1; i++)
	{
		this->graph[i] = new NeighborList();
	}
}

bool Graph::IsAdjacent(int u, int v) {
	Node* head = this->graph[u]->getHead();
	while (head != nullptr)
	{
		if (head->getValue() == v) {
			return true;
		}
		head = head->getNext();
	}
	return false;
}

NeighborList* Graph::GetAdjList(int u) {return this->graph[u];}

void Graph::RemoveEdge(int u, int v) {
	Node* node = this->graph[u]->getHead();
	while (node->getValue() != v)
	{
		node = node->getNext();
	}
	if (node != nullptr)
	{
		this->graph[u]->removeNeighbor(node);
	}
}

int Graph::IsEmpty() { return (this->n == 0) ? 1 : 0; }

int Graph::AddEdge(int i, int j) {
	if (i > this->n-1 || i < 1 || j || j > this->n-1 || j < 0)
	{
		return 0;
	}
	if (IsAdjacent(i, j)) {
		return 0;
	}

	Node* node = new Node(j);
	this->graph[i]->addNeighbor(node);
	return 1;
}

NeighborList* Graph::Adj(int i) { return this->graph[i]; }

Graph* Graph::Transpose() {
	Graph* transpose = new Graph();
	transpose->MakeEmptyGraph(this->n);
	for (int i = 1; i < this->n+1; i++)
	{
		Node* node = this->graph[i]->getHead();
		while (node != nullptr)
		{
			transpose->AddEdge(node->getValue(), i);
		}
	}
	return transpose;
}

void Graph::PrintGraph() {
	for (int i = 1; i < n+1; i++)
	{
		Node* head = this->graph[i]->getHead();
		while (head != nullptr)
		{
			cout << "(" << i << "," << head->getValue() << ") ";
			head = head->getNext();
		}
	}
}



