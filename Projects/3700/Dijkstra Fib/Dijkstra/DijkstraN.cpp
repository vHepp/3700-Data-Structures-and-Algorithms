#include "DijkstraN.hpp"

void DijkstraN::printSolution(Vertex nodes[])
{
    cout << "Vertex \t\tCost to Destination \t\t Selected" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << nodes[i].getCost() << "\t\t\t\t";

        if (nodes[i].getSelected())
            cout << 'T' << endl;
        else
            cout << 'f' << endl;

    }   
}

void DijkstraN::DijkstraNaive(Vertex Graph[V][V], int32_t dest)
{
    Vertex nodes[V];

    for (int i = 0; i < V; i++) {
        nodes[i].setCost(INT_MAX);
        nodes[i].setSelected(false);
        nodes[i].setParent(nullptr);
    }
    nodes[dest].setCost(0);

    Vertex v;
    int index;

    for (int i = 1; i < V; i++) {
        v.findBest(nodes,v,index);
        nodes[index].setSelected(true);

        for (int k = 0; k < V; k++) {
            if (!nodes[k].getSelected() && Graph[index][k].getCost() && v.getCost() != INT_MAX) {
                if (v.getCost() + Graph[index][k].getCost() < nodes[k].getCost()) {
                    nodes[k].setCost(v.getCost() + Graph[index][k].getCost());
                    nodes[k].setParent(&nodes[index]);
                }
            }
        }
    }

    printSolution(nodes);
}