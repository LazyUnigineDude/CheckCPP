#pragma once

#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>

typedef std::map<std::string, std::set<std::string>> ADJ_LIST;

struct GraphPoint {
	ADJ_LIST LIST;
	bool isVisited;
	GraphPoint() {}
	GraphPoint(ADJ_LIST& L, bool& V) : LIST(L), isVisited(V) {}
};


void DFS_Check(const GraphPoint& G, std::string _Start) {
	std::stack<std::string> _DFS;
	_DFS.push(_Start);
	std::string s = "";

	while (!_DFS.empty()) {
		std::string _s = _DFS.top();
		s += _s;
		_DFS.pop();

		for (auto& i : G.LIST.at(_s)) {
			_DFS.push(i);
		}
	}

	std::cout << s << "\n";
}

void BFS_Check(const GraphPoint& G, std::string _Start) {
	std::queue<std::string> _BFS;
	_BFS.push(_Start);
	std::string s = "";

	while (!_BFS.empty()) {
		std::string _s = _BFS.front();
		s += _s;
		_BFS.pop();

		for (auto& i : G.LIST.at(_s)) {
			_BFS.push(i);
		}
	}

	std::cout << s << "\n";


}

class GraphTraversalCheck
{

public:

	ADJ_LIST List = { {"a",{"b","c"}},{"b",{"d"}},{"c",{"e"}},{"d",{"f"}},{"e",{}},{"f",{}} };
	GraphPoint G;

	void MainProg() {
		G.LIST = List;
		G.isVisited = false;


		DFS_Check(G, "a");
		BFS_Check(G, "a");
	}

};

