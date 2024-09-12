#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int marks, id;
    struct node *next;
};
struct node *start = NULL;

void insertAtHead()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    cin >> temp->id;
    temp->next = NULL;
    struct node *curr=NULL;
}

void insertion()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    cout << "Enter the id: ";
    cin >> temp->id;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        struct node *curr = start;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
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
bool search()
{
    if (start == NULL)
    {
        cout << "List is empty." << endl;
    }
    int toSearch;
    cout << "Enter the id you want to search: " << endl;
    cin >> toSearch;
    struct node *curr = start;
    while (curr != NULL)
    {
        if (curr->id == toSearch)
        {
            return true;
            break;
        }
        curr = curr->next;
    }
}
void deleteNode()
{
    if (start == NULL)
    {
        cout << "List is empty." << endl;
    }
    int todelete;
    cout << "Enter the id you want to delete: " << endl;
    cin >> todelete;
    struct node *curr = start;
    struct node *prev = NULL;
    while (curr != NULL)
    {
        if (curr->id == todelete)
        {
            prev->next = curr->next;
            free(curr);
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}
void deleteAll()
{
    struct node *curr = start;
    while (curr != NULL)
    {
        curr = curr->next;
        free(curr);
    }
    start = NULL;
}
int main()
{
    int inp = 0;

    while (inp != 4)
    {
        cout << "For input (1) \nFor printing (2) \nFor searching (3) \nFor Deleting a specific node (4) \nFor deleting the whole list (5) \nFor exiting from loop (6): ";
        cout << endl;
        cin >> inp;
        if (inp == 1)
        {
            insertion();
        }
        else if (inp == 2)
        {
            print();
        }
        else if (inp == 3)
        {
            cout << search();
        }
        else if (inp == 4)
        {
            deleteNode();
        }
        else if (inp == 5)
        {
            deleteAll();
        }
        else if (inp == 6)
        {
            cout << "Loop ended" << endl;
            break;
        }
        else
        {
            cout << "This operation doesn't exist." << endl;
        }
    }
}
