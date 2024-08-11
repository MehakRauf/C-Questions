#include <iostream>
#include <stdlib.h>
#include <queue>
#include <stack>
using namespace std;

struct Vertex
{
    int data;
    struct Edge *edgeList;
    struct Vertex *next;
    bool visited;
};
struct Edge
{
    struct Vertex *toVertex;
    struct Edge *next;
};
struct Vertex *start;

bool isVertex(int value)
{
    struct Vertex *curr = start;
    while (curr != NULL)
    {
        if (curr->data == value)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

Vertex *VertexAddress(int value)
{
    struct Vertex *curr = start;
    while (curr != NULL)
    {
        if (curr->data == value)
        {
            return curr;
        }
        curr = curr->next;
    }
}
void insert_Edge(int ver1, int ver2)
{
    bool ver1exists = isVertex(ver1);
    bool ver2exists = isVertex(ver2);
    if (ver1exists && ver2exists)
    {
        struct Vertex *v1 = VertexAddress(ver1);
        struct Vertex *v2 = VertexAddress(ver2);
        struct Edge *temp = (struct Edge *)malloc(sizeof(struct Edge));
        temp->toVertex = v2;
        temp->next = NULL;
        if (v1->edgeList == NULL)
        {
            v1->edgeList = temp;
            return;
        }
        else
        {
            struct Edge *edge = v1->edgeList;
            while (edge->next != NULL)
            {
                edge = edge->next;
            }
            edge->next = temp;
        }
    }
}

void insert(int value)
{
    struct Vertex *temp = (struct Vertex *)malloc(sizeof(struct Vertex));
    temp->data = value;
    temp->next = NULL;
    temp->edgeList = NULL;
    if (start == NULL)
    {
        start = temp;
        return;
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

void print()
{
    struct Vertex *curr = start;
    while (curr != NULL)
    {
        cout << curr->data << " -> ";
        struct Edge *curr1 = curr->edgeList;
        while (curr1 != NULL)
        {
            cout << curr1->toVertex->data << " ";
            curr1 = curr1->next;
        }
        cout << endl;
        curr = curr->next;
    }
}
bool bfs(int v1, int v2)
{
    queue<int> q;
    queue<int> q1;
    struct Vertex *curr = VertexAddress(v1);
    q.push(curr->data);
    curr->visited = true;
    bool flag = false;
    while (!q.empty())
    {
        int currentVertex = q.front();
        q1.push(currentVertex);
        q.pop();

        if (currentVertex == v2)
        {
            flag = true;
            break;
        }
        struct Vertex *vertex = VertexAddress(currentVertex);
        struct Edge *edge = vertex->edgeList;
        while (edge != NULL)
        {
            if (!edge->toVertex->visited)
            {
                q.push(edge->toVertex->data);
                q1.push(edge->toVertex->data);
                edge->toVertex->visited = true;

                if (edge->toVertex->data == v2)
                {
                    flag = true;
                    break;
                }
            }
            edge = edge->next;
        }
    }

    if (flag)
    {
        cout << "The path is:" << endl;
        while (!q1.empty())
        {
            cout << q1.front() << " ";
            q1.pop();
        }
    }
    else
    {
        cout << "No path" << endl;
    }
}

int main()
{
    insert(0);
    insert(1);
    insert(2);
    insert_Edge(0, 0);
    insert_Edge(0, 2);
    insert_Edge(1, 0);
    insert_Edge(1, 1);
    insert_Edge(2, 2);
    print();
    
    bfs(0,2);
}