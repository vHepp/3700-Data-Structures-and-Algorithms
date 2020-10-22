#include <fstream>
#include <random>
#include <iostream>
#include <string>

using namespace std;

#define V 16

int getRandom(int32_t min, int32_t maxIncluded) {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<> dist(min, maxIncluded);

    auto random_number = dist(rng);

    return random_number;
}

void randomize(int Graph[V][V]) {

    int
        MAX = V * V - V,
        i = 0,
        u,
        dist;
    int
        rR, rC;

    for (int k = 0; k < V; k++) {
        for (int j = 0; j < V; j++) {
            Graph[k][j] = 0;
        }
    }

    i = getRandom(0, MAX/2);
    u = MAX - i;

    //gives each vertex a random cost
    while (i < MAX)
    {
        rR = getRandom(0, V - 1);
        rC = getRandom(0, V - 1);
        dist = getRandom(1, 500);


        Graph[rR][rC] = dist;
        Graph[rC][rR] = dist; //mirrors over the "0" line
        
        cout << i << '\t' << u << endl;

        i++;

    }

    cout << '\n' << u << endl;


    //resets the diagonal "0" line in
    for (i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j)
                Graph[i][j] = 0;
        }
    }
}

int Matrix [V][V];

int main() {

    randomize(Matrix);

    string lb = "{";
    string comma = ",";
    string rb = "}";

    string graph = "{ ";

    for (int i = 0; i < V; i++) {
        graph+= lb;
        for (int j = 0; j < V; j++) {
            if (j == V - 1)
                graph+= to_string(Matrix[i][j]);
            else
                graph+= to_string(Matrix[i][j]) + comma;
        }
        if (i == V - 1)
            graph+= rb;
        else
            graph+= rb + comma + "\n";
    }
    graph+= " " + rb;


    string Filename = "V=";
    string size = to_string(V);
    string TXT = ".txt";

    Filename+= size + TXT;


    ofstream myfile;
    myfile.open(Filename);
    myfile << graph;
    myfile.close();
    return 0;
}