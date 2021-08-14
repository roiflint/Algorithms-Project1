#pragma once
#include "NeighborList.h"
#include "Node.h"
#include "Queue.h"

#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <climits>

#define INFINITE INT_MAX
using namespace std;

class Graph
{
private:
	int n;					  // Number of vertices in the graph
	NeighborList** adjList;   // List of neighbors in the graph
	int s;
	int t;

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

	/*Read graph from the text file*/
	void ReadGraph();

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


	/*The main function - implements the algortihm that returns the graph of the shortest paths*/
	Graph* shortestPathsGraph(int s, int t);

	/*Helper function of the algorihms that deletes all of the inaccessible edges from the graph*/
	void deleteInaccessibleEdges(Graph* GST, int* GSTBFS);

	/*Tells the time it takes*/
	void tellTime(int s, int t);

	/*Setters for source and destination vertices*/
	void setS(int s);
	void setT(int t);

	/*Getters for source and destination vertices*/
	int getT();
	int getS();

	/*Checks the input of the amount of vertices, source vertix and destination while reading graph from file*/
	bool checkInput(string strSize, string strSourse, string strDestination);

	/*Checks the the input of two vertices while reading graph from while, before adding them as edge*/
	bool checkEdges(string strV1, string strV2, int size);
};