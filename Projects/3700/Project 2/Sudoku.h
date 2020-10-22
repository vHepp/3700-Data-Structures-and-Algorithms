#ifndef _SUDOKU_H
#define _SUDOKU_H

#include <iostream>
#include <bitset>
#include "Stack.h"

using namespace std;

class Sudoku {
	
public:
	Sudoku(char [9][9]);
	~Sudoku(void);
	
	void Solve(uint16_t board [9][9]);
	bool FindBest(uint16_t board [9][9]);
	
	bool isFilled(uint16_t);
	bool isValid(uint16_t, uint16_t);
	void markInvalid(uint16_t &, uint16_t);
	
	int  getLocation(int, int);
	int  getRow(int k) { return k / 9; }
	int  getCol(int k) { return k % 9; }
	
	int  findBox(uint16_t,uint16_t);
	
	void showBits(uint16_t);
	int  countBits(uint16_t);
	int nextValid(uint16_t &);
	
	
	void printSudoku(uint16_t [9][9]);
	
	uint16_t board [9][9];
	Stack <uint16_t> cells;
	
};

#endif
