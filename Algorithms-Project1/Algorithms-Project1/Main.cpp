#include "Graph.h"
#include "NeighborList.h"
#include "Node.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Graph* shortestPathsGraph(Graph* g, int s, int t);

int main()
{
	int n;				 // number of vertices
	int s;				// starting vertex
	int t;				// destination
	int v = 0, u = 0;	// edges of the graph
	int check = 0;
	bool isValid = true;
	try
	{
		cout << "Please enter the number of vertices: " << endl;
		cin >> n;

		cout << "Please enter the the starting vertex: " << endl;
		cin >> s;

		cout << "Please enter the destination vertex: " << endl;
		cin >> t;

		Graph* g = new Graph();
		g->MakeEmptyGraph(n);

		cout << "Start entering the edges until you press enter" << endl;


		while(isValid)
		{
			cin >> v;
			cin >> u;
			if (v == -1 || u == -1)
			{
				isValid = false;
			}

			else
			{
				check = g->AddEdge(v, u); 
			}
		}

		Graph* h = shortestPathsGraph(g, s, t);
		h->PrintGraph();

	}
	catch(exception)
	{
		cout << "invalid input" << endl;
		exit(1);
	}



}

Graph* shortestPathsGraph(Graph* g, int s, int t) {
	
	int* gBFS = g->BFS(s);
	g->deleteEdgesFromBFS(gBFS);
	Graph* GST = g->Transpose();
	int* GSTBFS = GST->BFS(t);
	for (int i = 1; i < GST->getN() + 1; i++)
	{
		NeighborList* lst = GST->GetAdjList(i);
		Node* node = lst->getHead();
		while (node != nullptr)
		{
			if (GSTBFS[node->getValue()] == INT_MAX)
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

	return GST->Transpose();

}
