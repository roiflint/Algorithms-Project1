#pragma once
#include "NeighborList.h"
#include "Node.h"
#include "Queue.h"

#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <climits>

//#define INFINITE INT_MAX
using namespace std;

class Graph
{
private:
	int n;					// Number of vertices in the graph
	NeighborList** adjList;   // List of neighbors in the graph

public:

	/*Ctor*/
	Graph();

	/*Dtor*/
	~Graph();

	/*Create an empty graph with n vertices*/
	void MakeEmptyGraph(int n);

	/*Returns 1 if graph is empty, 0 otherwise*/
	int IsEmpty();

	/*Adding the edge to the graph from vertices i and j. Returns 1 if edge was added to the graph, and 0 otherwise*/
	int AddEdge(int i, int j);

	/*Returns true if edge (u,v) exists in the graph, returns false otherwise*/
	bool IsAdjacent(int u, int v);

	/*Returns list of neighbors of the vertice u*/
	NeighborList* GetAdjList(int u);

	/*Returns list of neighbors of the vertice i*/
	NeighborList* Adj(int i);

	/*Removes edge (u,v) from the graph*/
	void RemoveEdge(int u, int v);

	/*void ReadGraph();*/

	/*Print the graph into the console*/
	void PrintGraph();

	/*Print the graph into the file*/
	void PrintGraphIntoFile();

	/*Returns the tranpose graph*/
	Graph* Transpose();

	/*Runs the algorithm BFS from the vertex s, returns array of the shortest paths for each vertice in the graph */
	int* BFS(int s);

	/*Deletes each edge (u,v) from the graph after the BFS run, the met the condition of d[v] = d[u] + 1  */
	void deleteEdgesFromBFS(int* bfs);

	/*Returns amount of the vertices in the graph*/
	int getN();

	Graph* shortestPathsGraph(int s, int t);

	void tellTime(int s, int t);


};