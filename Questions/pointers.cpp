#include<iostream>
using namespace std;
// for swapping to numbers 
void swap(int *p1, int *p2){
    int t=*p1;
    *p1=*p2;
    *p2=t;
}
//array elemnts to input the array elements
void arrayIn(int *p){
    for(int i=0; i<10; i++){
        cout<<"Enter the "<<i+1<<" element: ";
        cin>>p[i];
    }
    for(int i=0; i<10; i++){
        cout<<*p<<endl;
        p++;
    }
}
//array elements printing using pointers
void arrayInput(int *p){
    for (int i=0; i<10; i++){
        cout<< *p<<"\t";
        // this will increment to the size of its data type in case this will increment
        // by 4 bytes as int is normally of 4 bytes
        p++;
    }
}

//struct
struct student {
        int id;
        int marks;
        float gp;
    };
int main(){
    //********* input an array and print it
    // int arr[10];
    // arrayIn(arr);

    //**********STRUCTS
    // student st1;
    // cout<<"Enter the id: ";
    // cin>>st1.id;
    // cout<<"Enter the marks: ";
    // cin>>st1.marks;
    // cout<<endl;
    // cout<<"Enter the gpa: ";
    // cin>>st1.gp;
    // cout<<endl;
    // cout<<st1.id<<endl;
    // cout<<st1.marks<<endl;
    // cout<<st1.gp<<endl;

    //**************struct with arrays
    // student st1[5];
    // for(int i=0; i<5; i++){
    //     cout<<"Enter the id: ";
    //     cin>>st1[i].id;
    //     cout<<endl;
    //     cout<<"Enter the marks: ";
    //     cin>>st1[i].marks;
    //     cout<<endl;
    //     cout<<"Enter the gp: ";
    //     cin>>st1[i].gp;
    //     cout<<endl;

    // }
    // cout<<"Applying linear search."<< endl;
    // int toSearch, index;
    // bool flag;
    // cout<<"Enter the id you want to search: ";
    // cin>>toSearch;
    // for(int i=0; i<5; i++){
    //     if(st1[i].id == toSearch){
    //         flag=true;
    //         index=i;
    //     }
    // }
    // if(flag== true){
    //     cout<<"the id is found at "<<index<<endl;
    // }
    // else{
    //     cout<<"The id is not found. "<<endl;
    // }
    // for(int i=0; i<5; i++){
    //     cout<<"The id is: "<<st1[i].id <<endl;
    //     cout<<"The marks are: "<<st1[i].marks <<endl;
    //     cout<<"The gp is: "<<st1[i].gp <<endl;

    // }

//MALLOC(memory allocation) WITH STRUCTS
    //struct student* p = (struct student*) malloc(sizeof(struct student));

    // p->id=90;
    // p->marks=34;
    // p->gp=4.0;
    // cout<<p->gp;
    // cout<<p->marks;

    // *************for swapping to numbers without returning their values and using them.
    // int x=1, y=9;
    // swap(&x, &y);
    // cout<<x<< endl;
    // cout<<y<<endl;

    //************************ for pritnig the elements of an array with poiters
    // int arr[10]={1,2,3,4,5,6,7,8,9,0};
    // arrayInput(arr);


// int num1=999,num2=10000,num3=2180989;
// int *p1=&num1, *p2=&num2,*p3=&num3;
// cout<<"*************the pointers"<<endl;
// cout<<"The value of a is: "<<a<<endl;
// cout<<"The memory location is "<<&b<<endl;
// cout<<"The value using pointer is: "<<*b<<endl;

// cout<<"***************the address of the pointer itself"<<endl;
// cout<<&b<<endl;

// *************FINDING MAX OF THREE USING POINTERS
// if ((*p1>*p2) && (*p1>*p3)){
//     cout<<num1<<" is greatest of all.";
// }
// else if ((*p2>*p3) && (*p2>*p1)){
//     cout<<num2<<" is greatest of all.";
// }
// else{
//     cout<<num3<<" is greatest of all"<<endl;
// }

// *****************FACTORIAL USING POINTER
// int fac=1, i=1, num;
// cin>>num;
// int *p=&num;
// while (i<=*p){
//     fac=i*fac;
//     i++;
// }
// cout<<fac;

// *********************REVERSING A NUMBER
// int n, reversed=0,remainder;
// cin>>n;
// int *p=&n;
// while(*p!=00){
//     remainder=*p%10;
//     reversed=reversed*10+remainder;
//     n/=10;
// }cout<<reversed;



return 0; 
}