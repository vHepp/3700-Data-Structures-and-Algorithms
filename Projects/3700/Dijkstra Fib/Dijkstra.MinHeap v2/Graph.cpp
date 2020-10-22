#include "Graph.hpp"


Graph::Graph() {

	adj = new list<Pair>[V];
}

Graph::~Graph() { }

void Graph::addEdge(int u, int v, int cost) {
	adj[u].push_back(make_pair(v, cost));
	adj[v].push_back(make_pair(u, cost));
}