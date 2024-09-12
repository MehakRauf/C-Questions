#include <iostream>
using namespace std;

struct node
{
    int id;
    struct node *next = NULL;
    struct node *prev = NULL;
};
struct node *start = NULL;

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
            if (curr2->id >curr2->next->id)
            {
                swap(curr2->id,curr2->next->id);
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
        median=(prev->id+prev->next->id)/2.0;
        cout<<"The median is: " << median<<endl;
    }
    else{
        cout<<"The median is: " <<curr->id<<endl;
    }
}
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
void insertAtHead()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    cout << "Enter the id: " << endl;
    cin >> temp->id;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        start->prev = temp;
        temp->next = start;
        start = temp;
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

void search()
{
    int toSearch;
    cout << "Enter the id you want to searhc: " << endl;
    cin >> toSearch;
    struct node *curr = start;
    while (curr != NULL)
    {
        if (curr->id == toSearch)
        {
            break;
        }
        else
        {
            curr = curr->next;
        }
    }
    if (curr == NULL)
    {
        cout << "The element is not found." << endl;
    }
    else
    {
        cout << "The value is found " << endl;
    }
}
void AddAtIndex()
{
    int index;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    cout << "Enter the index: ";
    cin >> index;
    cout << "Enter the id: ";
    cin >> temp->id;
    struct node *curr = start;
    // make a temp node and traverse to the
    //   node previous to the position
    for (int i = 1; i < index - 1; i++)
    {
        if (curr != NULL)
        {
            curr = curr->next;
        }
    }

    // 5. If the previous node is not null, adjust
    //    the links
    if (curr != NULL)
    {
        temp->next = curr->next;
        temp->prev = curr;
        curr->next = temp;
        if (temp->next != NULL)
            temp->next->prev = temp;
    }
    else
    {

        // 6. When the previous node is null
        cout << "\nThe previous node is null.";
    }
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
        while (curr != NULL)
        {
            if (i == 3)
            {
                return curr->id;
                break;
            }
            curr = curr->prev;
        }
    }
}

int main()
{
    insertion();
    insertion();
    insertion();
    print();
    sort();
    print();
    median();
    insertion();
    print();
    sort();
    print();
    median();
}