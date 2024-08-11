#include <iostream>
#include <stdlib.h>
using namespace std;

struct List1
{
    int data1;
    struct List1 *next1;
};

struct List3
{
    int data3;
    struct List3 *next3;
};
struct List1 *start = NULL;

void insert_list1(int value)
{
    struct List1 *temp = (struct List1 *)malloc(sizeof(struct List1));
    temp->data1 = value;
    temp->next1 = NULL;
    if (start == NULL)
    {
        start = temp;
        return;
    }
    else
    {
        struct List1 *curr = start;
        while (curr->next1 != NULL)
        {
            curr = curr->next1;
        }
        curr->next1 = temp;
    }
}

void customized_insertion(struct List1 *add, int v2)
{
    struct List1 *temp=(struct List1*)malloc(sizeof(struct List1));
    temp->data1=v2;
    temp->next1=add->next1;
    add->next1=temp;
}

void customized(int v1, int v2)
{
    struct List1 *curr1 = start;
    while (curr1 != NULL)
    {
        if (curr1->data1 == v1)
        {
            customized_insertion(curr1,v2);
        }
        curr1=curr1->next1;
    }
}
void print(){
    struct List1* curr=start;
    while(curr!=NULL){
        cout<<curr->data1<<" ";
        curr=curr->next1;
    }
    cout<<endl;
}
int main()
{
    insert_list1(2);
    insert_list1(4);
    insert_list1(3);
    insert_list1(2);
    insert_list1(8);
    insert_list1(2);
    insert_list1(5);
    insert_list1(1);
    insert_list1(2);
    customized(2,10);
    print();
}