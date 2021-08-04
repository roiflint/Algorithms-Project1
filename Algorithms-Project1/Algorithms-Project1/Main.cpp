#include "Graph.h"
#include "NeighborList.h"
#include "Node.h"
#include <iostream>
using namespace std;


int main() {

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
