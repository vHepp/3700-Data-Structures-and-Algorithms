#pragma once
#include <cstdint>

class DisjointSet {

public:


	explicit DisjointSet(uint32_t n);

	~DisjointSet();

	int find(uint32_t a);

	void join(int32_t a, int32_t b);



private:

	uint32_t
		* elements, * rank;
};