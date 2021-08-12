#include "Graph.h"
#include "NeighborList.h"
#include "Node.h"
#include <string>

using namespace std;

bool checkEdgesInput(string strJ, string strI, int size);
bool checkStartingInput(string size, string s, string t);
bool checkInput(int v1, int v2, int size);
bool checkStartingInputs(int size, int s, int t);

int main()
{
	int n, s, t;

	int i = 0, j = 0;	
	bool isValid = true;

	Graph* g = new Graph();
	try
	{
		cout << "To insert graph through keyboard press 1, to insert graph through file press 2" << endl;
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
			/*cout << "Start entering the edges until you enter -1" << endl;*/

			if (checkStartingInputs(n, s, t))
			{

				while (!cin.eof())
				{
					cin >> i;
					if (i == EOF)
					{
						break;
					}

					cin >> j;
					if (j == EOF)
					{
						break;
					}

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
			Graph* timeTaken = g;
			Graph* h = g->shortestPathsGraph(g->getS(), g->getT());
			h->PrintGraph();
			/*h->PrintGraphIntoFile();*/
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
	if (size < 0 || size % 2 != 0 || s > size || s < 0 || t > size || t < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}


