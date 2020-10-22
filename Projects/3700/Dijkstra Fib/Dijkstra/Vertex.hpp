#pragma once
#include <time.h>
#include <random>
#include <iostream>

using namespace std;

constexpr auto V = 9;

class Vertex {
	
public:
	Vertex();
	~Vertex();

	int32_t getRandom(int32_t,int32_t);
	void randomize(int32_t[V][V]);

	void findBest(Vertex [], Vertex &, int32_t&);

	int getCost() { return cost; };
	bool getSelected() { return selected; };
	Vertex * getParent() { return parent; };
	int32_t getIndex() { return ind; };

	void setCost(int32_t x ) { cost = x; };
	void setSelected(bool x) { selected = x; };
	void setParent(Vertex *x) { parent = x; };

	void setIndex(int32_t x) { ind = x; };


private:
	Vertex
		*parent;
	int32_t
		cost,
		ind;
	bool
		selected;
};