#include "TraveledPath.h"
#include <vector>
TraveledPath::TraveledPath(std::vector<char> node, int cost) 
{
	m_node = node;
	m_cost = cost;
}
std::string TraveledPath::toString()
{
	std::string showPath = "";
	showPath += "Path:";
	for (char i : m_node) showPath +=  i;
	showPath += " Cost:";
	showPath += std::to_string(m_cost);
	showPath += "\n";
	return showPath;
	
}