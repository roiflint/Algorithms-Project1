#include "Graph.h"
#include "NeighborList.h"
#include "Node.h"
#include "Queue.h"
#include <iostream>
#include <fstream>
using namespace std;

Graph::Graph() { this->n = 0; this->graph = nullptr;}

Graph::~Graph() {
	for (int i = 0; i < n+1; i++)
	{
		delete this->graph[i];
	}
	delete[] this->graph;
}

int Graph::getN() { return this->n; }

void Graph::MakeEmptyGraph(int n) {
	this->graph = new NeighborList*[n+1];
	this->n = n;
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
	if (i > this->n || i < 1 || j > this->n || j < 1)
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
			node = node->getNext();
		}
	}
	return transpose;

}

void Graph::PrintGraph() {
	for (int i = 1; i < n+1; i++)
	{
		Node* head = this->graph[i]->getHead();
		if (head != nullptr)
		{
			cout << i << ": ";
			while (head != nullptr)
			{
				cout << "(" << i << "," << head->getValue() << ") ";
				head = head->getNext();
			}
			cout << endl;
		}
	}
	cout << endl;
}

void Graph::PrintGraphIntoFile()
{
	ofstream myfile("Output.txt");

	for (int i = 1; i < n + 1; i++)
	{
		Node* head = this->graph[i]->getHead();
		if (head != nullptr)
		{
			myfile << i << ": ";
			while (head != nullptr)
			{
				myfile << "(" << i << "," << head->getValue() << ") ";
				head = head->getNext();
			}
			myfile << endl;
		}
	}

}

int* Graph::BFS(int s) {
	int* arr = new int[this->n + 1];
	for (int i = 1; i < this->n+1; i++){
		arr[i] = INT_MAX;
	}
	Queue* q = new Queue();
	q->EnQueue(s);
	arr[s] = 0;

	while (!q->IsEmpty()) {
		int u = q->DeQueue();
		Node* node = this->graph[u]->getHead();
		while (node != nullptr)
		{
			if (arr[node->getValue()] == INT_MAX) { //arr[v] = infinity
				arr[node->getValue()] = arr[u] + 1; 
				q->EnQueue(node->getValue());
			}
			node = node->getNext();
		}
	}
	return arr;
}

void Graph::deleteEdgesFromBFS(int* bfs) {
	for (int i = 1; i < this->n + 1; i++)
	{
		NeighborList* lst = this->graph[i];
		Node* node = lst->getHead();
		while (node != nullptr)
		{
			if (bfs[node->getValue()] != bfs[i] + 1)
			{
				Node* remove = node;
				node = node->getNext();
				lst->removeNeighbor(remove);
			}
			else {
				node = node->getNext();
			}
		}
	}
}


