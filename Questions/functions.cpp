// #include <iostream>
// using namespace std;

//**********SUM OF TWO NUMBERS
// int sum(int a,int b){
//     int s=a+b;
//     cout<<s;
// }
// int main(){
//     sum(3,5);
//     return 0;
// }
//*******PRODUCT OF TWO NUMBERS
// int product(int a,int b){
//     int s=a*b;
//     cout<<s;
// }
// int main(){
//     product(3,5);
//     return 0;
// }

// ******AREA AND CIRCUMFERENCE OF CIRCLE
// int anc(int radius){
//     cout<<"Area is: "<<3.142*radius*radius<<endl;
//     cout<<"Circumference is: "<<3.142*2*radius<<endl;
// }
// int main(){
//     int n;
//     cout<<"Enter the radius: "<<endl;
//     cin>>n;
//     anc(n);
//     return 0;
// }

// *******Define two functions to print the maximum
// and the minimum number respectively among 
// three numbers entered by user.

// int maxnmin(int a,int b,int c){
//     if (a>b && a>c){
//         cout<<a<<" is the greatest of all."<<endl;
//     }
//     else if (b>c && b>a){
//         cout<<b<<" is the greatest of all."<<endl;
//     }
//     else {
//         cout<<c<<" is the greatest of all."<<endl;
//     }
//     if (a<b && a<<c){
//         cout<<a<<" is the smallest of all."<<endl;
//     }
//     else if(b<a && b<<c){
//         cout<<b<<" is the smallest of all."<<endl;
//     }
//     else{
//         cout<<c<<" is the smallest of all."<<endl;
//     }
// }
// int main(){
//     maxnmin(6,3,4);
//     return 0;
// }

// *******Define a program to find out whether a given 
// number is even or odd.
// int eno(int number){
//     if(number%2==0){
//         cout<<"The given number is even."<<endl;
//     }
//     else{
//         cout<<"The given number is odd."<<endl;
//     }
// }
// int main(){
//     int n;
//     cout<<"Enter your number: "<<endl;
//     cin>>n;
//     eno(n);
//     return 0;
// }

//**********Define a function to find out if number is prime or not
// bool prime(int num){
//     for (int i=2; i<num;i++){
//         if ((num % i)==0){
//             return false;
//         }
//     }return true;
// }
// int main(){
//     int n;
//     cout<<"Enter your name: "<<endl;
//     cin>>n;
//     cout<<prime(n);
//     return 0;
// }

// ********FACTORIAL
// int fac(int num){
//     int fact=1;
//     while (num>1){
//         fact=fact*num;
//         num=num-1;  
//     }return fact;
// }
// int main(){
//     cout<<"Enter your number: "<<endl;
//     int n;
//     cin>>n;
//     cout <<fac(n);
//     return 0; 
// }

// ******Write a function that takes your date of
// birth in YYYY, MM and DD format (separated by spaces) 
// as input as well as the current date, in same format, 
// and calculates your age in years, months .
// int age(float date,int month, int year){
//     int dt;  
//     cout<<"Your age in years is: "<<2022-year<<endl;
//     cout<<"Your age in months is: "<<((2022-year)*12)-month+12<<endl;
// }
// int main(){
//     age(1,9,2003);
//     return 0;
// }

// ******** PRIME FACTORS
// bool prime_factors(int num); //FUNCTION PROTOTYPE 
// int main(){
//     int n;
//     cout<<"Enter a number: "<<endl;
//     cin>>n;

//     for (int i=2;i<=n;i++){
//         if (n%i==0){
//             if (prime_factors(i)){//i IS A ACTUAL PARAMETER
//                 cout<<i<<" is a prime factor of "<<n<<endl;
//             }
//         }
//     }
//     return 0;
// }
// bool prime_factors(int num){// INT NUM IS A FORMAL PARAMETER
//     for (int i=2;i<num;i++){
//         if (num%i==0){
//             return false;
//         }
//     }return true;
    
// }

// **************INLINE FUNCTIONS ***************
/*INLINE FUNCTIONS ARE REQUEST TO THE COMPILER. WHICH SAYS THAT TO COPY THE SAME FUNCTON RATHER 
THAN PERFORMING IT AGAIN AND AGAIN WHICH RESULTS IN THE USE OF MEMORY AS WELL AS TIME. INLINE FUNCTIONS 
ARE USFULL IN THE CASE OF SMALL FUNCTIONS. THESE MAY BE FAIL. IT DEPENDS ON THE COMPILER, THE COMPILER
CAN REJECT IT. 
*/
// inline int product(int num1,int num2){
//     return num1*num2;
// }
// int main(){
//     cout<<product(2,4);
//     return 0;
// }

//**********DEFAULT ARGUMENTS************
/* THESE ARE SUPPOSE TO BE ON THE RIGHT MOST OF A FUNCTION ARGUMENT
*******EXAMPLE:
int pro(int num1,int num2,float num3=9){//in this num3 is a default 
    return num1*num2*num3;
}
int main(){
    cout<<pro(1,2)//no need to pass third parameter as it is already declared as default
    return 0;
}
*/

//*********CONSTANT ARGUMENTS*********
/* THESE ARE ARGUMENT WHICH ARE CONSTANT(UNCHANGEABLE). WE USE KEYWORD (const). 
IT TELLS THE COMPILER THAT THESE WORDS/VALUE WILL NEVER BE CHANGED.
******EXAMPLE:
float cir(int r,const float=3.142){
    pi=9; //THIS WILL PRODUCE AN ERROR, AS IT IS A CONSTANT.
    return 2*pi*r;
} 
int main(){
    cout<<cir(2);
    return 0;
}
*/
#include <iostream>
using namespace std;

class Shop
{
    string itemId[100];
    int itemPrice[100];
    int counter;

public:
    void initCounter(void) { counter = 0; }
    void setPrice(void);
    void displayPrice(void);
};

void Shop ::setPrice(void)
{
    cout << "Enter Id of your item no " << counter + 1 << endl;
    cin >> itemId[counter];
    cout << "Enter Price of your item" << endl;
    cin >> itemPrice[counter];
    counter++;
}

void Shop ::displayPrice(void)
{
    for (int i = 0; i < counter; i++)
    {
        cout << "The Price of item with Id " << itemId[i] << " is " << itemPrice[i] << endl;
    }
}

int main()
{
    Shop dukaan;
    dukaan.initCounter();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.displayPrice();
    return 0;
}