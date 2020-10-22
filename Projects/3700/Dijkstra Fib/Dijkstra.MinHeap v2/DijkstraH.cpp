#include "DijkstraH.hpp"

void DijkstraH::printSolution(int dist[V], bool visit[V])
{
    cout << "Vertex \t\tCost to Destination \t\t Selected" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << dist[i] << "\t\t\t\t";

        if (visit[i])
            cout << 'T' << endl;
        else
            cout << 'f' << endl;

    }
}

void DijkstraH::DijkstraHeap(Graph g, int dest)
{
    Heap<Pair> minHeap(V);
    int dist[V];
    bool visit[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visit[i] = false;
    }

    
    //add destination(src) to heap, add its cost to dist[]
    minHeap.insert(make_pair(0, dest));
    dist[dest] = 0;
    visit[dest] = true;

    int h = 0;

    while (!minHeap.isEmpty()) {
        h++;

        Pair min = minHeap.remove(0);
        int u = min.second;
        cout << "DEBUG: Remove: " << h << endl;

        list< pair<int, int> >::iterator i;

        for (i = g.getAdj()[u].begin(); i != g.getAdj()[u].end(); i++)
        {
            int v = (*i).first;
            int cost = (*i).second;

            if (dist[v] > dist[u] + cost)
            {
                dist[v] = dist[u] + cost;
                minHeap.insert(make_pair(dist[v], v));
                visit[v] = true;
                cout << "DEBUG: Insert" << endl;
            }
        }
        
    }

    printSolution(dist, visit);
}