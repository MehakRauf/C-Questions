#include <iostream>
#include <fstream>



using namespace std;
void Show(int Enteries, int Arr[])
{
    for (int i = 0; i < Enteries; i++)
    {
        cout << Arr[i] << '\t';
       
    }
}
void readFromFile(char fileName[], int storage[], int &total)
{
    ifstream take(fileName);
    take >> total;
    char c[total];
    for (int i = 0; i < total; i++)
    {
        take >> storage[i];
        take>>c[i];
    }
 
}
int main()
{
    int count, store[100];
    char filename[10] = {"a.txt"};
    readFromFile(filename, store, count);
    Show(count, store);
    
     return 0;
}
