#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

struct node
{
    int num;
    struct node *next;
};
struct node *start = NULL;
void ADD(int value)
{
    struct node *curr1;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->num = value;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        curr1 = start;
        while (curr1->next != NULL)
        {
            curr1 = curr1->next;
        }
        curr1->next = temp;
    }
}
void sort()
{
    struct node *curr2 ;
    struct node *curr1=NULL;
    bool swapped;
    //bubble sort algorithm
    do
    {
        swapped = false; 
        curr2=start;
        while (curr2->next != curr1)
        {
            if (curr2->num >curr2->next->num)
            {
                swap(curr2->num,curr2->next->num);
                swapped=true;
            }
            curr2 = curr2->next;
        }
        curr1=curr2;
    } while (swapped);
}
void median(){
    float median;
    struct node* curr=start;
    struct node* runner=start;
    struct node *prev=NULL;
    while(runner!=NULL && runner->next!=NULL){
        runner=runner->next->next;
        prev=curr;
        curr=curr->next;
    }
    if(runner==NULL){
        median=(prev->num+prev->next->num)/2.0;
        cout<<"The median is: " << median<<endl;
    }
    else{
        cout<<"The median is: " <<curr->num<<endl;
    }
}
void READ()
{
    string filepath;
    cout << "Enter the file path ";
    getline(cin, filepath);
    ifstream inputFile(filepath);
    if (!inputFile)
    {
        cout << "Error";
        return;
    }
    int value;
    while (inputFile >> value)
    {
        if (value<0 || value>100){
            continue;
        }
        ADD(value);
        sort();
        median();
    }
}
void PRINT()
{
    if (start == NULL)
    {
        cout << "List is empty.";
    }
    struct node *curr = start;
    while (curr != NULL)
    {
        cout << curr->num << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    READ();
    PRINT();
}