#include <iostream>
#include <stack>
using namespace std;

struct node
{
    int id;
    struct node *next = NULL;
    struct node *prev = NULL;
};
struct node *start = NULL;
void insertion()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    cout << "Enter the id: " << endl;
    cin >> temp->id;
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