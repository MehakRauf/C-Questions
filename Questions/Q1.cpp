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

void GetTrump()
{
    struct node *curr = start;
    struct node *runner = start;
    struct node *prev = NULL;
    while (runner != NULL && runner->next != NULL)
    {
        prev = curr;
        curr = curr->next;
        runner = runner->next->next;
    }
    if (runner == NULL)
    {
        cout<<"The middle values are: "<<endl;
        cout << prev->num << " " << prev->next->num << endl;
    }
    else
    {
        cout<<"The middle element is: "<<endl;
        cout << curr->num;
    }
}

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
void DELETE()
{
    if (start == NULL)
    {
        cout << "No elements to be deleted." << endl;
    }
    else if (start->next == NULL)
    {
        start = NULL;
    }
    else
    {
        struct node *curr = start;
        struct node *prev = NULL;
        while (curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        free(curr);
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

    string command;
    int value;
    while (inputFile >> command)
    {
        if (command == "ADD")
        {
            if (inputFile >> value)
            {
                ADD(value);
            }
        }
        else if (command == "DELETE")
        {
            DELETE();
        }
        else
        {
            struct node *curr = start;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            struct node *END = curr;
        }
    }
    inputFile.close();
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
    GetTrump();
}
