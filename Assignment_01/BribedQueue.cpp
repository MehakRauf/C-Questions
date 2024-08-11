#include <iostream>
#include <fstream>

using namespace std;

 // function for counting bribes
int BribedQueue(int arr[], int size)
{
    int gap, bribes = 0;
    for (int i = 0; i < size; i++)
    {
        int hold = arr[i];
        gap = i - 1;
        while (gap >= 0 && hold < arr[gap])
        {
            int temp = arr[gap + 1];
            arr[gap + 1] = arr[gap];
            arr[gap] = temp;
            bribes++;
        }
    }
    return bribes;
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
    

   cout << BribedQueue(arr, total);
}