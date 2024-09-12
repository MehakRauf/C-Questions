#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

struct node
{
    int id;
    struct node *next;
    struct node *prev = NULL;
};
struct node *start = NULL;
struct node *MoveForward = NULL;
struct node *MoveBackward;

void insertAtpos(int steps, int value)
{
    struct node *curr = start;
    for (int i = 0; i < steps; i++)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->id = value;
        temp->next = curr->next;
        curr->next->prev = temp;
        curr->next = temp;
        temp->prev = curr;
    }
    if (start == NULL)
    {
        cout << "List is empty." << endl;
    }
    struct node *curr1 = start;
    while (curr1 != NULL)
    {
        cout << curr1->id << " ";
        curr1 = curr1->next;
    }
    cout << endl;
}
void insertion(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->id = value;
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
    if (start == NULL)
    {
        cout << "List is empty." << endl;
    }
    struct node *curr1 = start;
    while (curr1 != NULL)
    {
        cout << curr1->id << " ";
        curr1 = curr1->next;
    }
    cout << endl;
}
void insertAtHead(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->id = val;
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
void print()
{
    // if (start == NULL)
    // {
    //     cout << "List is empty." << endl;
    // }
    // struct node *curr = start;
    // while (curr != NULL)
    // {
    //     cout << curr->id << " ";
    //     curr = curr->next;
    // }
    // cout << endl;
}
void MoveForward_steps(int steps)
{
    MoveForward = start;
    struct node *curr = start;
    for (int i = 0; i <= steps; i++)
    {
        if (i == steps)
        {
            MoveForward = curr;
        }
        curr = curr->next;
    }
    cout << "Moved the cursor by: " << steps << " steps." << endl;
    cout << "MoveForward: " << MoveForward->id << endl;
}
void Backward_steps(int steps)
{
    MoveBackward = MoveForward;
    for (int i = 0; i <= steps; i++)
    {
        if (i == steps)
        {
            break;
        }
        MoveBackward = MoveBackward->prev;
    }
    cout << "MoveBackward" << MoveBackward->id << endl;
}

void AddImmediate_number(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->id = val;
    temp->next=NULL;
    if(MoveForward==NULL){
        insertAtpos(1,val);
    }
    else if(MoveForward->next==NULL){
        insertion(val);
    }
    else{
        
            temp->id = val;
            temp->prev = MoveForward;
            temp->next = MoveForward->next;
            MoveForward->next->prev = temp;
            MoveForward->next = temp;
    }
    // if (MoveForward == NULL)
    // {
    //     MoveForward = start;
    //     temp->next = MoveForward->next;
    //     temp->prev = MoveForward;
    //     MoveForward->next = temp;
    //     MoveForward->next->prev = temp;
    //     return;
    // }

    // else if (MoveForward->next == NULL)
    // {
    //     MoveForward->next = temp;
    //     temp->prev = MoveForward;
    // }
    // else
    // {

    //     temp->next = MoveForward->next;
    //     temp->prev = MoveForward;
    //     MoveForward->next = temp;
    //     return;
    // }
}
void Deletion()
{
    struct node *curr = start;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->prev->next->next = NULL;
    free(curr);
}
void deleteAtIndex(int index)
    {
        if (index < 1 )
        {
            cout << "Invalid index\n";
        }
        else if (index == 1)
        {
            if (start == NULL)
            {
                cout << "List is empty\n";
            }
            else if (start->next==NULL)
            {
                free(start);
                start = NULL;
            }
            else
            {
                struct node *temp = start;
                start = start->next;
                start->prev = NULL;
                free( temp);
            }
        }
        else if (MoveForward->next==NULL)
        {
            Deletion();
        }
        else
        {
            struct node *temp = start;
            for (int i = 1; i < index; i++)
            {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free( temp);
            MoveForward = temp->prev;
        }
    }
void DeleteImmediate()
{

    //   if (MoveForward == start)
    //     {
    //         deleteAtIndex(1);
    //     }
    //     else if (cursor == tail)
    //     {
    //         deleteTail();
    //     }
    //     else
    //     {
    //         Node *temp = cursor;
    //         cursor->prev->next = cursor->next;
    //         cursor->next->prev = cursor->prev;
    //         cursor = cursor->prev;
    //         delete temp;
    //     }

    if (MoveForward == start)
    {
        start = start->next;
        free(MoveForward);
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
        return;
    }
    MoveForward->prev->next = MoveForward->next;
    free(MoveForward);
}



void Update_index_number(int pos, int val)
{
    int i = 0;
    struct node *curr = start;
    while (curr != NULL)
    {
        if (i == pos)
        {
            curr->id = val;
            break;
        }
        curr = curr->next;
    }
}
void UpdateImmediate_number()
{
    int updatenum;
    cout << "Enter the number: " << endl;
    cin >> updatenum;
    MoveForward->next->id = updatenum;
}
void Shift_index()
{
    MoveForward->next->id = MoveForward->id;
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
    int pos_val;
    string command;
    int value;
    while (inputFile >> command)
    {
        if (command == "Add")
        {
            if (inputFile >> value)
            {
                if (value > 1)
                {
                    insertion(value);
                    print();
                }
                else
                {
                    inputFile >> pos_val;
                    insertAtpos(value, pos_val);
                    print();
                }
            }
        }
        else if (command == "Print")
        {
            print();
        }
        else if (command == "MoveForward")
        {
            int steps;
            inputFile >> steps;
            MoveForward_steps(steps);
        }
        else if (command == "AddImmediate")
        {
            int val;
            inputFile >> val;
            AddImmediate_number(val);
        }
        else if (command == "DeleteImmediate")
        {
            DeleteImmediate();
        }
        else if (command == "Update")
        {
            int pos, val;
            inputFile >> pos;
            inputFile >> val;
            Update_index_number(pos, val);
        }
        else if (command == "Delete")
        {
            Deletion();
            print();
        }
        else if (command == "MoveBackward")
        {
            int steps;
            inputFile >> steps;
            Backward_steps(steps);
        }
        else if (command == "Undo")
        {
            cout << "Undo" << endl;
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
int main()
{
    READ();
}