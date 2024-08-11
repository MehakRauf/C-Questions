#include <iostream>
using namespace std;

int hash_function(int key, int size)
{
    return (key % size);
}
void linear_hash(int arr[], int key, int size)
{
    int ind = hash_function(key, size);
    if (arr[ind] == -1)
    {
        arr[ind] = key;
    }
    else
    {
        for (int i = 1; i < size; i++)
        {
            int index = (ind + 1) % size;
            if (arr[index] == -1)
            {
                arr[index] = key;
                break;
            }
        }
    }
}
int main()
{
    int arr[8];
    for (int i = 0; i < 8; i++)
    {
        arr[i] = -1;
    }
    linear_hash(arr, 2, 8);
    linear_hash(arr, 3, 8);
    linear_hash(arr, 3, 8);
    linear_hash(arr, 4, 8);
    linear_hash(arr, 5, 8);
    linear_hash(arr, 9, 8);

    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
}