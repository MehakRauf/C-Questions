#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
using namespace std;

struct node
{
    int transactionId;
    int transactionAmount;
    struct node *next;
    struct node *prev;
};
struct node *start = NULL;

void ADD(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->transactionId = arr[i];
        cout << arr[i] << " ";
        temp->transactionAmount = arr[i + 1];
        cout << arr[i + 1] << " ";
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
}
void DELETE(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        struct node *curr = start;
        while (curr != NULL)
        {
            if (curr->transactionId == arr[i])
            {
                curr->transactionAmount = 0;
            }
            curr = curr->next;
        }
    }
}
void read()
{
    int numberOfTransactions;
    int numberOfFraudulentTransactions;
    int transId;
    int transAmount;
    char comma;
    string line;
    string filepath;
    cout << "Enter the file path ";
    getline(cin, filepath);
    ifstream inputFile(filepath);
    if (!inputFile)
    {
        cout << "Error";
        return;
    }
    inputFile >> numberOfTransactions;
    inputFile >> numberOfFraudulentTransactions;
    int size = numberOfTransactions * 2 + numberOfFraudulentTransactions;
    int arr[size];
    int del[numberOfFraudulentTransactions];
    for (int i = 0; i < size; i++)
    {
        while (i < numberOfTransactions)
        {
            inputFile >> arr[i];
            inputFile >> comma;
            inputFile >> arr[i + 1];
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->transactionId = arr[i];
            temp->transactionAmount = arr[i + 1];
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
            i++;
        }
    }
    for (int i = 0; i < numberOfFraudulentTransactions; i++)
    {
        inputFile >> del[i];
    }
    DELETE(del,numberOfFraudulentTransactions);
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
        if(curr->transactionAmount!=0){
        cout << curr->transactionId << "," << curr->transactionAmount << endl;
        }
        curr = curr->next;
    }
    cout << endl;
}
int main()
{
    read();
    print();
}