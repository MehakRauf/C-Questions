#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

struct node
{
    int id;
    struct node *next = NULL;
    struct node *prev = NULL;
};
struct node *start = NULL;

void insertion(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->id=value;
    temp->next = NULL;
    struct node *curr = start;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }
}

void print()
{
    if (start == NULL)
    {
        cout << "List is empty." << endl;
    }
    struct node *curr = start;
    while (curr != NULL)
    {
        cout << curr->id << " ";
        curr = curr->next;
    }
    cout << endl;
}

int reverse()
{
    int i = 1;
    struct node *curr = start;
    while (curr->next != NULL)
    {
        curr = curr->next;
        i++;
    }
    if (i < 3)
    {
        return -1;
    }
    else
    {
        int j=1;
        while (curr != NULL)
        {
            if (j == 3)
            {
                return curr->id;
                break;
            }
            curr = curr->prev;
            j++;
        }
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
       insertion(value);
        
    }
}
int main(){
    READ();
    int val=reverse();
    if(val==-1){
        cout<<"The size of list is less than three "<<val<<endl;
    }
    else{
        cout<<"The third last value is: "<<val;
    }
}