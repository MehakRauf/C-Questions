#include <iostream>
#include <cstdlib>
#include <set>
using namespace std;

#define INF 9999

struct Vertex
{
    char data;
    struct Vertex *next;
    struct Edge *edgeList;
    bool visited;
    int distance;
};

struct Edge
{
    struct Vertex *toVertex;
    int weight;
    struct Edge *next;
};

struct Vertex *start = nullptr;

// Function to insert a vertex
void insertVertex(char data)
{
    struct Vertex *temp = new Vertex;
    temp->data = data;
    temp->edgeList = nullptr;
    temp->visited = false;
    temp->distance = INF;
    temp->next = nullptr;

    if (start == nullptr)
    {
        start = temp;
    }
    else
    {
        struct Vertex *curr = start;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

// Function to insert an edge
void insertEdge(char v1, char v2, int weight)
{
    bool v1Exists = false;
    bool v2Exists = false;

    struct Vertex *fromVertex = nullptr;
    struct Vertex *toVertex = nullptr;

    // Check if both vertices exist in the graph
    struct Vertex *curr = start;
    while (curr != nullptr)
    {
        if (curr->data == v1)
        {
            v1Exists = true;
            fromVertex = curr;
        }
        if (curr->data == v2)
        {
            v2Exists = true;
            toVertex = curr;
        }
        curr = curr->next;
    }

    // If both vertices exist, insert the edge
    if (v1Exists && v2Exists)
    {
        struct Edge *edge = new Edge;
        edge->toVertex = toVertex;
        edge->weight = weight;
        edge->next = nullptr;

        if (fromVertex->edgeList == nullptr)
        {
            fromVertex->edgeList = edge;
        }
        else
        {
            struct Edge *temp = fromVertex->edgeList;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = edge;
        }
    }
}

// Function to find the shortest path using Dijkstra's algorithm
void findShortestPath(char startVertex, char endVertex)
{
    // Initialize all vertices with infinite distance except the start vertex
    struct Vertex *curr = start;
    while (curr != nullptr)
    {
        // From the start vertex to itself distance is 0
        if (curr->data == startVertex)
        {
            curr->distance = 0;
        }
        // If the current vertex is not the start vertex, we set its distance to infinity because we don't know its distance yet.
        else
        {
            curr->distance = INF;
        }
        curr = curr->next;
    }

    // Check if start and end vertices exist in the graph
    struct Vertex *startVertexPtr = nullptr;
    struct Vertex *endVertexPtr = nullptr;
    curr = start;
    while (curr != nullptr)
    {
        if (curr->data == startVertex)
        {
            startVertexPtr = curr;
        }
        if (curr->data == endVertex)
        {
            endVertexPtr = curr;
        }
        curr = curr->next;
    }

    if (startVertexPtr == nullptr || endVertexPtr == nullptr)
    {
        cout << "Start or end vertex does not exist.";
        return;
    }

    // Dijkstra's algorithm
    while (true)
    {
        // Find the vertex with minimum distance that hasn't been visited
        struct Vertex *minVertex = nullptr;
        curr = start;
        while (curr != nullptr)
        {
            if (!curr->visited && (minVertex == nullptr || curr->distance < minVertex->distance))
            {
                minVertex = curr;
            }
            curr = curr->next;
        }

        // If no unvisited vertex with minimum distance is found, break out of the loop
        if (minVertex == nullptr || minVertex == endVertexPtr)
            break;

        // Mark the minimum distance vertex as visited
        minVertex->visited = true;

        // Traverse all the edges of the current vertex
        struct Edge *edge = minVertex->edgeList;
        while (edge != nullptr)
        {
            // Calculate the new distance
            int newDistance = minVertex->distance + edge->weight;

            // Update the distance of the adjacent vertex if it is smaller than the current distance
            if (newDistance < edge->toVertex->distance)
            {
                edge->toVertex->distance = newDistance;
            }

            edge = edge->next;
        }
    }

    // Print the shortest distance from the start vertex to the end vertex
    cout << "Shortest distance from " << startVertex << " to " << endVertex << " is: " << endVertexPtr->distance << endl;
}

int main()
{
    insertVertex('a');
    insertVertex('b');
    insertVertex('c');
    insertVertex('d');
    insertVertex('t');

    insertEdge('a', 'c', 3);
    insertEdge('c', 'b', 2);
    insertEdge('a', 'b', 8);
    insertEdge('a', 't', 4);

    findShortestPath('a','t');

    return 0;
}