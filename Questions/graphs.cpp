#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter the no. of vertices: " << endl;
    cin >> size;
    int arr[size][size];
    // for entering the values
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "Enter the edges one by one using '1' and '0': " << endl;
            cout << i << " " << j << " = ";
            cin >> arr[i][j];
            if (i != j)
            {
                arr[j][i] = arr[i][j];
            }
        }
    }

    // for printing the adjacency matrix and also calculating the no. of edges
    int edges = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << " ";
            if (arr[i][j] == 1)
            {
                edges++;
                if (i == j == 1)
                {
                    edges++;
                }
            }
            
        }
        cout << endl;
    }

    // to calculate the edges of every vertex
    for (int i = 0; i < size; i++)
    {
        int edge_vertex = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] == 1)
            {
                edge_vertex++;
            }
            if (j == size - 1)
            {
                cout << "The number of edges of " << i << " vertex is: " << edge_vertex << endl;
            }
        }
    }
    cout << "The total no. of edges is: " << (edges / 2) << endl;
    cout << "The total no. of vertices is: " << size << endl;
}