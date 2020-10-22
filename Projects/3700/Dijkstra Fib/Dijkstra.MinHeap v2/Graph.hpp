#pragma once
#include "MinHeap.hpp"
#include <list>
#include <vector>
#include <random>

constexpr auto V = 100;

typedef pair<int, int> Pair;

class Graph {

	list< pair<int, int> >* adj;

public:
	
    Graph();
	~Graph();


	list< pair<int, int> >* getAdj() { return adj; };
    void addEdge(int u, int v, int cost);

};