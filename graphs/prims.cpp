#include <iostream>
#include <stdlib.h>
using namespace std;

struct Vertex
{
    char data;
    struct Vertex *next;
    struct Edge *edgeList;
    bool visited;
};

struct Edge
{
    struct Vertex *toVertex;
    int weight;
    struct Edge *next;
};

struct Vertex *start = NULL;

void insertVertex(char v)
{
    struct Vertex *temp = new Vertex;
    temp->data = v;
    temp->visited = false;
    temp->next = NULL;
    temp->edgeList = NULL;

    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        struct Vertex *curr = start;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

bool searchVertex(char v)
{
    struct Vertex *curr = start;
    while (curr != NULL)
    {
        if (curr->data == v)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

struct Vertex *searchAddress(char v)
{
    struct Vertex *curr = start;
    while (curr != NULL)
    {
        if (curr->data == v)
        {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

void insertEdge(char v1, char v2, int weight)
{
    bool v1Exists = searchVertex(v1);
    bool v2Exists = searchVertex(v2);

    if (v1Exists && v2Exists)
    {
        struct Vertex *fromVertex = searchAddress(v1);
        struct Vertex *toVertex = searchAddress(v2);

        struct Edge *temp = new Edge;
        temp->toVertex = toVertex;
        temp->weight = weight;
        temp->next = NULL;

        if (fromVertex->edgeList == NULL)
        {
            fromVertex->edgeList = temp;
        }
        else
        {
            struct Edge *curr = fromVertex->edgeList;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = temp;
        }
    }
}

void primAlgorithm()
{
    // Select the starting vertex
    struct Vertex *v = start;
    v->visited = true;

    while (v != NULL)
    {
        // Find the minimum weight edge from the visited vertices
        struct Edge *minEdge = NULL;
        // store the vertex to which the minimum weight edge is connected.
        struct Vertex *minToVertex = NULL;
        // This variable will be used to iterate through all vertices in the graph.
        struct Vertex *curr = start;
        while (curr != NULL)
        {
            // to find the edges from the visited vertices
            if (curr->visited)
            {
                struct Edge *edge = curr->edgeList;
                // to check the visited edges
                while (edge != NULL)
                {
                    // checks if the vertex connected through the current edge has been visited or not.
                    if (!edge->toVertex->visited)
                    {
                        if (minEdge == NULL || edge->weight < minEdge->weight)
                        {
                            minEdge = edge;
                            minToVertex = edge->toVertex;
                        }
                    }
                    edge = edge->next;
                }
            }
            curr = curr->next;
        }

        // Add the minimum weight edge to the minimum spanning tree
        if (minEdge != NULL)
        {
            minToVertex->visited = true;
            cout << "Added edge: " << v->data << " - " << minToVertex->data << " (Weight: " << minEdge->weight << ")" << endl;
        }

        // Move to the next visited vertex
        v = v->next;
    }
}

void traverse()
{
    struct Vertex *curr = start;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    insertVertex('a');
    insertVertex('b');
    insertVertex('c');
    insertVertex('d');
    insertVertex('e');

    insertEdge('a', 'b', 4);
    insertEdge('a', 'c', 2);
    insertEdge('b', 'c', 3);
    insertEdge('c', 'd', 1);
    insertEdge('a', 'e', 4);
    insertEdge('c', 'c', 6);
    insertEdge('b', 'a', 2);
    insertEdge('c', 'd', 9);

    primAlgorithm();

    return 0;
}
