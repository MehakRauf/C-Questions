#include <iostream>
using namespace std;

int hash_function(int value, int size)
{
    int hash_key = (value) % size;
    return hash_key;
}
void insert(int arr[], int size)
{
    int key_value;
    cout << "Enter the value: " << endl;
    cin >> key_value;
    int ind = hash_function(key_value, size);
    int i = 1;
    while (arr[ind] != -1)
    {
        ind = (key_value + i * i) % size;
        i++;
    }
    arr[ind] = key_value;
}
bool search(int arr[], int key, int size)
{
    int index = hash_function(key, size);
    if (arr[index] == key)
    {
        return true;
    }
    int i = 1;
    while (arr[index] != key)
    {
        if (arr[index] == -1)
            return false;

        index = (key + i * i) % size;
        i++;
    }

    return true;
}
int main()
{
    int size;
    cout << "Enter the size of the hash_table: " << endl;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = -1;
    }
    for (int i = 0; i < size; i++)
    {
        insert(arr, size);
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << search(arr, 3, size) << endl;
}
