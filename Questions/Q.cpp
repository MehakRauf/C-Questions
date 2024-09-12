// #include <iostream>
// #include <fstream>
// #include <stdlib.h>
// using namespace std;

// struct node
// {
//     int id;
//     struct node *next;
//     struct node *prev = NULL;
// };
// struct node *start = NULL;
// struct node *MoveForward = NULL;
// struct node *MoveBackward;

// void insertion(int value)
// {
//     struct node *temp = (struct node *)malloc(sizeof(struct node));
//     temp->id = value;
//     temp->next = NULL;
//     struct node *curr = start;
//     if (start == NULL)
//     {
//         start = temp;
//     }
//     else
//     {
//         while (curr->next != NULL)
//         {
//             curr = curr->next;
//         }
//         curr->next = temp;
//         temp->prev = curr;
//     }
//     if (start == NULL)
//     {
//         cout << "List is empty." << endl;
//     }
//     struct node *curr1 = start;
//     while (curr1 != NULL)
//     {
//         cout << curr1->id << " ";
//         curr1 = curr1->next;
//     }
//     cout << endl;
// }
// void Deletion()
// {
//     struct node *curr = start;
//     while (curr->next != NULL)
//     {
//         curr = curr->next;
//     }
//     curr->prev->next->next = NULL;
//     free(curr);
// }
// void insertAtpos(int steps, int value)
// {
//     struct node *curr = start;
//     for (int i = 0; i < steps; i++)
//     {
//         struct node *temp = (struct node *)malloc(sizeof(struct node));
//         temp->id = value;
//         temp->next = curr->next;
//         curr->next->prev = temp;
//         curr->next = temp;
//         temp->prev = curr;
//     }
//     if (start == NULL)
//     {
//         cout << "List is empty." << endl;
//     }
//     struct node *curr1 = start;
//     while (curr1 != NULL)
//     {
//         cout << curr1->id << " ";
//         curr1 = curr1->next;
//     }
//     cout << endl;
// }
// void deleteAtIndex(int index)
// {
//     if (index < 1)
//     {
//         cout << "Invalid index\n";
//     }
//     else if (index == 1)
//     {
//         if (start == NULL)
//         {
//             cout << "List is empty\n";
//         }
//         else if (start->next == NULL)
//         {
//             free(start);
//             start = NULL;
//         }
//         else
//         {
//             struct node *temp = start;
//             start = start->next;
//             start->prev = NULL;
//             delete temp;
//             MoveForward = start;
//         }
//     }

//     else
//     {
//         struct node *temp = start;
//         for (int i = 1; i < index; i++)
//         {
//             temp = temp->next;
//         }
//         temp->prev->next = temp->next;
//         temp->next->prev = temp->prev;
//         free(temp);
//         MoveForward = temp->prev;
//     }
// }

