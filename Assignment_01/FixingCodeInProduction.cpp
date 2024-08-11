#include <iostream>
#include <fstream>

using namespace std;

// function to search a specific number
int FixingCodeInProduction(int arr[], int size, int toSearch)
{
    int l = 0, r = size;
    for (int i = 0; i < size; i++)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == toSearch)
        {
            return mid;
        }
        if (arr[mid] >toSearch )
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return -1;
}
int main()
{
    int toSearch, total, arr[100];
    string filepath;
    cout << "Enter the file path ";
    getline(cin, filepath);
    ifstream inputFile(filepath);
    if (!inputFile)
    {
        cout << "Error";
        return 1;
    }
    inputFile>>toSearch;
    inputFile >> total;
    cout << "The size of the array is: " << total << endl;
    for (int i = 0; i < total; i++)
    {
        string element;
        getline(inputFile, element, ',');
        arr[i] = stoi(element);
    }
    inputFile.close();
    // calling the function
    int result = FixingCodeInProduction(arr, total, toSearch);
    if (result != -1)
    {
        cout << "The number is found at " << result;
    }
    else
    {
        cout << "Number is not found.";
    }
}