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

// struct node
// {
//     int marks, id;
//     struct node *next;
// };

// void insertAtHead(struct node **start)
// {
//     struct node *temp = (struct node *)malloc(sizeof(struct node));
//     cin >> temp->id;
//     temp->next = NULL;
//     struct node *curr=NULL;
// }

// void insertion(struct node **start)
// {
//     struct node *temp = (struct node *)malloc(sizeof(struct node));
//     cout << "Enter the id: ";
//     cin >> temp->id;
//     temp->next = NULL;
//     if (*start == NULL)
//     {
//         *start = temp;
//     }
//     else
//     {
//         struct node *curr = *start;
//         while (curr->next != NULL)
//         {
//             curr = curr->next;
//         }
//         curr->next = temp;
//     }
// }
// void print(struct node **start)
// {
//     if (*start == NULL)
//     {
//         cout << "List is empty." << endl;
//     }
//     struct node *curr = *start;
//     while (curr != NULL)
//     {
//         cout << curr->id << " ";
//         curr = curr->next;
//     }
//     cout << endl;
// }
// bool search(struct node **start)
// {
//     if (*start == NULL)
//     {
//         cout << "List is empty." << endl;
//     }
//     int toSearch;
//     cout << "Enter the id you want to search: " << endl;
//     cin >> toSearch;
//     struct node *curr = *start;
//     while (curr != NULL)
//     {
//         if (curr->id == toSearch)
//         {
//             return true;
//             break;
//         }
//         curr = curr->next;
//     }
// }
// void deleteNode(struct node **start)
// {
//     if (*start == NULL)
//     {
//         cout << "List is empty." << endl;
//     }
//     int todelete;
//     cout << "Enter the id you want to delete: " << endl;
//     cin >> todelete;
//     struct node *curr = *start;
//     struct node *prev = NULL;
//     while (curr != NULL)
//     {
//         if (curr->id == todelete)
//         {
//             prev->next = curr->next;
//             free(curr);
//         }
//         else
//         {
//             prev = curr;
//             curr = curr->next;
//         }
//     }
// }
// void deleteAll(struct node **start)
// {
//     struct node *curr = *start;
//     while (curr != NULL)
//     {
//         curr = curr->next;
//         free(curr);
//     }
//     *start = NULL;
// }
// int main()
// {
//     int inp = 0;
//     struct node *start = NULL;
//     while (inp != 4)
//     {
//         cout << "For input (1) \nFor printing (2) \nFor searching (3) \nFor Deleting a specific node (4) \nFor deleting the whole list (5) \nFor exiting from loop (6): ";
//         cout << endl;
//         cin >> inp;
//         if (inp == 1)
//         {
//             insertion(&start);
//         }
//         else if (inp == 2)
//         {
//             print(&start);
//         }
//         else if (inp == 3)
//         {
//             cout << search(&start);
//         }
//         else if (inp == 4)
//         {
//             deleteNode(&start);
//         }
//         else if (inp == 5)
//         {
//             deleteAll(&start);
//         }
//         else if (inp == 6)
//         {
//             cout << "Loop ended" << endl;
//             break;
//         }
//         else
//         {
//             cout << "This operation doesn't exist." << endl;
//         }
//     }
// }

// struct node
// {
//     int id;
//     struct node *next = NULL;
//     struct node *prev = NULL;
// };
// struct node *start = NULL;
// void insertion()
// {
//     struct node *temp = (struct node *)malloc(sizeof(struct node));
//     cout << "Enter the id: " << endl;
//     cin >> temp->id;
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
// }
// void insertAtHead()
// {
//     struct node *temp = (struct node *)malloc(sizeof(struct node));
//     cout << "Enter the id: " << endl;
//     cin >> temp->id;
//     if (start == NULL)
//     {
//         start = temp;
//     }
//     else
//     {
//         start->prev = temp;
//         temp->next = start;
//         start = temp;
//     }
// }
// void print()
// {
//     if (start == NULL)
//     {
//         cout << "List is empty." << endl;
//     }
//     struct node *curr = start;
//     while (curr != NULL)
//     {
//         cout << curr->id << " ";
//         curr = curr->next;
//     }
//     cout << endl;
// }

