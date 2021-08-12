#include "Graph.h"

Graph::Graph() { this->n = 0; this->adjList = nullptr;}

Graph::~Graph() {
	for (int i = 0; i < n+1; i++)
	{
		delete this->adjList[i];
	}
	delete[] this->adjList;
}

int Graph::getN() { return this->n; }

int Graph::IsEmpty() { return (this->n == 0) ? 1 : 0; }

NeighborList* Graph::GetAdjList(int u) { return this->adjList[u]; }

NeighborList* Graph::Adj(int i) { return this->adjList[i]; }

void Graph::MakeEmptyGraph(int n) {
	this->adjList = new NeighborList*[n+1];
	this->n = n;
	for (int i = 0; i < n+1; i++)
	{
		this->adjList[i] = new NeighborList();
	}
}

bool Graph::IsAdjacent(int u, int v) {
	Node* head = this->adjList[u]->getHead();
	while (head != nullptr)
	{
		if (head->getValue() == v) {
			return true;
		}
		head = head->getNext();
	}
	return false;
}


void Graph::RemoveEdge(int u, int v) {
	Node* node = this->adjList[u]->getHead();
	while (node->getValue() != v)
	{
		node = node->getNext();
	}
	if (node != nullptr)
	{
		this->adjList[u]->removeNeighbor(node);
	}
}



int Graph::AddEdge(int i, int j) {
	if (i > this->n || i < 1 || j > this->n || j < 1)
	{
		return 0;
	}
	if (IsAdjacent(i, j)) {
		return 0;
	}

	Node* node = new Node(j);
	this->adjList[i]->addNeighbor(node);
	return 1;
}


Graph* Graph::Transpose() {
	Graph* transpose = new Graph();
	transpose->MakeEmptyGraph(this->n);
	for (int i = 1; i < this->n+1; i++)
	{
		Node* node = this->adjList[i]->getHead();
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
		Node* head = this->adjList[i]->getHead();
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
	ofstream myfile("Measure.txt");

	for (int i = 1; i < n + 1; i++)
	{
		Node* head = this->adjList[i]->getHead();
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
	myfile << endl;
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
		Node* node = this->adjList[u]->getHead();
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
		NeighborList* lst = this->adjList[i];
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

Graph* Graph::shortestPathsGraph(int s, int t) {
	
	int* gBFS = this->BFS(s);
	this->deleteEdgesFromBFS(gBFS);
	Graph* GST = this->Transpose();

	int* GSTBFS = GST->BFS(t);
	for (int i = 1; i < GST->getN() + 1; i++)
	{
		NeighborList* lst = GST->GetAdjList(i);
		Node* node = lst->getHead();
		while (node != nullptr)
		{
			if (GSTBFS[i] == INT_MAX)
			{
				Node* remove = node;
				node = node->getNext();
				lst->removeNeighbor(remove);
			}
			else
			{
				node = node->getNext();
			}
		}
	}
	return GST->Transpose();
}

void Graph::tellTime(int s, int t)
{
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	this->shortestPathsGraph(s, t);
	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt", ios_base::app); // The name of the file
	myfile << "Time taken by function <shortestPathsGraph> is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();

	cout << "Time taken by function <shortestPathsGraph> is : " << fixed
		<< time_taken << setprecision(9);
	cout << " sec" << endl;
}