// void MoveForward_steps(int steps)
// {
//     MoveForward = start;
//     struct node *curr = start;
//     for (int i = 0; i <= steps; i++)
//     {
//         if (i == steps)
//         {
//             MoveForward = curr;
//         }
//         curr = curr->next;
//     }
//     cout << "Moved the cursor by: " << steps << " steps." << endl;
//     cout << "MoveForward: " << MoveForward->id << endl;
// }
// void Backward_steps(int steps)
// {
//     MoveBackward = MoveForward;
//     for (int i = 0; i <= steps; i++)
//     {
//         if (i == steps)
//         {
//             break;
//         }
//         MoveBackward = MoveBackward->prev;
//     }
//     cout << "MoveBackward" << MoveBackward->id << endl;
// }
// void AddImmediate_number(int val)
// {
//     struct node *temp = (struct node *)malloc(sizeof(struct node));
//     temp->id = val;
//     temp->next = NULL;
//     if (MoveForward == NULL)
//     {
//         insertAtpos(1, val);
//     }
//     else if (MoveForward->next == NULL)
//     {
//         insertion(val);
//     }
//     else
//     {
//         temp->prev = MoveForward;
//         temp->next = MoveForward->next;
//         MoveForward->next->prev = temp;
//         MoveForward->next = temp;
//     }
// }
// void DeleteImmediate()
// {
//     if (MoveForward == start)
//     {
//         start = start->next;
//         free(MoveForward);
//         if (start == NULL)
//         {
//             cout << "List is empty." << endl;
//         }
//         struct node *curr = start;
//         while (curr != NULL)
//         {
//             cout << curr->id << " ";
//             curr = curr->next;
//         }
//         cout << endl;
//         return;
//     }
//     MoveForward->prev->next = MoveForward->next;
//     free(MoveForward);
// }
// int printCursorData()
// {
//     if (MoveForward != NULL)
//     {
//         return MoveForward->id;
//     }
//     else
//     {
//         cout << "No data present at cursor\n";
//         return -1;
//     }
// }
// void Update_index_number(int pos, int val)
// {
//     int i = 0;
//     struct node *curr = start;
//     while (curr != NULL)
//     {
//         if (i == pos)
//         {
//             curr->id = val;
//             break;
//         }
//         curr = curr->next;
//     }
// }
// void UpdateImmediate_number()
// {
//     int updatenum;
//     cout << "Enter the number: " << endl;
//     cin >> updatenum;
//     MoveForward->next->id = updatenum;
// }
// void Shift_index()
// {
//     struct node *temp = MoveForward;
//     int data = temp->id;
//     temp->id = MoveForward->id;
//     MoveForward->id = data;
// }
// void undo()
// {
//     // To be implemented - Maintain a history of operations and revert them
// }
// void READ()
// {
//     string filepath;
//     cout << "Enter the file path ";
//     getline(cin, filepath);
//     ifstream inputFile(filepath);
//     if (!inputFile)
//     {
//         cout << "Error";
//         return;
//     }
//     int pos_val;
//     string command;
//     int value;
//     while (inputFile >> command)
//     {
//         if (command == "Add")
//         {
//             if (inputFile >> value)
//             {
//                 if (value > 1)
//                 {
//                     insertion(value);
//                 }
//                 else
//                 {
//                     inputFile >> pos_val;
//                     insertAtpos(value, pos_val);
//                 }
//             }
//         }
//         else if (command == "Print")
//         {
//             printCursorData();
//         }
//         else if (command == "MoveForward")
//         {
//             int steps;
//             inputFile >> steps;
//             MoveForward_steps(steps);
//         }
//         else if (command == "AddImmediate")
//         {
//             int val;
//             inputFile >> val;
//             AddImmediate_number(val);
//         }
//         else if (command == "DeleteImmediate")
//         {
//             DeleteImmediate();
//         }
//         else if (command == "Update")
//         {
//             int pos, val;
//             inputFile >> pos;
//             inputFile >> val;
//             Update_index_number(pos, val);
//         }
//         else if (command == "Delete")
//         {
//             int ind;
//             if (inputFile >> ind)
//             {
//                 deleteAtIndex(ind);
//             }
//             else
//             {
//                 Deletion();
//             }
//         }
//         else if (command == "MoveBackward")
//         {
//             int steps;
//             inputFile >> steps;
//             Backward_steps(steps);
//         }
//         else if (command == "Undo")
//         {
//             cout << "Undo" << endl;
//         }
//         else
//         {
//             struct node *curr = start;
//             while (curr->next != NULL)
//             {
//                 curr = curr->next;
//             }
//             struct node *END = curr;
//         }
//     }
//     inputFile.close();
// }
// int main()
// {
//     READ();
// }

// #include <iostream>
// #include <fstream>
// #include <stdlib.h>
// using namespace std;

// struct node
// {
//     int id;
//     struct node *next;
//     struct node *prev = NULL;
// };
// struct stack1
// {
//     struct stack1 *next;
//     struct stack1 *prev;
// };
// struct stack1 *top = NULL;
// struct node *tail = NULL;
// struct node *start = NULL;
// struct node *cursor = start;
// void Add_number(int value)
// {
//     struct node *temp = (struct node *)malloc(sizeof(struct node));
//     temp->id = value;
//     temp->next = NULL;
//     if (start == NULL)
//     {
//         start = tail = cursor = temp;
//     }
//     else
//     {
//         struct node *curr = start;
//         while (curr->next != NULL)
//         {
//             curr = curr->next;
//         }
//         curr->next = temp;
//         temp->prev = curr;
//         tail = temp;
//     }
//     if (start == NULL)
//     {
//         cout << "List is empty." << endl;
//     }
//     struct node *curr1 = start;
//     while (curr1 != NULL)
//     {
//         cout << curr1->id << " ";
//         curr1 = curr1->next;
//     }
//     cout << endl;
// }
// void Delete()
// {
//     struct node *curr = start;
//     while (curr != tail)
//     {
//         curr = curr->next;
//     }
//     curr->prev->next = NULL;
//     free(curr);
//     struct node *curr1 = start;
//     while (curr1 != NULL)
//     {
//         cout << curr1->id << " ";
//         curr1 = curr1->next;
//     }
//     cout << endl;
// }
// void Add_index_number(int index, int value)
// {
//     struct node *temp = (struct node *)malloc(sizeof(struct node));
//     temp->id = value;
//     temp->next = NULL;

