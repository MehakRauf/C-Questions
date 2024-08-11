#include <iostream>
#include <fstream>

using namespace std;

int SelectingTheMedian(int arr[], int size)
{
    int hold, j, median;
    for (int i = 0; i < size; i++)
    {
        hold = arr[i];
        j = i - 1;
        while (j >= 0 && hold < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = hold;
    }
   
    if (size % 2 != 0)
    {
        median = arr[size / 2];
    }
    else
    {
        median = (arr[size / 2 + 1] + arr[size / 2]) / 2;
    }
    return median;
}
int main()
{
    int total, arr[1100];
    string filepath;
    cout << "Enter the file path ";
    getline(cin, filepath);
    ifstream inputFile(filepath);
    if (!inputFile)
    {
        cout << "Error";
        return 1;
    }
    inputFile >> total;
    cout << "The size of the array is: " << total << endl;
    for (int i = 0; i < total; i++)
    {
        string element;
        getline(inputFile, element, ',');
        arr[i] = stoi(element);
    }
    inputFile.close();

    cout<< SelectingTheMedian(arr, total);
}