#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int source, destination, weight;
};

bool compareEdges(Edge one, Edge two) {
    return one.weight < two.weight;
}

int find(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

vector<Edge> kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; ++i) parent[i] = i;

    vector<Edge> mst;
    for (const Edge& edge : edges) {
        if (find(parent, edge.source) != find(parent, edge.destination)) {
            mst.push_back(edge);
            unionSets(parent, rank, edge.source, edge.destination);
        }
    }

    return mst;
}

int main() {
    int V, E;
    cout << "Enter the no. vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter the edges (src, dest, weight):\n";
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    vector<Edge> mst = kruskalMST(V, edges);

    cout << "The Edges in the Minimum Spanning Tree:\n";
    int totalWeight = 0;
    for (const Edge& edge : mst) {
        cout << edge.source << " -- " << edge.destination << " == " << edge.weight << "\n";
        totalWeight += edge.weight;
    }
    cout << "The total weight of the MST: " << totalWeight << "\n";

    return 0;
}
