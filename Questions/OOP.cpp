#include <iostream>
using namespace std;
// Write a program that would print the information
//(name, year of joining, salary, address) of three
// employees by creating a class named 'Employee'.
// The output should be as follows:
// Name        Year of joining        Address
// Robert        1994        64C- WallsStreat
// Sam        2000        68D- WallsStreat
// John        1999        26B- WallsStreat

// class Employee
// {
//     string name[100];
//     int salary[100];
//     int counter;
//     int year[100];
//     string address[100];

// public:
//     void initCounter(void) { counter = 0; }
//     void setData(void);
//     void displayData(void);
// };

// void Employee ::setData(void)
// {
//     cout << "Enter your name: " << endl;
//     cin >> name[counter];
//     cout << "Enter your salary: " << endl;
//     cin >> salary[counter];
//     cout << "Enter your address: " << endl;
//     cin >> address[counter];
//     cout << "Enter your year: " << endl;
//     cin >> year[counter];
//     counter++;
// }

// void Employee ::displayData(void)

// {
//     cout << "Name"
//          << "  "
//          << "Salary"
//          << "  "
//          << "Address"
//          << "  "
//          << "Year"
//          << "  " << endl;
//     for (int i = 0; i < counter; i++)
//     {
//         // cout << "Name of the employeee: " << name[i] << endl;
//         // cout<<"Salary of the employee: "<<salary[i]<<endl;
//         // cout << "Address of the employee: "<<address[i] << endl;
//         // cout<<"Year of joining of the employee: "<<year[i]<<endl;
//         cout << name[i] << "  " << salary[i] << "   " << address[i] << "   " << year[i] << "   " << endl;
//     }
// }

// int main()
// {
//     int n;
//     cout << "Enter the number of employees: " << endl;
//     cin >> n;
//     Employee hi;
//     hi.initCounter();
//     for (int i = 0; i < n; i++)
//     {
//         hi.setData();
//     }
//     hi.displayData();
//     return 0;
// }
// Create a class named 'Student' with a string variable
// 'name' and an integer variable 'roll_no'. Assign the
// value of roll_no as '2' and that of name as "John"
// by creating an object of the class Student.

// class student {
//     public:
//     string name;
//     int roll_no;
// };
// student s1;
// s1.name="John";
// s1.roll_no=2;

// Write a program to print the area and perimeter of a triangle having sides
// of 3, 4 and 5 units by creating a class named 'Triangle' with a function
// to print the area and perimeter.

// class Triangle{
//     public:
//     int a,b,c;
//     float areanperimeter(int a,int b, int c){
//         cout<<"The area of triangle is: "<<(a*b)/2<<endl;
//         cout<<"The area of perimeter is: "<<a+b+c<<endl;
//     }
// };
//     Triangle harry;
// harry.areanperimeter(3,4,5);

// Assign and print the roll number, phone number and address
// of two students having names "Sam" and "John" respectively
// by creating two objects of the class 'Student'.

// class students{
//     public:
//     string names[2];
//     string address[2];
//     int phone_number[2];
// };
// students hi;
// for (int i=0;i<2;i++){
//     cout<<"Enter the name: "<<endl;
//     cin>>hi.names[i];
//     cout<<"Enter the address: "<<endl;
//     cin>>hi.address[i];
//     cout<<"Enter the phone number: "<<endl;
//     cin>>hi.phone_number[i];
// }
// for (int i=0;i<2;i++){
//     cout<<"The name of the student is: "<<hi.names[i]<<endl;
//     cout<<"The address of the student is: "<<hi.address[i]<<endl;
//     cout<<"The phone_number of the student is: "<<hi.phone_number[i]<<endl;

// }

// Write a program to print the area of a rectangle by creating a
// class named 'Area' having two functions. First function named as
//'setDim' takes the length and breadth of the rectangle as parameters
// and the second function named as 'getArea' returns the area of the
// rectangle. Length and breadth of the rectangle are entered through keyboard.

// class Area
// {
//     public:
//     int l, b, length, breadth;
//     void setDim()
//     {
//         length = l;
//         breadth = b;
//     }
//     void getArea()
//     {
//         cout<<"The area of the Rectangle is: "<< length*breadth<<endl;
//     }
// };
// Area a;

// cout<<"Enter the length of the recatngle: "<<endl;
// cin>>a.l;
// cout<<"Enter the breadth of the recatngle: "<<endl;
// cin>>a.b;
// a.setDim();
// a.getArea();

//     return 0;
// }
// Write a program by creating an 'Employee' class having the
// following functions and print the final salary.
// 1 - 'getInfo()' which takes the salary, number of hours of work per day of employee as parameters
// 2 - 'AddSal()' which adds $10 to the salary of the employee if it is less than $500.
// 3 - 'AddWork()' which adds $5 to the salary of the employee if the number of hours of work per
// day is more than 6 hours.

// class Employee
// {
//     int salary;
//     int hours;
//     int s;
//     int h;

// public:
//     int getInfo(int salary, int hours)
//     {
//         s = salary;
//         h = hours;
//     }
//     void addsal()
//     {
//         if (s < 500)
//         {
//             s = s + 10;
//             cout << "On the basis of salary" << s << endl;
//         }
//         else
//         {
//             cout << "On the basis of salary" << s << endl;
//         }
//     }
//     void addWork()
//     {
//         if (h > 6)
//         {
//             cout << "On the basis of working hours" << s + 5 << endl;
//         }
//         else
//         {
//             cout << "On the basis of working hours" << s << endl;
//         }
//     }
// };
// int main()
// {
//     Employee sal;
//     int salary, hours;
//     cout << "Enter your salary: " << endl;
//     cin >> salary;
//     cout << "Enter your working hours per day: " << endl;
//     cin >> hours;
//     sal.getInfo(salary, hours);
//     sal.addsal();
//     sal.addWork();
//     return 0;
// }
