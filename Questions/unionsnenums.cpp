#include <iostream>
using namespace std;
int main(){
    // UNION IS GOOD FOR MEMORY MANAGEMENT
    // AS IT WILL VANISH THE OLD VALUE BY OVERWRITING 
    //THAT'S WHY IT IS USED OVER STRUCTURE
//     union name
//     {
//         int marks;
//         int age;
//         int rollno;
//     };
//     union name n1;
//     cout<<"Enter the age: "<<endl;
//     cin>>n1.age;
//     cout<<"Enter the marks: "<<endl;
//     cin>>n1.marks;
//     cout<<"Enter the roll no. : "<<endl;
//     cin>>n1.rollno;

//     cout<<"The age is: "<<n1.age<<endl; //it will print garbage value 
//     cout<<"The marks are: "<<n1.marks<<endl; //it will also print garbage value
//     cout<<"The roll no. is: "<<n1.rollno<<endl;
// // The output by putting input as 1 2 3
//     The age is: 3
// The marks are: 3
// The roll no. is: 3

// ENUMERATE
// SET OF FIXEED CONSTANTS
// enum hi{
//     dua,hira,aleena,aaraaf,fiza
// };
// hi m1=dua;
// cout<<(m1==0);//WILL RETURN IS IT TRUE OR NOT
// cout<<hira;//IT WILL GIVE THE LOCATION OF HIRA IN ENUM (As 0,1,2....)
// cout<<aleena;
// cout<<aaraaf;
// cout<<fiza;
    return 0;
}