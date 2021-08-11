#include "Graph.h"
#include "NeighborList.h"
#include "Node.h"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

Graph* shortestPathsGraph(Graph* g, int s, int t);
bool   checkEdgesInput(string strU, string strV, int size);
bool   checkStartingInput(string size, string source, string destination);
void   tellTime(Graph* g, int s, int t);

int main()
{
	int n;				 // number of vertices
	int s;				// starting vertex
	int t;				// destination
	int v = 0, u = 0;	// edges of the graph
	int check = 0;
	bool isValid = true;

	Graph* g = new Graph();
	try
	{
		/*cout << "Please enter the number of vertices: " << endl;
		cin >> n;

		cout << "Please enter the the starting vertex: " << endl;
		cin >> s;

		cout << "Please enter the destination vertex: " << endl;
		cin >> t;

		g->MakeEmptyGraph(n);

		cout << "Start entering the edges until you press enter" << endl;


		while (isValid)
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
		h->PrintGraph();*/

		ifstream readMyFile;
		ofstream writeMyFile;

		readMyFile.open("C:\\Users\\rotan\\Desktop\\test_data2.txt");
		if (!readMyFile)
		{
			cout << "invalid" << endl;
			exit(1);
		}

		/*Read first 3 items from the file */

		int sizeOfAnArray = 0;
		int source = 0;
		int destination = 0;

		string strSize, strSource, strDestination;
	
		readMyFile >> strSize >> strSource >> strDestination;

		if (checkStartingInput(strSize, strSource, strDestination))
		{
			sizeOfAnArray = stoi(strSize);
			source = stoi(strSource);
			destination = stoi(strDestination);


			g->MakeEmptyGraph(sizeOfAnArray);

			while (!readMyFile.eof() && isValid)
			{
				/*Reading pair of vertices to create an edge*/
				string strU, strV;
				readMyFile >> strV >> strU;

				if (checkEdgesInput(strV, strU, sizeOfAnArray))
				{
					int v = stoi(strV);
					int u = stoi(strU);
					g->AddEdge(v, u);
				}
				else
				{
					isValid = false;
				}
			}

			if (isValid)
			{
				Graph* timeComplex = g;
				/*timeComplex->setGraph(g->getGraph());*/

				Graph* H = shortestPathsGraph(g, source, destination);
				H->PrintGraph();
				H->PrintGraphIntoFile();
				
				tellTime(timeComplex, source, destination);
			}
			else
			{
				cout << "invalid input" << endl;
			}
		}
		else
		{
			cout << "invalid input" << endl;
		}
	
	}
	catch(exception&)
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


bool checkEdgesInput(string strV1, string strV2, int size)
{
	try
	{
		int v1 = stoi(strV1);
		int v2 = stoi(strV2);

		if (v1 > size || v1 < 0 || v2 < 0 || v2 > size)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	catch (exception&)
	{
		return false;
	}
}

bool checkStartingInput(string strSize, string strSourse, string strDestination)
{
	try {
		int size = stoi(strSize);
		int source = stoi(strSourse);
		int destination = stoi(strDestination);

		if (size < 0 || size % 2 != 0 || source > size || source < 0 || destination > size || destination < 0)		
		{
			return false;
		}
		else
		{
			return true;
		}

	}
	/*If stoi fails, we'll catch the exception*/
	catch (exception&)
	{
		return false;
	}
}

void tellTime(Graph* g, int s, int t)
{

	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	shortestPathsGraph(g, s, t);// Here you put the name of the function you wish to measure
	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt"); // The name of the file
	myfile << "Time taken by function <shortestPathsGraph> is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
}
