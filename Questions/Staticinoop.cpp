#include <iostream>
using namespace std;

// Print the average of three numbers entered by the user by
// creating a class named 'Average' having a function to calculate
// and print the average without creating any object of the Average class.

// class Average{
//     public:
//     static int Avg(float n1,float n2, float n3){ // static function
//         float avgr=(n1+n2+n3)/3;
//         return avgr;
//     }
// };

// int main()
// {
//     int n1,n2,n3;
//     cout<<"Enter the value of n1: "<<endl;
//     cin>>n1;
//     cout<<"Enter the value of n2: "<<endl;
//     cin>>n2;
//     cout<<"Enter the value of n3: "<<endl;
//     cin>>n3;
//     cout<<Average :: Avg (n1,n2,n3)<<endl;
//     return 0;
// }

// Grocery list with items id, ,name, price and the total number of items
// class Grocery
// {
//     static int item_number;
//     int item_total;
//     static int item_id;
//     int item_price[100];
//     string item_name[100];

// public:
//     void get_data(void);
//     void display_data(void);
//     void total(void);
// };
// int Grocery ::item_number = 0;
// int Grocery ::item_id = 1;
// void Grocery ::total(void)
// {
//     cout << "Enter the total number of entries you want: " << endl;
//     cin >> item_total;
// }
// void Grocery ::get_data(void)
// {
//     while (item_number < item_total)
//     {
//         cout << "The id of your item is: " << item_id << endl;
//         cout << "Enter the name of the item: " << endl;
//         cin >> item_name[item_number];
//         cout << "Enter the item price: " << endl;
//         cin >> item_price[item_number];
//         item_number++;
//         item_id++;
//     }
// }
// void Grocery :: display_data(void)
// {
//     for (int i = 0; i <= item_number; i++)
//     {

//         cout << item_name[i] << "   " << item_price[i] << endl;
//     }
// }
// int main()
// {
//     Grocery gro;
//     gro.total();
//     gro.get_data();
//     cout << "Your grocery list is as follows:" << endl;
//     cout << "NAME "
//          << "  "
//          << " PRICE "
//          << "  " << endl;
//     gro.display_data();
//     return 0;
// }
