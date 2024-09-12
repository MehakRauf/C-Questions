#include <iostream>
using namespace std;

// *********CALL BY VALUE
//VOID FUNCTION
// void swap(int a, int b){
//         int temp=a;
//         a=b;
//         b=temp;
//     }
// int main(){
//     //CALL BY VALUE
//     //SWAP FUNCTION
//     int x=9, y=8;
//     cout<<"The value of x is: "<<x<<endl;
//     cout<<"The value of y is: "<<y<<endl;
//     cout<<"NOW SWAPPING THE VALUES BY CALL BY VALUE METHOD. "<<endl;
//     swap(x,y);
//     cout<<"The new value of x is: "<<x<<endl;
//     cout<<"The new value of y is: "<<y<<endl;
//     return 0;
// }

// CALL BY REFERENCE 
// void swap(int &a, int &b){ //void swap(int *a, int *b){
//         int temp=a;        //int temp=*a;
//         a=b;              //*a=*b;
//         b=temp;            //*b=temp;
//     }
//     int main(){
//     //CALL BY REFERENCE
//     //SWAP FUNCTION
//     int x=9, y=4;
//     cout<<"The value of x is: "<<x<<endl;
//     cout<<"The value of y is: "<<y<<endl;
//     cout<<"NOW SWAPPING THE VALUES BY CALL BY VALUE METHOD. "<<endl;
//     swap(x,y);
//     cout<<"The new value of x is: "<<x<<endl;
//     cout<<"The new value of y is: "<<y<<endl;
//     return 0;
// }

// RETURN BY REFERENCE 
// int  &swapbyreference(int &a, int &b){
//         int temp=a;
//         a=b;
//         b=temp;
//         return a ; //It will return value of a  
//     }
// int main(){
//     //SWAP FUNCTION
//     int x=9, y=8;
//     cout<<"The value of x is: "<<x<<endl;
//     cout<<"The value of y is: "<<y<<endl;
//     cout<<"NOW SWAPPING THE VALUES BY CALL BY VALUE METHOD. "<<endl;
//     swapbyreference(x,y)=76;//THE VALUE OF "a" WILL BE 76 BECAUSE THE FUNCTION IS RETURNING a. 
//     cout<<"The new value of x is: "<<x<<endl;
//     cout<<"The new value of y is: "<<y<<endl;
//     return 0;
// }