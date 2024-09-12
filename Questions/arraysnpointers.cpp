#include <iostream>
using namespace std;
int main(){
    INPUTING VALUES
    int array[10];
    int *p=array;
    for (int i=0;i<10;i++){
        cin>>array[i];
    }
    PRINTING ADDRESS
    int *ptr=array;
    for (int i=0;i<10;i++){
        cout<<ptr<<endl;
        cout<<ptr+i<<endl;
    }
    TRAVERSING AN ARRAY
    int *pt=array;
    for (int i=0;i<10;i++){
       int j=*(ptr+i);
       cout<<j<<endl;
    }

    return 0;
}