//     if (start == NULL)
//     {
//         start = temp;
//         return;
//     }

//     if (index == 0)
//     {
//         temp->next = start;
//         start = temp;
//         return;
//     }

//     struct node *currNode = start;
//     struct node *prevNode = NULL;
//     int count = 0;

//     while (currNode != NULL && count < index)
//     {
//         prevNode = currNode;
//         currNode = currNode->next;
//         count++;
//     }

//     prevNode->next = temp;
//     temp->next = currNode;
// }
// void Delete_index(int index)
// {
//     if (start == nullptr)
//     {
//         cout << "Linked List is empty!" << std::endl;
//         return;
//     }

//     struct node *curr = start;
//     struct node *prev = nullptr;
//     int currentIndex = 0;

//     // Check if index is 0
//     if (index == 0)
//     {
//         start = curr->next;
//         free(curr);
//         return;
//     }

//     // Traverse the linked list until the desired index is reached
//     while (curr != nullptr && currentIndex != index)
//     {
//         prev = curr;
//         curr = curr->next;
//         currentIndex++;
//     }

//     // Check if the desired index does not exist in the linked list
//     if (curr == nullptr)
//     {
//         cout << "Index out of range!" << endl;
//         return;
//     }
//     else
//     {
//         // Delete the node at the desired index
//         prev->next = curr->next;
//         delete curr;
//     }
// }
// void MoveForward(int steps)
// {
//     for (int i = 0; i < steps; i++)
//     {
//         if (cursor != NULL)
//         {
//             cursor = cursor->next;
//         }
//         else
//         {
//             break;
//         }
//     }
// }

// void MoveBackward(int steps)
// {
//     for (int i = 0; i <= steps; i++)
//     {
//         if (cursor != NULL)
//         {
//             cursor = cursor->prev;
//         }
//         else
//         {
//             continue;
//         }
//     }
// }

// void Print()
// {
//     if (cursor != NULL)
//     {
//         cout << cursor->id << endl;
//     }
//     else
//     {
//         cout << "NULL" << endl;
//     }
// }

// void AddImmediate(int num)
// {
//    if (cursor != NULL) {
//         struct node* temp = (struct node*)malloc(sizeof(struct node));
//         temp->id = num;

//         temp->prev = cursor;
//         temp->next = cursor->next;

//         if (cursor->next != NULL)
//             cursor->next->prev = temp;

//         cursor->next = temp;
//         cursor = temp;
//     } else {
//         Add_number(num);
//     }
// }
// void DeleteImmediate()
// {
//     struct node *temp = cursor;
//     if (cursor != NULL)
//     {
//         if (cursor->prev == NULL)
//         {
//             start = start->next;
//             free(temp);
//         }

//         else if (start == NULL)
//         {
//             cout << "List is empty." << endl;
//         }
//         else if (cursor->next == NULL)
//         {
//             cursor->prev->next = cursor->next;
//             free(temp);
//         }
//         else
//         {
//             cursor->next = cursor->next->next;
//             cursor->next->prev = cursor;
//         }
//         struct node *curr1 = start;
//         while (curr1 != NULL)
//         {
//             cout << curr1->id << " ";
//             curr1 = curr1->next;
//         }
//         cout << endl;
//     }
// }
// void Update_index_number(int pos, int val)
// {
//     if (pos < 0)
//         return;

//     struct node *temp = start;
//     for (int i = 0; i < pos; i++)
//     {
//         if (temp == NULL)
//         {
//             return;
//         }
//         temp = temp->next;
//     }

//     if (temp != NULL)
//     {
//         temp->id = val;
//     }
// }
// void UpdateImmediateNumber(int num)
// {
//     if (cursor != NULL)
//     {
//         cursor->id = num;
//     }
// }
// void Shift_index(int index)
// {
//     if (cursor != NULL)
//     {
//         struct node *temp = start;
//         for (int i = 0; i < index; i++)
//         {
//             if (temp == NULL)
//             {
//                 return;
//             }
//             temp = temp->next;
//         }

