#pragma once
#include "NeighborList.h"
class Graph
{
private:
	int n;
	NeighborList** graph;

public:
	Graph();
	~Graph();
	void MakeEmptyGraph(int n);
	bool IsAdjacent(int u, int v);
	NeighborList* GetAdjList(int u);
	void RemoveEdge(int u, int v);
	/*void ReadGraph();*/
	void PrintGraph();
	int IsEmpty();
	int AddEdge(int i, int j);
	NeighborList* Adj(int i);
	Graph* Transpose();
	int* BFS(int s);
	int getN();
	void deleteEdgesFromBFS(int* bfs);
};