// void search()
// {
//     int toSearch;
//     cout << "Enter the id you want to searhc: " << endl;
//     cin >> toSearch;
//     struct node *curr = start;
//     while (curr != NULL)
//     {
//         if (curr->id == toSearch)
//         {
//             break;
//         }
//         else
//         {
//             curr = curr->next;
//         }
//     }
//     if (curr == NULL)
//     {
//         cout << "The element is not found." << endl;
//     }
//     else
//     {
//         cout << "The value is found " << endl;
//     }
// }
// void AddAtIndex()
// {
//     int index;
//     struct node *temp = (struct node *)malloc(sizeof(struct node));
//     cout<<"Enter the index: ";
//     cin>>index;
//     cout<<"Enter the id: ";
//     cin>>temp->id;
//     struct node* curr = start;
//     // make a temp node and traverse to the 
//    //   node previous to the position
//     for(int i = 1; i < index-1; i++) {
//       if(curr != NULL) {
//         curr = curr->next;
//       }
//     }
 
//     //5. If the previous node is not null, adjust 
//     //   the links
//     if(curr != NULL) {
//       temp->next = curr->next;
//       temp->prev = curr;
//       curr->next = temp;
//       if(temp->next != NULL)
//         temp->next->prev = temp;  
//     } else {
      
//       //6. When the previous node is null
//       cout<<"\nThe previous node is null.";
//     } 

//     }

// int reverse()
// {
//     int i = 1;
//     struct node *curr = start;
//     while (curr->next != NULL)
//     {
//         curr = curr->next;
//         i++;
//     }
//     if (i < 3)
//     {
//         return -1;
//     }
//     else
//     {
//         while (curr != NULL)
//         {
//             if (i == 3)
//             {
//                 return curr->id;
//                 break;
//             }
//             curr = curr->prev;
//         }
//     }
// }

// int main()
// {
//     // insertion();
//     insertion();
//     insertion();
//     print();
//     AddAtIndex();
//     print();

// }
// struct node
// {
//     int id;
//     struct node *next = NULL;
//     struct node *prev = NULL;
// };
// struct node *start = NULL;
// void median(){
    
// }
// void insertion()
// {
//     struct node *temp = (struct node *)malloc(sizeof(struct node));
//     cout << "Enter the id: " << endl;
//     cin >> temp->id;
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
// }
// void insertAtHead()
// {
//     struct node *temp = (struct node *)malloc(sizeof(struct node));
//     cout << "Enter the id: " << endl;
//     cin >> temp->id;
//     if (start == NULL)
//     {
//         start = temp;
//     }
//     else
//     {
//         start->prev = temp;
//         temp->next = start;
//         start = temp;
//     }
// }
// void print()
// {
//     if (start == NULL)
//     {
//         cout << "List is empty." << endl;
//     }
//     struct node *curr = start;
//     while (curr != NULL)
//     {
//         cout << curr->id << " ";
//         curr = curr->next;
//     }
//     cout << endl;
// }

// void search()
// {
//     int toSearch;
//     cout << "Enter the id you want to searhc: " << endl;
//     cin >> toSearch;
//     struct node *curr = start;
//     while (curr != NULL)
//     {
//         if (curr->id == toSearch)
//         {
//             break;
//         }
//         else
//         {
//             curr = curr->next;
//         }
//     }
//     if (curr == NULL)
//     {
//         cout << "The element is not found." << endl;
//     }
//     else
//     {
//         cout << "The value is found " << endl;
//     }
// }
// void AddAtIndex()
// {
//     int index;
//     struct node *temp = (struct node *)malloc(sizeof(struct node));
//     cout<<"Enter the index: ";
//     cin>>index;
//     cout<<"Enter the id: ";
//     cin>>temp->id;
//     struct node* curr = start;
//     // make a temp node and traverse to the 
//    //   node previous to the position
//     for(int i = 1; i < index-1; i++) {
//       if(curr != NULL) {
//         curr = curr->next;
//       }
//     }
 
//     //5. If the previous node is not null, adjust 
//     //   the links
//     if(curr != NULL) {
//       temp->next = curr->next;
//       temp->prev = curr;
//       curr->next = temp;
//       if(temp->next != NULL)
//         temp->next->prev = temp;  
//     } else {
      
//       //6. When the previous node is null
//       cout<<"\nThe previous node is null.";
//     } 

//     }

// int reverse()
// {
//     int i = 1;
//     struct node *curr = start;
//     while (curr->next != NULL)
//     {
//         curr = curr->next;
//         i++;
//     }
//     if (i < 3)
//     {
//         return -1;
//     }
//     else
//     {
//         while (curr != NULL)
//         {
//             if (i == 3)
//             {
//                 return curr->id;
//                 break;
//             }
//             curr = curr->prev;
//         }
//     }
// }

// int main()
// {
//     // insertion();
//     insertion();
//     insertion();
//     print();
//     AddAtIndex();
//     print();

// }