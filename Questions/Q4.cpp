#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

struct node
{
    int num;
    struct node *next;
    struct node *prev;
};
struct node *start = NULL;
struct node *MoveForward = NULL;
struct node *MoveBackward = NULL;

void Add_number(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->num = value;
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
        temp->prev = curr;
    }
}
void Print()
{
    cout << MoveForward->num << endl;
}
void Delete()
{
    struct node *curr = start;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->prev->next->next = NULL;
    free(curr);
}
void Delete_index(int index)
{
    struct node *curr = start;
    for (int i = 0; i <= index; i++)
    {
        if (i == index)
        {
            if (i == 0)
            {
                start = start->next;
                free(curr);
                return;
            }
            else
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                free(curr);
                return;
            }
        }
        curr = curr->next;
    }
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
    cout << "MoveForward: " << MoveForward->num << endl;
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
    cout << "MoveBackward" << MoveBackward->num << endl;
}
void AddImmediate_number(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->num = val;
    if (MoveForward == NULL)
    {
        MoveForward = start;
        temp->next = MoveForward->next;
        temp->prev = MoveForward;
        MoveForward->next = temp;
        MoveForward->next->prev = temp;
        return;
    }
    else
    {
        temp->next = MoveForward->next;
        temp->prev = MoveForward;
        MoveForward->next = temp;
        return;
    }
}
void DeleteImmediate()
{
    if (MoveForward == start)
    {
        start = start->next;
        free(MoveForward);
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
            curr->num = val;
            break;
        }
        curr = curr->next;
    }
}
void UpdateImmediate_number(int num)
{
    MoveForward->next->num = num;
}
void Shift_index()
{
    MoveForward->next->num = MoveForward->num;
}
void Undo()
{
    cout<<"UNDO"<<endl;
}
void insertAtpos(int steps, int value)
{
    struct node *curr = start;
    for (int i = 0; i < steps; i++)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->num = value;
        temp->next = curr->next;
        curr->next->prev = temp;
        curr->next = temp;
        temp->prev = curr;
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
                    Add_number(value);
                }
                else
                {
                    inputFile >> pos_val;
                    insertAtpos(value, pos_val);
                }
            }
        }
        else if (command == "Print")
        {
            Print();
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
            Delete();
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