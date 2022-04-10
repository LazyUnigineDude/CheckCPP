#pragma once
#include <iostream>
#include <vector>
#include <map>


//	 0		1		2    3		4	5
//		{ 2,1 }{0}	  {0,3}	{2}	   {5} {4}
//
//						
/*
			0
		  /   \
		1		2 ---- 3      4---5
*/


class NaiveGraphCheck
{
public:
	int EDGE_COUNT(std::vector <std::vector<int>> M) {
		int count = 0;
		std::map<int, bool> visited;

		for (int i = 0; i < M.size(); i++)
		{
			if (!visited[i]) { visited[i] = true; }

			for (auto& j : M[i]) {

				if (!visited[j]) {
					visited[j] = true;
					count++;
				}
			}

		}
		return count;
	}

	int GRAPH_COUNT(std::vector <std::vector<int>> M) {
		int count = 0;
		std::map<int, bool> visited;

		for (int i = 0; i < M.size(); i++)
		{
			if (!visited[i]) { visited[i] = true; count++; }

			for (auto& j : M[i]) {

				if (!visited[j]) {
					visited[j] = true;
				}
			}

		}
		return count;
	}

	void GraphCheck() {

		std::vector<std::vector<int>> M;
		M = { {2,1}, {0}, {0,3}, {2} , {5}, {4} };
		std::cout << M.size() << "\n";
		std::cout << EDGE_COUNT(M) << "\n";
		std::cout << GRAPH_COUNT(M) << "\n";

	}

};

