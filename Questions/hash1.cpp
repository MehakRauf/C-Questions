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
    if (arr[ind] == -1)
    {
        arr[ind] = key_value;
        return;
    }
    for (int i = 1; i < size; i++)
    {
        int n_ind = (ind + i) % size;
        if (arr[n_ind] == -1)
        {
            arr[n_ind] = key_value;
            return;
        }
    }
}
void deletion(int size, int arr[])
{
    bool flag = false;
    int todelete;
    cout << "Enter the number you want to delete: " << endl;
    cin >> todelete;
    int ind = hash_function(todelete, size);
    if (arr[ind] == todelete)
    {
        cout<<"Element is found."<<endl;
        return;
    }
    else
    {
        int i = 1;
        int n_ind = (ind + i) % size;
        while (arr[n_ind] != todelete)
        {
            if (arr[n_ind] == todelete)
            {
                cout<<"Element is found"<<endl;
                return;
            }
            i++;
            n_ind = (ind + i) % size;
        }        
    }
 cout<<"Element is not found."<<endl;   
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
    deletion(size,arr);
}