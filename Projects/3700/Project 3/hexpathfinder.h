#pragma once

#include "stack.h"
#include <cstdint>
#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

const uint32_t
MAX_ROWS = 50,
MAX_COLS = 50,
DRAW_E = 6,
DRAW_V = 5,
DRAW_X_LEFT = 54,
DRAW_Y_TOP = 708;

#define computeX(c) (DRAW_X_LEFT + DRAW_E + (3 * DRAW_E * (c)) / 2)
#define computeY(r,c) (DRAW_Y_TOP - DRAW_V - 2 * DRAW_V * (r) - ((c) & 1u) * DRAW_V)

//
// these are constants to use in the maze cells
//
enum CellValues {
    WALL_UP = 0x01u,            // 00000001
    WALL_UP_RIGHT = 0x02u,      // 00000010
    WALL_DOWN_RIGHT = 0x04u,    // 00000100
    WALL_DOWN = 0x08u,          // 00001000
    WALL_DOWN_LEFT = 0x10u,     // 00010000
    WALL_UP_LEFT = 0x20u,       // 00100000
    VISITED = 0x40u,            // 01000000
    DEAD_END = 0x80u            // 10000000
};



//=============================================================================
// void printMaze(uint8_t maze[][MAX_COLS],int nR,int nC);
//  print the given maze
//
// Parameters
//  maze - MAX_ROWS x MAX_COLS character array containing maze information
//  nR   - number of rows in the maze
//  nC   - number of columns in the maze
//

void printMaze(uint8_t maze[][MAX_COLS], int nR, int nC);


uint32_t encode(uint32_t, uint32_t, uint32_t);
void decode(uint32_t, uint32_t&, uint32_t&, uint32_t&);
