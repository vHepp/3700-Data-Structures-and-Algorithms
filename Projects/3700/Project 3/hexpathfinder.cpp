// Hex Pathfinder.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <stack.h>
#include "DisjointSet.h"
#include "hexpathfinder.h"
#include "Sampler.h"


using namespace std;

int c, r, neighborR, neighborC;



int32_t
// delta Column
dC[] = { 0,1,1,0,-1,-1 },
//delta Row Even
dReven[] = { -1,-1,0,1,0,-1 },
//delta Row Odd
dRodd[] = { -1,0,1,1,1,0 },
wallMasks[] = { 1, 2, 4, 8, 16, 32 };

int32_t
nR, nC, * dR;

uint8_t maze[MAX_ROWS][MAX_COLS];


// This is Algorithm 5, and utilizes backtracking to determine the correct path. If it reaches a deadend, it will until it reaches the last decision point.
void findPath() {

	Stack<uint32_t> S;


	S.push(encode(0, 0, 0));
	maze[0][0] = maze[0][0] | (VISITED);


	while (true)
	{
		uint32_t r, c, d;
		decode(S.peek(), r, c, d);
		if (r == nR - 1 && c == nC - 1)
			break;

		if (d == 6)
		{
			maze[r][c] = maze[r][c] | (DEAD_END);
			S.pop();
		}

		else
		{
			uint32_t rPrime, cPrime;

			if (c & 1)
				dR = dRodd;
			else
				dR = dReven;

			rPrime = r + dR[d];
			cPrime = c + dC[d];

			S.pop();
			S.push(encode(r, c, d + 1));

			if ((maze[r][c] & wallMasks[d]) == 0 && (maze[rPrime][cPrime] & VISITED) == 0)
			{
				S.push(encode(rPrime, cPrime, 0));
				maze[rPrime][cPrime] = maze[rPrime][cPrime] | (VISITED);
			}
		}
	}
}

//Encodes r, c & d into a single uint32_t, and returns it
uint32_t encode(uint32_t r, uint32_t c, uint32_t d)
{
	return c + nC * (r + nR * d);
}

// Decodes e into variables r, c, and d.
void decode(uint32_t e, uint32_t& r, uint32_t& c, uint32_t& d)
{
	c = e % nC;
	e /= nC;
	r = e % nR;
	d = e / nR;
}

//Removes a cell wall in the given direction.
void removeWall(int32_t r, int32_t c, int32_t d)
{
	maze[r][c] &= ~(1u << d);
}

// Algorithm 4, generates the maze utilizing a 2D array.
// Utilizes the Sampler.getSample, decode, encode, DisjointSet.join, DisjointSet.find, and removeWall functions
void GenerateMaze() {

	// Generates a map of hexagons with nR rows and nC columns
	for (int i = 0; i < nR; i++) {
		for (int j = 0; j < nC; j++) {
			maze[i][j] = 63;   //0b00111111; marks all six walls present
		}
	}

	int x = nR * nC;
	int y = 3 * x;
	DisjointSet ds(x);
	Sampler sampler(y);


	uint32_t
		i = 0,
		r1, c1, d1, r2, c2,
		cell1, cell2,
		e;

	// This while loop removes the walls to create the maze from the original map.
	while (i < ((nR * nC) - 1))
	{
		do
		{
			do
			{
				e = sampler.getSample();
				decode(e, r1, c1, d1);

				if (c1 & 1u)
					dR = dRodd;
				else
					dR = dReven;

				r2 = r1 + dR[d1];
				c2 = c1 + dC[d1];
			} while (r2 < 0 || r2 >= nR || c2 < 0 || c2 >= nC);

			cell1 = encode(r1, c1, 0);
			cell2 = encode(r2, c2, 0);

		} while (ds.find(cell1) == ds.find(cell2));

		ds.join(cell1, cell2);
		i++;


		//Remove wall between (r1,c1) and (r2,c2)
		int d2 = (d1 + 3) % 6;
		removeWall(r1, c1, d1);
		removeWall(r2, c2, d2);

	}
}

// This is the main function
// Takes in the command line input and runs the GenerateMaze, findPath, and printMaze functions
int main(int argc, char* argv[])
{

	if (argc != 3)
	{
		std::cout << "Usage: " << argv[0] << " nRows nColumns" << std::endl;
		return 1;
	}

	//converts c-string into integer. argv[i] is the input. argv[1] is the number of rows, [2] is the number of columns
	nR = atoi(argv[1]);
	nC = atoi(argv[2]);



	GenerateMaze();
	findPath();
	printMaze(maze, nR, nC);

	return 0;
}