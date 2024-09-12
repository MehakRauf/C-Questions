#include <iostream>
using namespace std;
int main()
{

    // Write a program to print the area and perimeter
    // of a triangle having sides of 3, 4 and 5 units by
    // creating a class named 'Triangle' with the constructor
    // having the three parameters
    //  class Triangle{
    //      public:
    //      int s1, s2, s3;
    //      Triangle(int a ,int b,int c){  //Constructor
    //          s1=a;
    //          s2=b;
    //          s3=c;
    //      }
    //      void printarea(){
    //          double s=(s1+s2+s3)/2.0;
    //          cout<<"The area of the triangle is: "<<s<<endl;
    //          cout<<"The perimeter of the treiangle is: "<<(s1+s2+s3)<<endl;
    //      }
    //  };
    //  Triangle t(1,2,3);
    //  t.printarea();

    // Write a program to print the area of two rectangles having
    //  sides (4,5) and (5,8) respectively by creating a class named
    //  'Rectangle' with a function named 'Area' which returns the area.
    //  Length and breadth are passed as parameters to its constructor.

    // class Rectangle{
    //     public:
    //     int l,b;
    //     Rectangle(int length,int breadth){
    //         b=length;
    //         l=breadth;
    //     }
    //     void area(){
    //         cout<<"The area is: "<<l*b<<endl;
    //     }
    // };
    // int lr, br;
    // cout<<"Enter the length of the rectangle: ";
    // cin>>lr;
    // cout<<endl;
    // cout<<"Enter the breadth of the rectangle: ";
    // cin>>br;
    // cout<<endl;
    // Rectangle r(lr,br);
    // r.area();

    //Write a program to print the area of a rectangle by creating a 
    //class named 'Area' taking the values of its length and breadth as 
    //parameters of its constructor and having a function named 'returnArea' 
    //which returns the area of the rectangle. 
    //Length and breadth of the rectangle are entered through keyboard.

    class Area{
        public:
        int length,breadth;
        Area (int l,int b){
            length=l;
            breadth=b;
        }
        int returnArea(){
            return length*breadth;
        }
    };
    int l,b;
    cout<<"Enter the length of the rectangle: "<<endl;
    cin>>l;
    cout<<"Enter the breadth of the rectangle: "<<endl;
    cin>>b;
    Area a(l,b);
    cout<<"The area of the recatngle is: "<<a.returnArea()<<endl;
    return 0;
}