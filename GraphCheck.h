#pragma once

#include <list>
#include <vector>
#include <array>
#include <iostream>
#include <set>
#include <map>


struct Edges {
	int* First;
	int* Second;
	int Weight;
};


struct Graph {
	std::list<int> Vertex;
	std::vector<Edges> Edges;
};

typedef std::vector<std::pair<int, int>> EDGES;
typedef std::vector<std::set<int>> ADJ_E;
typedef std::map<const  int, std::set<int>> MAP_E;

struct I_Graph {
	std::vector<int> Vertex;
	EDGES Edges;

	I_Graph() {}
	I_Graph(const std::vector<int>& v, EDGES& e) : Vertex(v), Edges(e) {}
};

struct ADJGRAPH {
	std::vector<int> Vertex;
	ADJ_E Edges;

	ADJGRAPH() {}
	ADJGRAPH(const std::vector<int> V, ADJ_E& E) : Vertex(V), Edges(E) {}

};

struct MAPGRAPH {
	MAP_E& Edges;
	MAPGRAPH(MAP_E& E) : Edges(E) {}
};


class GraphCheck
{

private: 
	std::array<int, 15> y;
	int Enums;

public:
	GraphCheck() {
		y = { 1,3,4, 1,2,3, 0,1,2, 0,3,1, 4,2,5 };
		Enums = y.max_size() / 3;
	}

	void CheckGraph(){
		for (int i = 0; i < Enums; i++)
		{
			Edges E;
			E.First = &y[i * 3];
			E.Second = &y[(i * 3) + 1];
			E.Weight = y[(i * 3) + 2];


			std::cout << "First Vertex: " << *E.First << "    Second Vertex: " << *E.Second << "  Weight: " << E.Weight << "\n";
		}

		std::vector<int> V = { 0,1,2,3 };
		EDGES E = { {0,1},{1,2},{2,3},{3,0} };

		I_Graph G(V, E);

		std::vector<std::set<int>> ADJV = { {1,2},{0,2,3,4},{0,1,3},{1,2,4} };

		ADJGRAPH ADJ_G(V, ADJV);

		MAP_E Edges = { {0, {1,2}}, {1,{0,2,3,4}}, {2,{0,1,3}}, {3,{1,2,4}} };

		MAPGRAPH MAP_G(Edges);


	}





};

