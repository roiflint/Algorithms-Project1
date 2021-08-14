/*

Current program receives the vertices from the file or from stdin as edges of the graph, and returns the sub graph 
that has all of the shortest paths of the original graph from the chosen vertice S (source) to vertice T (destination)
and this graph contains ONLY the edges from those paths

***********Data Structures***********
Linked List 
Queue
Graph (represented by array of Adjacent Lists)


***********Implementation of the program*********** 

1. Choose if you want to input vertices from stdin or from the file (1 for stdin, 2 for reading from file)
2. If you choose option 1, than:
	2.1. Insert amount of vertices 
	2.2  Insert the source and destination vertices
	2.3  Enter all of the edges
	2.4  To end the input, enter -1

3. If you choose option 2, enter the file path.

*/


#include "Graph.h"
#include "NeighborList.h"
#include "Node.h"

/*Checks the input from the stdin*/
bool checkInput(int v1, int v2, int size);
bool checkStartingInputs(int size, int s, int t);

int main()
{
	int n, s, t;
	int i = 0, j = 0;	
	int count = 0;	// Saves the number or vertices for the edges
	bool isValid = true;

	Graph* g = new Graph();
	try
	{
		cout << "To insert graph through keyboard press 1, to insert graph through file press 2: ";
		int option;
		cin >> option;
		if (option != 1)
		{
			g->ReadGraph();
		}
		else {
			///***************STDIN INPUT***************/

			cout << "Please enter the number of vertices: " << endl;
			cin >> n;

			cout << "Please enter the the starting vertex: " << endl;
			cin >> s;

			cout << "Please enter the destination vertex: " << endl;
			cin >> t;

			g->MakeEmptyGraph(n);
			g->setS(s);
			g->setT(t);

			cout << "Start entering the edges until you enter -1" << endl;

			if (checkStartingInputs(n, s, t))
			{

				while (!cin.eof())
				{
					cin >> i;
					if (i == EOF)
					{
						break;
					}
					count++;

					cin >> j;
					if (j == EOF)
					{
						break;
					}
					count++;

					if (checkInput(i, j, n))
					{
						g->AddEdge(i, j);
					}
					else
					{
						cout << "invalid input" << endl;
						exit(1);
					}
				}
			}
			else
			{
				cout << "invalid input" << endl;
				exit(1);
			}
		}

		if (count % 2 != 0)
		{
			cout << "invalid input" << endl;
			exit(1);
		}

		Graph* timeTaken = g;
		Graph* h = g->shortestPathsGraph(g->getS(), g->getT());
		h->PrintGraph();
		timeTaken->tellTime(g->getS(), g->getT());
		}

		catch (exception&)
		{
			cout << "invalid input" << endl;
			exit(1);
		}

}


bool checkInput(int v1, int v2, int size)
{
	if (v1 > size || v1 < 0 || v2 < 0 || v2 > size)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool checkStartingInputs(int size, int s, int t)
{
	if (size <= 0 || s > size || s < 0 || t > size || t < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}


