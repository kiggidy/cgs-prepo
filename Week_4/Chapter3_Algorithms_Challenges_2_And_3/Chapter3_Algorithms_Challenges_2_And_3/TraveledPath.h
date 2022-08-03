#pragma once
#include <vector>
#include <string>

class TraveledPath
{
	public:
		TraveledPath() 
		{
		
		};
		
		TraveledPath(std::vector<char> node, int cost);
		
		int GetCost() const 
		{
			return m_cost;
		}
		std::vector<char> GetNode() const
		{
			return m_node;
		}
		std::string toString();
	private:	
		std::vector<char> m_node;
		int m_cost = 0;
};

