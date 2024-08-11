#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Data structure to represent each edge in the graph
struct Edge
{
    int src, dest, weight;
};

// Data structure to represent a disjoint set
struct DisjointSet
{
    vector<int> parent, rank;
};

// Create a disjoint set with n vertices
void createSet(DisjointSet &ds, int n)
{
    ds.parent.resize(n);
    ds.rank.resize(n);
    
    // Initialize the parent and rank for each vertex
    for (int i = 0; i < n; i++)
    {
        ds.parent[i] = i;
        ds.rank[i] = 0;
    }
}

// Find the set to which a vertex belongs (with path compression)
int find(DisjointSet &ds, int v)
{
    if (ds.parent[v] != v)
        ds.parent[v] = find(ds, ds.parent[v]);
    return ds.parent[v];
}

// Union two sets using rank (union by rank)
void unionSets(DisjointSet &ds, int x, int y)
{
    int xroot = find(ds, x);
    int yroot = find(ds, y);
    
    if (ds.rank[xroot] < ds.rank[yroot])
        ds.parent[xroot] = yroot;
    else if (ds.rank[xroot] > ds.rank[yroot])
        ds.parent[yroot] = xroot;
    else
    {
        ds.parent[yroot] = xroot;
        ds.rank[xroot]++;
    }
}

// Comparator function to sort edges by weight in non-decreasing order
bool compareEdges(Edge &e1, Edge &e2)
{
    return e1.weight < e2.weight;
}

// Apply Kruskal's Algorithm to find the minimum spanning tree
vector<Edge> kruskalAlgorithm(vector<Edge> &edges, int numVertices)
{
    vector<Edge> mst;
    
    // Sort edges in non-decreasing order of weight
    sort(edges.begin(), edges.end(), compareEdges);
    
    // Create a disjoint set with all vertices
    DisjointSet ds;
    createSet(ds, numVertices);
    
    // Process each edge in the sorted order
    for (Edge &e : edges)
    {
        int srcParent = find(ds, e.src);
        int destParent = find(ds, e.dest);
        
        // Check if the edge forms a cycle
        if (srcParent != destParent)
        {
            // Add the edge to the minimum spanning tree
            mst.push_back(e);
            
            // Union the two sets
            unionSets(ds, srcParent, destParent);
        }
    }
    
    return mst;
}

// Print the minimum spanning tree
void printMST(vector<Edge> &mst)
{
    cout << "Minimum Spanning Tree:" << endl;
    for (Edge &e : mst)
    {
        cout << e.src << " -- " << e.dest << " : " << e.weight << endl;
    }
}

int main()
{
    int numVertices = 5;
    
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 2},
        {1, 2, 3},
        {2, 3, 1},
        {0, 4, 4},
        {1, 3, 2},
        {3, 4, 6}
    };
    
    vector<Edge> mst = kruskalAlgorithm(edges, numVertices);
    
    printMST(mst);
    
    return 0;
}