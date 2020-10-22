#include "DisjointSet.h"
#include <iostream>

using namespace std;

DisjointSet::DisjointSet(uint32_t n)
{
	elements = new uint32_t[n];
	rank = new uint32_t[n];


	for (uint32_t i = 0; i < n; i++)
	{
		elements[i] = i;
		rank[i] = 0;
	}
}

DisjointSet::~DisjointSet()
{
	delete[] rank;
	delete[] elements;
}

int DisjointSet::find(uint32_t a)
{

	if (elements[a] != a)
		elements[a] = find(elements[a]);
	return elements[a];

}

void DisjointSet::join(int32_t a, int32_t b)
{
	a = find(a);
	b = find(b);


	if (a != b)
		if (rank[a] < rank[b])
			elements[a] = b;
		else
		{
			if (rank[a] == rank[b])
				rank[a] = rank[a] + 1;
			elements[b] = a;
		}
}