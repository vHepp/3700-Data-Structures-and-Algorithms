#include <limits.h> 
#include <stdio.h>
#include <iostream>
#include <chrono> 
#include "DijkstraN.hpp"
//#include "DijkstraH.hpp"

using namespace std::chrono;
using namespace std;

//the roads matrix from the slides
   /*
int32_t Matrix [V][V] = { { 0 ,103, 0 ,275, 0 , 0 , 0 ,128},
                                    {103, 0 ,113, 0 , 0 , 0 , 0 , 0 },
                                    { 0 ,113, 0 , 44, 74, 0 , 0 , 0 },
                                    {275, 0 , 44, 0 , 50, 0 ,114, 0 },
                                    { 0 , 0 , 74, 50, 0 , 68, 0 , 0 },
                                    { 0 , 0 , 0 , 0 , 68, 0 ,177, 0 },
                                    { 0 , 0 , 0 ,114, 0 ,177, 0 ,169},
                                    {128, 0 , 0 , 0 , 0 , 0 ,169, 0 } };

   */

//Matrix of graph from GeeksforGeeks
   // /*
int32_t Matrix[V][V] = { { 0 , 4 , 0 , 0 , 0 , 0 , 0 , 8 , 0 },
                         { 4 , 0 , 8 , 0 , 0 , 0 , 0 , 11, 0 },
                         { 0 , 8 , 0 , 7 , 0 , 4 , 0 , 0 , 2 },
                         { 0 , 0 , 7 , 0 , 9 , 14, 0 , 0 , 0 },
                         { 0 , 0 , 0 , 9 , 0 , 10, 0 , 0 , 0 },
                         { 0 , 0 , 4 , 14, 10, 0 , 2 , 0 , 0 },
                         { 0 , 0 , 0 , 0 , 0 , 2 , 0 , 1 , 6 },
                         { 8 , 11, 0 , 0 , 0 , 0 , 1 , 0 , 7 },
                         { 0 , 0 , 2 , 0 , 0 , 0 , 6 , 7 , 0 } };

// */


void doDijkstraN() {
    Vertex Graph[V][V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            Graph[i][j].setCost(Matrix[i][j]);
        }
    }

    DijkstraN dummyN;

    // Get starting timepoint 
    auto start = high_resolution_clock::now();

    dummyN.DijkstraNaive(Graph, 0);

    // Get ending timepoint 
    auto stop = high_resolution_clock::now();
    // Get duration.
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: DijkstraNaive = "
        << duration.count() << " microseconds" << endl;
}

/*
void doDijkstraH() {
    Vertex Graph[V][V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            Graph[i][j].setCost(Matrix[i][j]);
        }
    }

    DijkstraH dummyH;

    // Get starting timepoint 
    auto start = high_resolution_clock::now();

    dummyH.DijkstraHeap(Graph, 0);

    // Get ending timepoint 
    auto stop = high_resolution_clock::now();
    // Get duration.
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: DijkstraHeap = "
        << duration.count() << " microseconds" << endl;
}
*/

/*
void doDijkstraF() {
    //int32_t Matrix[V][V];
    Vertex dummy;

    // dummy.randomize(Matrix);

    DijkstraN dummyN;

    // Get starting timepoint 
    auto start = high_resolution_clock::now();

    dummyN.DijkstraNaive(Matrix, 0);

    // Get ending timepoint 
    auto stop = high_resolution_clock::now();
    // Get duration.
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: DijkstraNaive = "
        << duration.count() << " microseconds" << endl;
}
*/

int main()
{ 
    //testMinHeap();

     doDijkstraN();
    // doDijkstraH();
    // doDijkstraF();

    return 0;
}