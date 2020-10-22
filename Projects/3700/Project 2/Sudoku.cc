#include "Sudoku.h"

const uint16_t 
	VALUE_MASK = 0x000f,    //0000 0000   0000 1111
	VALID_MASK = 0x1ff0,    //0001 1111   1111 0000
	IS_FILLED_IN = 0x8000,  //1000 0000   0000 0000
	IS_0_VALID = 0x2000;    //0010 0000   0000 0000

Sudoku::Sudoku(char charList [9][9]) {
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			char temp;
			cin >> temp;
			charList[row][col] = temp;
		}
	}
	
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			if (charList [row][col] != '.')
			{
				board[row][col] = charList[row][col] & VALUE_MASK;
				board[row][col] = board[row][col] | IS_FILLED_IN;
				
			}
			else
				board[row][col] = VALID_MASK;
		}
	}
} //Constructor

Sudoku::~Sudoku(void) {} //Deconstructor

void Sudoku::Solve(uint16_t board [9][9]) {
	FindBest(board);
	
	while(true)
	{
		int i = getRow(cells.peek()),
			j = getCol(cells.peek()),
			validChoice;
	
		validChoice = nextValid(board[i][j]);
		
		if (validChoice >= 10)
		{
			board[i][j] = board[i][j] & ~(IS_FILLED_IN);
			board[i][j] = board[i][j] & ~VALUE_MASK;
			cells.pop();
			if (cells.isEmpty())
			{
				cout << "Error: Puzzle has no solution" << endl;
				return;
			}
			continue;
		}
		bool good = FindBest(board);
		
		if (!good)
			break;
	}
	printSudoku(board);
}

bool Sudoku::FindBest(uint16_t board [9][9]){
	
	//initialize all digits as choices - works
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			if (!(isFilled(board[row][col])))
				board[row][col] = board[row][col] | VALID_MASK;
		}
	}
	
	//remove invalid choices - works
	for (int row = 0; row < 9; row++){
		for (int col = 0; col < 9; col++){
			if ((isFilled(board[row][col])))
			{
				//One for-loop to mark all invalid guesses
				for (int i = 0; i < 9; i++)
				{
					if (!(isFilled(board[row][i]))) 
						markInvalid(board[row][i], board[row][col]);
					if (!(isFilled(board[i][col]))) 
						markInvalid(board[i][col], board[row][col]);
				}
				
				//Loop for 3x3 box
				int cellBox = findBox(row, col);
				for (int r = 0; r < 9; r++)
				{
					for (int c = 0; c < 9; c++)
					{
						if (findBox(r, c) == cellBox)
							if (!(isFilled(board[r][c]))) 
								markInvalid(board[r][c], board[row][col]);
					}
				}
			}
		}
	}
	
	
	int low = 10,
		iBest,
		jBest;
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (!(isFilled(board[i][j])))
			{
				int bitCount = countBits((board[i][j]) & VALID_MASK);
				
				if (bitCount < low)
				{
					low = bitCount;
					iBest = i;
					jBest = j;
				}
			}
		}
	}
	
	if (low == 10)
		return false;
	
	board[iBest][jBest] = board[iBest][jBest] | IS_FILLED_IN;
	
	int16_t intLoc = getLocation(iBest, jBest);
	cells.push(intLoc);
	
	return true;
} 

bool Sudoku::isFilled(uint16_t cell) {
	if ((cell & IS_FILLED_IN) >> 15 != 0)
		return true;
	return false;
}

bool Sudoku::isValid(uint16_t cell, uint16_t i) {
	return ((cell & (IS_0_VALID >> i)) != 0);
}

void Sudoku::markInvalid(uint16_t &cell, uint16_t i) {
    uint16_t h = 1, 
			k =i & VALUE_MASK;

    h = ~(h << (3 + k));
    cell = cell &h;

}

int Sudoku::getLocation(int r, int c) {
	return (c + (r * 9));
}

int Sudoku::nextValid(uint16_t &cell){
	int i = 1;
    for(; i<10; i++){
        if(isValid(cell, i)){
            cell &= ~VALUE_MASK;
            cell |= (10-i);
            cell &= ~(IS_0_VALID >> i);
            break;
        }
    }
    return i;
}

int Sudoku::findBox(uint16_t row,uint16_t col) {
	int 
		rowBox = (row/3),
		colBox = (col/3);
	
	if (rowBox == 0 && colBox == 0)
		return 0;
	else if (rowBox == 0 && colBox == 1)
		return 1;
	else if (rowBox == 0 && colBox == 2)
		return 2;
	else if (rowBox == 1 && colBox == 0)
		return 3;
	else if (rowBox == 1 && colBox == 1)
		return 4;
	else if (rowBox == 1 && colBox == 2)
		return 5;
	else if (rowBox == 2 && colBox == 0)
		return 6;
	else if (rowBox == 2 && colBox == 1)
		return 7;
	else if (rowBox == 2 && colBox == 2)
		return 8;
}

void Sudoku::showBits(uint16_t n) {
	
	for (int i = 15; i >= 0; i--) {
		if (n & (1 << i))
			cout << '1';
		else
			cout << '0';
	}
		
}

int Sudoku::countBits(uint16_t n) {
    int count = 0;

    while(n != 0)
	{
        count++;
        n &= n - 1;
    }

    return count;
}

void Sudoku::printSudoku(uint16_t board [9][9]) {
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			board[row][col] = (board[row][col] & VALUE_MASK);
			cout << board[row][col] << " ";
		}
		cout << endl;
	}
}
