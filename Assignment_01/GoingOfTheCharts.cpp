#include <iostream>
#include <fstream>

using namespace std;

// function for counting the longest sequence
int GoingOffTheCharts(int arr[], int size)
{

    int max_wh[size];
    int wh = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 6)
        {
            wh++;
            max_wh[i] = wh;
        }
        else
        {
            wh = 0;
            max_wh[i] = wh;
        }
    }
    int min = max_wh[0];
    for (int i = 0; i < size; i++)
    {
        if (min < max_wh[i])
        {
            min = max_wh[i];
        }
    }
    return min;
}

int main()
{
    int total, arr[100];
    string filepath;
    cout<<"Enter the file path ";
    getline(cin, filepath);
    ifstream inputFile(filepath);
    if(!inputFile){
        cout<<"Error";
        return 1;
      
    }
    inputFile>>total;
    cout<<"The size of the array is: "<<total<<endl;
    for(int i=0; i<total; i++){
        string element;
        getline(inputFile,element, ',');
        arr[i]= stoi(element);
    }
    inputFile.close();
    // calling the function
    cout<<endl;
    cout << GoingOffTheCharts(arr, total);
}