//         if (temp != NULL)
//         {
//             int temp1=temp->id;
//             temp->id=cursor->id;
//             cursor->id=temp1;
//         }
//     }
// }

// void READ()
// {
//     string filepath;
//     cout << "Enter the file path ";
//     getline(cin, filepath);
//     ifstream inputFile(filepath);
//     if (!inputFile)
//     {
//         cout << "Error";
//         return;
//     }
//     int pos_val;
//     string command;
//     int value;
//     while (inputFile >> command)
//     {
//         if (command == "Add")
//         {
//             if (inputFile >> value)
//             {
//                 if (value > 1)
//                 {
//                     Add_number(value);
//                 }
//                 else
//                 {
//                     inputFile >> pos_val;
//                     Add_index_number(value,pos_val);
//                 }
//             }
//         }
//         else if (command == "Print")
//         {
//             Print();
//         }
//         else if (command == "MoveForward")
//         {
//             int steps;
//             inputFile >> steps;
//             MoveForward(steps);
//         }
//         else if (command == "AddImmediate")
//         {
//             int val;
//             inputFile >> val;
//             AddImmediate(val);
//         }
//         else if (command == "DeleteImmediate")
//         {
//             DeleteImmediate();
//         }
//         else if (command == "UpdateImmediate")
//         {
//             int val;
//             inputFile >> val;
//             UpdateImmediateNumber(val);
//         }
//         else if(command=="Shift"){
//             int index;
//             inputFile>>index;
//             Shift_index(index);
//         }
//         else if (command == "Update")
//         {
//             int pos, val;
//             inputFile >> pos;
//             inputFile >> val;
//             Update_index_number(pos, val);
//         }
//         else if (command == "Delete")
//         {
//             int ind;
//             if (inputFile >> ind)
//             {
//                 Delete_index(ind);
//             }
//             else
//             {
//                 Delete();
//             }
//         }
//         else if (command == "MoveBackward")
//         {
//             int steps;
//             inputFile >> steps;
//             MoveBackward(steps);
//         }
//         else if (command == "Undo")
//         {
//             cout << "Undo" << endl;
//         }
//         else
//         {
//             cout<<"The operation is invalid."<<endl;
//         }
//     }
//     inputFile.close();
// }
// int main()
// {
//     READ();
// }

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

struct stack1
{
    struct stack1 *next1;
    struct stack1 *prev1;
    int id1;
};
struct node
{
    int id;
    struct node *next;
    struct node *prev;
};
struct stack1 *Sstart = NULL;
struct node *start = NULL;
struct stack1 *MoveForward = Sstart;
struct node *MoveBackward;
int count = 0;

void push(struct node *temp2)
{
    struct stack1 *temp1 = (struct stack1 *)malloc(sizeof(struct stack1));
    temp1->next1 = NULL;
    temp1->id1 = temp2->id;
    if (Sstart == NULL)
    {
        Sstart = temp1;
    }
    else
    {
        struct stack1 *curr = Sstart;
        Sstart->prev1 = temp1;
        temp1->next1 = Sstart;
        Sstart = temp1;
    }
}
void pop()
{
    struct stack1 *temp = Sstart;
    Sstart = Sstart->next1;
    free(temp);
    struct stack1 *curr = Sstart;
    while (curr != NULL)
    {
        cout << curr->id1 << " ";
        curr = curr->next1;
    }
    cout << endl;
}
void insertAtpos(int steps, int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->id = value;
    if (steps == 1)
    {
        temp->prev = NULL;
        temp->next = start;
        if (start != NULL)
        {
            start->prev = temp;
            start = temp;
            push(temp);
        }
    }
    else
    {
        struct node *curr = start;
        for (int i = 1; i <= steps; i++)
        {
            temp->next = curr->next;
            curr->next->prev = temp;
            curr->next = temp;
            temp->prev = curr;
        }
    }
    push(temp);
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
        push(temp);
    }
    else
    {
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
        push(temp);
    }
}
void insertAtHead(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->id = val;
    if (start == NULL)
    {
        start = temp;
        push(temp);
    }
    else
    {
        start->prev = temp;
        temp->next = start;
        start = temp;
        push(temp);
    }
}
void print()
{
}
void MoveForward_steps(int steps)
{
    struct stack1 *curr = Sstart;
    for (int i = 0; i <= steps; i++)
    {
        if (i == steps)
        {
            MoveForward = curr;
            count = i;
            break;
        }
        curr = curr->next1;
    }
    if (MoveForward == NULL)
    {
        cout << "NULL" << endl;
    }
    else
    {
        cout << "Moved the cursor by: " << steps << " steps." << endl;
        cout << MoveForward->id1 << endl;
    }
    push((struct node *)MoveForward);
}
void Backward_steps(int steps)
{
    for (int i = 1; i < steps; i++)
    {
        if (MoveForward != NULL)
        {
            MoveForward = MoveForward->prev1;
        }
        else
        {
            continue;
        }
    }
    cout << MoveForward->id1 << endl;
    push((struct node *)MoveForward);
}

