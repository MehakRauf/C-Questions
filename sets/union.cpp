#include <iostream>
#include <stdlib.h>
using namespace std;

struct List1
{
    int data1;
    struct List1 *next1;
};

struct List2
{
    int data;
    struct List2 *next;
};
struct List3
{
    int data3;
    struct List3 *next3;
};
struct List1 *start = NULL;
struct List2 *start2 = NULL;
struct List3 *start3 = NULL;

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

void insert_list2(int value)
{
    struct List2 *temp = (struct List2 *)malloc(sizeof(struct List2));
    temp->data = value;
    temp->next = NULL;
    if (start2 == NULL)
    {
        start2 = temp;
        return;
    }
    else
    {
        struct List2 *curr = start2;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}
void insert_list3(int value)
{
    struct List3 *temp = (struct List3 *)malloc(sizeof(struct List3));
    temp->data3 = value;
    temp->next3 = NULL;
    if (start3 == NULL)
    {
        start3 = temp;
        return;
    }
    else
    {
        struct List3 *curr = start3;
        while (curr->next3 != NULL)
        {
            curr = curr->next3;
        }
        curr->next3 = temp;
    }
}
void compare_values(int value)
{
    struct List3 *curr = start3;
    while (curr != NULL)
    {
        if (curr->data3 == value)
        {
            return;
        }
        curr = curr->next3;
    }
    insert_list3(value);
    return;
}
void union_sets()
{
    struct List1 *curr1 = start;
    while (curr1 != NULL)
    {
        insert_list3(curr1->data1);
        curr1 = curr1->next1;
    }
    struct List2 *curr2 = start2;
    while (curr2 != NULL)
    {
        compare_values(curr2->data);
        curr2 = curr2->next;
    }
}
void print()
{
    struct List3 *curr = start3;
    cout<<"The union of both the sets is: "<<endl;
    while (curr != NULL)
    {
        cout << curr->data3<<" ";
        curr = curr->next3;
    }
    cout<<endl;
}
int main()
{
    insert_list1(1);
    insert_list1(3);
    insert_list1(4);
    insert_list1(7);
    insert_list1(12);
    insert_list2(1);
    insert_list2(5);
    insert_list2(7);
    insert_list2(9);
    union_sets();
    print();
}