#include <iostream>
#include <chrono>
#include <string>


using namespace std;
void GetInputs(int numPoints);
void CoordStrToStruct(string input);
void SetPath(string input);
char g_startPoint;
char g_endPoint;

struct MapEdge {
	char x;
	char y;
	int cost;
};

MapEdge* g_mapEdges;

int main()
{
	int numPoints;
	int openNodePosition = -1;
	int closedNodePosition = -1;
	string pathRequest;


	cout << "Enter number of coordinates: ";
	cin >> numPoints;
	//change array size to numPoints
	g_mapEdges = new MapEdge[numPoints];
	GetInputs(numPoints);
	cout << "Enter path request as formatted: firstPoint,secondPoint";
	cin >> pathRequest;
	SetPath(pathRequest);

	//sort array to priority queue

	// A* against pathRequest
	char* openNodes = new char[numPoints];
	char* closedNodes = new char[numPoints];
	openNodes[0] = g_startPoint; //Add starting point to open nodes list

	do
	{
		/*
			add nodePath, totalCost->PREV_placeholder
			if placeholder < PREV_PLACEHOLDER
			{
				pushfront
			}
			else
			{
				continue
			}
		*/
	} while (openNodePosition >= 0);

}


//Need a priority queue : it helps in picking the lowest cost edge
/*
bool operator ()(const priorityQueueItem& left, const PriorityQueueItem& right)
{
	return left.cost > right.cost;
}
*/



void GetInputs(int numPoints)
{
	string coordinateString;
	string delimiterChar = ",";
	for (int i = 0; i < numPoints; i++)
	{
		cout << "Enter the first point, second point, and cost as formatted: firstPoint,secondPoint,cost" << endl;
		cin >> coordinateString;
		CoordStrToStruct(coordinateString, i);
		cout << "You have " << numPoints - i << " points left to enter." << endl;
	}
	//pass list to coord str to str
}

void CoordStrToStruct(string input, int index)
{
	// Take the strings from input and convert them into structs
	string placeHolder;
	MapEdge tempEdge = new MapEdge;
	//Todo - pull out this logic into another function and call that
	placeHolder = input.substr(0, input.find(",", 0));
	input = input.substr(input.find(",", 0) + 1, input.length());
	tempEdge.x = placeHolder[0];

	placeHolder = input.substr(0, input.find(",", 0));
	input = input.substr(input.find(",", 0) + 1, input.length());
	tempEdge.y = placeHolder[0];

	tempEdge.cost = (int)input[0];

	g_mapEdges[index] = tempEdge;
}

void SetPath(string input)
{
	string placeHolder;

	placeHolder = input.substr(0, input.find(",", 0));
	input = input.substr(input.find(",", 0) + 1, input.length());
	g_startPoint = placeHolder[0];

	placeHolder = input.substr(0, input.find(",", 0));
	input = input.substr(input.find(",", 0) + 1, input.length());
	g_endPoint = placeHolder[0];
}