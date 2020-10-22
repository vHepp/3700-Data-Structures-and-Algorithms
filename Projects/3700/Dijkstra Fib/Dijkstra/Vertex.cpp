#include "Vertex.hpp"

Vertex::Vertex() {
	selected = false;
	parent = nullptr;
	cost = INT_MAX;
}

Vertex::~Vertex() { }

int32_t Vertex::getRandom(int32_t min, int32_t maxIncluded) {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<> dist(min, maxIncluded);

    auto random_number = dist(rng);

    return random_number;
}

void Vertex::randomize(int32_t Graph[V][V]) {

    int32_t
        MAX = V * V - V,
        i = 0, dist;
    int
        rR, rC;

    for (int k = 0; k < V; k++) {
        for (int j = 0; j < V; j++) {
            Graph[k][j] = 0;
        }
    }

    //gives each vertex a random cost
    while (i < MAX)
    {
        rR = getRandom(0, V - 1);
        rC = getRandom(0, V - 1);
        dist = getRandom(1, 1000);

        Graph[rR][rC] = dist;
        Graph[rC][rR] = dist; //mirrors over the "0" line
        

        i++;

    }


    //sets the diagonal "0" line in
    for (i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j)
                Graph[i][j] = 0;
        }
    }
}

void Vertex::findBest(Vertex nodes[], Vertex &v, int32_t&index) {
    int32_t min = INT_MAX;
    Vertex best;

    for (int i = 0; i < V; i++) {
        if (nodes[i].getCost() <= min && nodes[i].getSelected() == false) {
            best = nodes[i];
            min = nodes[i].getCost();
            index = i;
        }
    }

    v = best;
}