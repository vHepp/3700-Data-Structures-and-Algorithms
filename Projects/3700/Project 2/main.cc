#include "Sudoku.h"

void printSudoku(char puzzle [9][9]);

int main(){
	
	char charList [9][9];
	
	Sudoku puzzle(charList);
	
	/*
	for (int row = 0; row < 9; row++){
		for (int col = 0; col < 9; col++){
			if ((puzzle.isFilled(puzzle.board[row][col])))
			{
				//One for-loop to mark all invalid guesses
				for (int i = 0; i < 9; i++)
				{
					if (!(puzzle.isFilled(puzzle.board[row][col]))) 
						puzzle.markInvalid(puzzle.board[row][i], puzzle.board[row][col]);
					if (!(puzzle.isFilled(puzzle.board[row][col]))) 
						puzzle.markInvalid(puzzle.board[i][col], puzzle.board[row][col]);
				}
				
				//Loop for 3x3 box
				int cellBox = puzzle.findBox(row, col);
				for (int r = 0; r < 9; r++){
					for (int c = 0; c < 9; c++){
						if (puzzle.findBox(r, c) == cellBox)
							puzzle.markInvalid(puzzle.board[r][c], puzzle.board[row][col]);
					}
				}
			}
		}
	}
	
	for (int row = 0; row < 9; row++)
	{
		cout << "row " << row << ":" << endl;
		for (int col = 0; col < 9; col++)
		{
			cout << "\t";
			puzzle.showBits(puzzle.board[row][col]);
			cout << "\t";
			cout << puzzle.countBits(puzzle.board[row][col]) << endl;
		}
		cout << endl;
	}
	
	cout << "cells: " << endl;	
	puzzle.FindBest(puzzle.board);
	cout << "row: " << puzzle.getRow(puzzle.cells.peek());
	cout << " col: " << puzzle.getCol(puzzle.cells.peek()) << endl;
	 */
	
	
	puzzle.Solve(puzzle.board);
	
	return 0;
}

