// #include <iostream>
// #include <fstream>
// using namespace std;

// struct node
// {
//     int id;
//     struct node *next;
// };
// struct node *start = NULL;
// void read()
// {
//     int total;
//     string filepath;
//     cout << "Enter the file path ";
//     getline(cin, filepath);
//     ifstream inputFile(filepath);
//     if (!inputFile)
//     {
//         cout << "Error";
//         return;
//     }
//     int tot;
//     inputFile >> total;
//     inputFile>>tot;
//     cout << "The size of the array is: " << total << endl;
//     for (int i = 0; i < total; i++)
//     {
//         struct node *temp = (struct node *)malloc(sizeof(struct node));
//         string element;
//         temp->next = NULL;
//         getline(inputFile, element, ' ');
//         temp->id = stoi(element);
//         if (start == NULL)
//         {
//             start = temp;
//         }
//         else
//         {
//             struct node* curr=start;
//             while(curr->next!=NULL){
//             curr=curr->next;
//             }
//             curr->next=temp;
//         }
//     }
//     inputFile.close();
// }
// void print(){
//     struct node* curr=start;
//     while(curr!=NULL){
//         cout<<curr->id<<" ";
//         curr=curr->next;
//     }
// }
// int main()
// {
//     read();
//     print();
// }

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Node {
    int id;
    int value;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertNode(int id, int value) {
        Node* newNode = new Node;
        newNode->id = id;
        newNode->value = value;

        if (head == NULL) {
            head = tail = newNode;
            newNode->prev = NULL;
            newNode->next = NULL;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = NULL;
            tail = newNode;
        }
    }

    void displayList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->id << "," << temp->value << endl;
            temp = temp->next;
        }
    }
};

int main() {
    ifstream inputFile("Test01.txt");
    string line;

    DoublyLinkedList list;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string idStr, valueStr;
        getline(ss, idStr, ',');
        getline(ss, valueStr);

        int id = stoi(idStr);
        int value = stoi(valueStr);

        list.insertNode(id, value);
    }

    inputFile.close();

    list.displayList();

    return 0;
}