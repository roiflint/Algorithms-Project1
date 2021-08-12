#include "Graph.h"
#include "NeighborList.h"
#include "Node.h"

#include <stdlib.h>
#include <fstream>

using namespace std;

bool  checkEdgesInput(string strJ, string strI, int size);
bool  checkStartingInput(string size, string s, string t);

int main()
{

	ifstream readMyFile; // text file to read from
	string fileName;	 

	int n, s, t;
	string strSize, strSource, strDestination;

	string strI, strJ;	 // edges of the graph
	int i = 0, j = 0;	
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
			cin >> i;
			cin >> j;
			if (i == -1 || j == -1)
			{
				isValid = false;
			}

			else
			{
				check = g->AddEdge(i, j);
			}
		}

		Graph* h = g->shortestPathsGraph(s, t);
		h->PrintGraph();
		h->PrintGraphIntoFile();*/

		cout << "Please enter the path of the file: ";
		cin >> fileName;
		cout << endl;

		readMyFile.open(fileName);
		if (!readMyFile)
		{
			cout << "ERROR with opening the file" << endl;
			exit(1);
		}

		/*Read first 3 items from the file */

		readMyFile >> strSize >> strSource >> strDestination;

		if (checkStartingInput(strSize, strSource, strDestination))
		{
			n = stoi(strSize);
			s = stoi(strSource);
			t = stoi(strDestination);

			g->MakeEmptyGraph(n);

			while (!readMyFile.eof() && isValid)
			{
				/*Reading pair of vertices to create an edge*/
				readMyFile >> strI >> strJ;

				if (checkEdgesInput(strI, strJ, n))
				{
					int i = stoi(strI);
					int j = stoi(strJ);
					g->AddEdge(i, j);
				}
				else
				{
					isValid = false;
				}
			}

			if (isValid)
			{
				Graph* timeTaken = g;			//Graph to measure the time

				Graph* H = g->shortestPathsGraph(s, t);
				H->PrintGraph();
				H->PrintGraphIntoFile();
				
				timeTaken->tellTime(s, t);	    
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
	/*If stoi fails, we'll catch the exception*/
	catch (exception&)
	{
		return false;
	}
}

bool checkStartingInput(string strSize, string strSourse, string strDestination)
{
	try
	{
		int size = stoi(strSize);
		int s = stoi(strSourse);
		int t = stoi(strDestination);

		if (size < 0 || size % 2 != 0 || s > size || s < 0 || t > size || t < 0)		
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

