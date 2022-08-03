#include <iostream>
#include <chrono>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include "TraveledPath.h"

struct comparePaths
{
	bool operator() (const TraveledPath& left, const TraveledPath& right)
	{
		return left.GetCost() > right.GetCost();
	}
};

void GetInputs(int numPoints);
void CoordStrToStruct(std::string input, int index);
void SetPath(std::string input);
void GetNeighbors(TraveledPath currentPath, std::priority_queue<TraveledPath, std::vector<TraveledPath>, comparePaths>* paths, std::vector<char> visitedNodes, int numPoints);
void DisplayEndResult(TraveledPath in, int numPoints);
char g_startPoint;
char g_endPoint;

struct MapEdge {
	char x;
	char toNode;
	int cost;
};

MapEdge* g_mapEdges;

int main()
{
	int numPoints;
	int openNodePosition = -1;
	int closedNodePosition = -1;
	std::string pathRequest;


	std::cout << "Enter number of coordinates: ";
	std::cin >> numPoints;
	//change array size to numPoints
	g_mapEdges = new MapEdge[numPoints];
	GetInputs(numPoints);
	std::cout << "Enter path request as formatted: firstPoint,secondPoint" << std::endl;
	std::cin >> pathRequest;
	SetPath(pathRequest);

	//sort array to priority queue
	std::priority_queue<TraveledPath,std::vector<TraveledPath>, comparePaths> paths;
	std::vector<char> visitedNodes;
	std::vector<char> vect(1, g_startPoint);
	paths.push(TraveledPath(vect,0));
	TraveledPath endPath = TraveledPath(visitedNodes, -999);

	do
	{
		TraveledPath current = paths.top();
		paths.pop();
		visitedNodes.push_back(current.GetNode().back());

		if (current.GetNode().back() == g_endPoint)
		{
			endPath = current;
			break;
		}
		else
		{
			std::cout << "Priority Queue before neighbors: " << std::to_string(paths.size()) << std::endl;
			GetNeighbors(current, &paths, visitedNodes, numPoints);
			std::cout << "Priority Queue after neighbors: " << std::to_string(paths.size()) << std::endl;
		}
		
	} while (!paths.empty());
	if (endPath.GetCost() == -999)
	{
		//end condition: no solution
		std::cout << "No solution was found, I am so sorry.\n";
	}
	else
	{
		DisplayEndResult(endPath, numPoints);
	}
	delete g_mapEdges;

}

void GetInputs(int numPoints)
{
	std::string coordinateString;
	std::string delimiterChar = ",";
	for (int i = 0; i < numPoints; i++)
	{
		std::cout << "Enter the first point, second point, and cost as formatted: firstPoint,secondPoint,cost" << std::endl;
		std::cin >> coordinateString;
		CoordStrToStruct(coordinateString, i);
	}
	//pass list to coord str to str
}

void CoordStrToStruct(std::string input, int index)
{
	// Take the strings from input and convert them into structs
	std::string placeHolder;
	MapEdge tempEdge;
	//Todo - pull out this logic into another function and call that
	placeHolder = input.substr(0, input.find(",", 0));
	input = input.substr(input.find(",", 0) + 1, input.length());
	tempEdge.x = placeHolder[0];

	placeHolder = input.substr(0, input.find(",", 0));
	input = input.substr(input.find(",", 0) + 1, input.length());
	tempEdge.toNode = placeHolder[0];

	tempEdge.cost = int(input[0]) - '0';

	g_mapEdges[index] = tempEdge;
}

void SetPath(std::string input)
{
	std::string placeHolder;

	placeHolder = input.substr(0, input.find(",", 0));
	input = input.substr(input.find(",", 0) + 1, input.length());
	g_startPoint = placeHolder[0];

	placeHolder = input.substr(0, input.find(",", 0));
	input = input.substr(input.find(",", 0) + 1, input.length());
	g_endPoint = placeHolder[0];
}

void GetNeighbors(TraveledPath currentPath, std::priority_queue<TraveledPath, std::vector<TraveledPath>, comparePaths>* paths, std::vector<char> visitedNodes, int numPoints)
{
	char currentNode = currentPath.GetNode().back();

	for (int i = 0; i < numPoints; i++)
	{
		MapEdge currentEdge = g_mapEdges[i];
		std::cout << "Current Edge:(" << g_mapEdges[i].x << ", " << g_mapEdges[i].toNode << ", " << g_mapEdges[i].cost << ")" << std::endl;
		if (currentEdge.x == currentNode)
		{
			std::cout << "X matches current node" << std::endl;
			std::vector<char> newPath(currentPath.GetNode());
			newPath.push_back(currentEdge.toNode);
			TraveledPath neighbor = TraveledPath(newPath, currentEdge.cost + currentPath.GetCost());
			if (std::find(visitedNodes.begin(), visitedNodes.end(), currentEdge.toNode) != visitedNodes.end())
			{
				continue;
			}
			else
			{
				paths->push(neighbor);
			}
			
		}
		else if (currentEdge.toNode == currentNode)
		{
			std::cout << "Y matches current node" << std::endl;
			std::vector<char> newPath(currentPath.GetNode());
			newPath.push_back(currentEdge.x);
			TraveledPath neighbor = TraveledPath(newPath, currentEdge.cost + currentPath.GetCost());
			if (std::find(visitedNodes.begin(), visitedNodes.end(), currentEdge.x) != visitedNodes.end())
			{
				continue;
			}
			else
			{
				paths->push(neighbor);
			}

		}
		else {
			std::cout << "Idk man, nothing matches." << std::endl;

		}
	}
	std::cout << "Priority Queue within the neightbors function" << std::to_string(paths->size()) << std::endl;
}

void DisplayEndResult(TraveledPath in, int numPoints)
{
	std::cout << "Input Map: " << std::endl;
	for (int i = 0; i < numPoints; i++)
	{
		std::cout << "(" << g_mapEdges[i].x << ", " << g_mapEdges[i].toNode << ", " << g_mapEdges[i].cost << ")" << std::endl;
	}
	std::cout << "Path recommended: ";
	std::cout << in.toString();
}