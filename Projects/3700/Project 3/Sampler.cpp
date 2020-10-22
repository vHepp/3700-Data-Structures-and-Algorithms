#include <fstream>
#include <iostream>
#include "Sampler.h"


using namespace std;

// Creates an array of n integers. Sets array[i] = i for all slots. Stores n in a class variable.
Sampler::Sampler(uint32_t n) {

	items = new uint32_t[n];
	nItems = n;


	for (uint32_t i = 0; i < n; i++)
		items[i] = i;


	rd = new random_device();
	mt = new mt19937((*rd)());
}

// Deletes the array
Sampler::~Sampler()
{
	delete[] items;
}


// Returns one element from the array using Algorithm 1
uint32_t Sampler::getSample()
{
	uint32_t
		rand,
		randomElement;
	uniform_int_distribution<>
		dis(0, nItems - 1);

	rand = (uint32_t)dis(*mt);

	randomElement = items[rand];

	nItems--;

	items[rand] = items[nItems];

	return randomElement;
}