void AddImmediate(int num)
{
    struct stack1 *temp = (struct stack1 *)malloc(sizeof(struct stack1));
    temp->id1 = num;

    if (MoveForward != NULL)
    {
        temp->prev1 = MoveForward;
        temp->next1 = MoveForward->next1;

        if (MoveForward->next1 != NULL)
            MoveForward->next1->prev1 = temp;

        MoveForward->next1 = temp;
        MoveForward = temp;
    }
    else
    {
        insertion(num);
    }
    push((struct node *)temp);
}
void DeleteImmediate()
{
    struct stack1 *temp = MoveForward;
    if (MoveForward != NULL)
    {
        if (MoveForward->prev1 == NULL)
        {
            Sstart = Sstart->next1;
            push((struct node *)temp);
            cout<<temp->id1;
            free(temp);
        }

        else if (Sstart == NULL)
        {
            cout << "List is empty." << endl;
        }
        else if (MoveForward->next1 == NULL)
        {
            MoveForward->prev1->next1 = MoveForward->next1;
            push((struct node *)temp);
            free(temp);
        }
        else
        {
            MoveForward->next1 = MoveForward->next1->next1;
            MoveForward->next1->prev1 = MoveForward;
        }
    }
}
void Deletion()
{
    struct stack1 *curr = Sstart;
    while (curr->next1 != NULL)
    {
        curr = curr->next1;
    }
    curr->prev1->next1 = NULL;
    free(curr);
}
// void deleteAtIndex(int index)
// {
//     if (index < 1)
//     {
//         cout << "Invalid index\n";
//     }
//     else if (index == 1)
//     {
//         if (start == NULL)
//         {
//             cout << "List is empty\n";
//         }
//         else if (start->next == NULL)
//         {
//             free(start);
//             start = NULL;
//         }
//         else
//         {
//             struct node *temp = start;
//             start = start->next;
//             start->prev = NULL;
//             free(temp);
//         }
//     }
//     else if (MoveForward->next == NULL)
//     {
//         Deletion();
//     }
//     else
//     {
//         struct node *temp = start;
//         for (int i = 1; i <= index; i++)
//         {
//             temp = temp->next;
//         }
//         temp->prev->next = temp->next;
//         temp->next->prev = temp->prev;
//         free(temp);
//         MoveForward = temp->prev;
//     }
// }

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
// void UpdateImmediate_number(int val)
// {
//     if (MoveForward != NULL)
//     {
//         MoveForward->id = val;
//     }
//     else
//     {
//         cout << "NULL" << endl;
//     }
// }
// void Shift_index()
// {
//     MoveForward->next->id = MoveForward->id;
// }
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
            // AddImmediate(val);
        }
        else if (command == "DeleteImmediate")
        {
            // DeleteImmediate();
        }
        else if (command == "UpdateImmediate")
        {
            int val;
            inputFile >> val;
            // UpdateImmediate_number(val);
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
            int ind;
            if (inputFile >> ind)
            {
                // deleteAtIndex(ind);
            }
            else
            {
                Deletion();
            }
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
    insertion(4);
    insertion(6);
    insertion(7);
    insertion(39);
    insertion(30);
    insertAtpos(1, 5);
    insertAtHead(89);
    insertAtHead(89);
    pop();
    MoveForward_steps(3);
    Backward_steps(2);
    Deletion();
    pop();
    AddImmediate(9);
    insertion(10);
    DeleteImmediate();
    pop();
    pop();
    // Backward_steps(1);

    // MoveForward_steps(2);
}