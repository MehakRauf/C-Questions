#include <iostream>
using namespace std;
//**********PRINTING n NATURAL NUMBERS
// int natnum(int n){
//     if (n<=50){
//         cout<<n<<endl;
//         natnum(n+1);

//     }
// }
// int main(){
//     natnum(1);
//     return 0;
// }

//*******SUM OF n NATURAL NUMBERS
// int sumn(int n){
//     int sum=0;
//     if (n==1){
//         return 1;}
//         else {
//         sum=n+sumn(n-1);
//     }return sum;
// }
// int main(){
//     cout<<"The sum of the n natural numbers is: "<<sumn(5);
//     return 0;
// }

//********FIBONACCI SERIES
// int fib(int n){
//     if (n==0 || n==1){
//         return 1;
//     }
//     else{
//         return fib(n-2)+fib(n-1);
//     }
// }
// int main(){
//     cout<<fib(5);
//     return 0;
// }

//**********FACTORIALS
// int fac(int num){
//     if (num==1 ||num==0){
//         return 1;
//     }
//     else{
//     return num*fac(num-1);
// }
// }
// int main(){
//     cout<<"The factorial of the given number is: "<<fac(4);
//     return 0;
// }
// void printn(int n){
//     if(n==0){
//         return;
//     }
//     cout<<n<<endl;
//     printn(n-1);
// }
// void printn1(int n1){
//     if(n1==5){
//         cout<<n1;
//         return;
//     }
//     cout<<n1<<endl;
//     printn1(n1+1);
// }
// void sum(int n, int sum1){
//     if(n==0){
//         cout<<sum1;
//         return;
//     }
//     sum1+=n;
//     sum(n-1,sum1);
// }

// void factorial(int n, int fac){
//     if(n==0 || n==1){
//         cout<<fac;
//         return;
//     }
//     fac*=n;
//     factorial(n-1,fac);
// }

// void fibonacci(int n1, int n2, int n){
//     if(n==0 ){
//         return;
//     }
//     cout<<n1<<endl;
//     fibonacci(n2,n2+n1,n-1);
// }

// int power(int x, int n){
//     if(n==0){
//         return 1;
//     }
//     if(x==0){
//         return 0;
//     }
//     if(n%2==0){
//         return power(x,n/2)* power(x,n/2);
//     }
//     else{
//         return power(x,n/2)* power(x,n/2)* x;
//     }
// }

// void towerOfHanoi(int n, char src, char help, char dest)
// {
//     if (n == 1)
//     {
//         cout << "Transfer " << n << " from " << src << " to " << dest << endl;
//         return;
//     }
//     towerOfHanoi(n - 1, src, dest, help);
//     cout << "Transfer " << n << " from " << src << " to " << dest << endl;
//     towerOfHanoi(n - 1, help, src, dest);
// }

// void reverseString(char ar[], int ind){
//     if(ind==0){
//         return;
//     }
//     cout<<ar[ind-1];
//     reverseString(ar ,ind-1);
// }
// static int first=-1;
// static int last=-1;

// void occurance(char arr[],int ind, int len, char element){
//     if(ind==len){
//         cout<<"The first occurance is at "<<first<<endl;
//         cout<<"The last occurance is at "<<last<<endl;
//     }
//     if(arr[ind]==element){
//         if(first==-1){
//             first=ind;
//         }
//         else{
//             last=ind;
//         }
//     }
//     occurance(arr,ind+1,len,element
// bool isSorted(int arr[], int idx, int len){
//     if(idx==len-1){
//         return true;
//     }
//     if(arr[idx]<arr[idx+1]){
//         isSorted(arr,idx+1,len);
//     }else{
//         return false;
//     }
// }

    // static int countpaths(int i, int j, int n, int m){
    //     if(i==n || j==m){
    //         return 0;
    //     }
    //     if(i==n-1 || j==m-1){
    //         return 1;
    //     }
    //     int downpaths=countpaths(i+1,j,n,m);
    //     int rightpaths=countpaths(i,j+1,n,m);
    //     return downpaths+rightpaths;
    // }


int main()
{
//    cout<<countpaths(0,0,3,3);
    // int arr[]={1,2,3,5,7};
    // cout<<isSorted(arr,0,6);
    // char arr[]={'a','b','a','a','c','d','a','e','f','a','a','h'};
    // occurance(arr,0,12,'a');
    // char ar[]={'m','e','h','a','k'};
    // reverseString(ar,5);
    //towerOfHanoi(3,'S','H','D');
    // cout<<power(2,4);
    //  fibonacci(0,1,5);
    // factorial(5,1);
    //  sum(9,0);
    //  printn1(1);
    //  cout<<"second"<<endl;
    //  printn(6);
}
