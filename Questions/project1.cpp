#include <iostream>
#include <stdlib.h>
using namespace std;

struct HNode
{
    int CNo;
    string name;
    struct HNode *next;
};
int hash_function(int key)
{
    return ((key - 65) % 26);
}
void insert(HNode HTable[])
{
    string str;
    int Contact;
    cout << "Enter the name of the person: " << endl;
    cin >> str;
    cout << "Enter the contact number: " << endl;
    cin >> Contact;
    int key = (int)str[0];
    int ind = hash_function(key);
    if (HTable[ind].CNo == -1)
    {
        HTable[ind].CNo = Contact;
        HTable[ind].name = str;
    }
    else
    {
        struct HNode *temp = (struct HNode *)malloc(sizeof(struct HNode));
        temp->CNo = Contact;
        temp->name = str;
        temp->next = NULL;
        if (HTable[ind].next == NULL)
        {
            HTable[ind].next = temp;
        }
        else
        {
            struct HNode *curr = HTable[ind].next;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = temp;
        }
    }
}
bool Search(HNode HTable[])
{
    string str;
    int Contact;
    cout << "Enter the name of the person: " << endl;
    cin >> str;
    cout << "Enter the contact number: " << endl;
    cin >> Contact;
    int ind = hash_function((int)str[0]);
    if (HTable[ind].CNo == Contact &&  HTable[ind].name.compare(str) == 0)
    {
        return true;
    }
    else
    {
        struct HNode *curr = HTable[ind].next;
        if (curr == NULL)
        {
            return false;
        }
        else
        {
            while (curr != NULL)
            {
                if (curr->CNo == Contact &&  HTable[ind].name.compare(str) == 0)
                {
                    return true;
                }
                else
                {
                    curr = curr->next;
                }
            }
        }
    }
    return false;
}
int main()
{
    int size = 26;
    HNode HTable[size];
    for (int i = 0; i < size; i++)
    {
        HTable[i].CNo = -1;
    }
    insert(HTable);
    insert(HTable);
    insert(HTable);

    cout << Search(HTable);
}