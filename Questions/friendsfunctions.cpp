// ADDING COMPLEX NUMBER
//  class Complex{
//      int a, b;
//      friend Complex sumComplex(Complex o1, Complex o2);
//      public:
//          void setNumber(int n1, int n2){
//              a = n1;
//              b = n2;
//          }

//         void printNumber(){
//             cout<<"Your number is "<<a<<" + "<<b<<"i"<<endl;
//         }
// };

// Complex sumComplex(Complex o1, Complex o2){
//     Complex o3;
//     o3.setNumber((o1.a + o2.a), (o1.b+o2.b))
//     ;
//     return o3;
// }

// int main(){
//     Complex c1, c2, sum;
//     c1.setNumber(1, 4);
//     c1.printNumber();

//     c2.setNumber(5, 8);
//     c2.printNumber();

//     sum = sumComplex(c1, c2);
//     sum.printNumber();

//     return 0;
// }

// SUM OF SERIES OF NUMBERS
// #include <iostream>
// using namespace std;

// class SumOdd
// {
//     int n;
//     friend int sum(int n, int s);
// };

// int sum(int n, int s)
// {
//     while (n > 0)
//     {
//         s = s + n;
//         n = n - 1;
//     }
//     return s;
// }

// int main()
// {
//     cout << sum(8, 0);
//     return 0;
// }

// SUM OF ODD NUMBERS OF A NUMBER SERIES
// #include <iostream>
// using namespace std;

// class SumOdd
// {
//     int n;
//     friend int sum(int n, int s);
// };

// int sum(int n, int s)
// {
//     while (n > 0)
//     {
//         if (n%3==0){
//             s = s + n;
//     }
//     n = n - 1;
//     }
//     return s;
// }

// int main()
// {
//     cout <<"The sum of odd numbers is: "<< sum(9, 0) <<endl;
//     return 0;
// }

//FIBONACCI SERIES
// #include <iostream>
// using namespace std;

// class fibonacci{
//     int n;
//     friend int fibseries( int n);
// };
// int fibseries(int n) {
//     if (n==1 ||  n==0){
//         return 1;
//     }
//     else{
//         return fibseries(n-1)+fibseries(n-2);
//     }
// }
// int main(){
//     cout<<fibseries(5);
//     return 0;
// }

#include <iostream>
using namespace std;

class pattern{
    int nor;
    friend string patt(int n);
};
string patt(int n){
    string i="*";
    cout<<n*i;
}
int main(){
    patt(4);
    return 0;
}