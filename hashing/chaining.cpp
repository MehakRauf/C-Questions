#include <iostream>
using namespace std;

struct HNode
{
    string data;
    struct HNode *next = NULL;
};

int hash_function(char c, int size)
{
    return (c - 'A') % size;
}
void chaining(HNode Htable[], int size, string keyvalue)
{
    int ind = hash_function(char(keyvalue[0]),size);
    if (Htable[ind].data == "-1")
    {
        Htable[ind].data = keyvalue;
    }
    else
    {
        HNode *temp = (struct HNode *)malloc(sizeof(struct HNode));
        temp->data = keyvalue;
        temp->next = NULL;
        if (Htable[ind].next == NULL)
        {
            Htable[ind].next = temp;
        }
        struct HNode *curr = Htable[ind].next;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}
bool search(HNode HTable[], int size)
{
    // taking the value as input
    string toSearch;
    cout << "Enter the value you want to search: " << endl;
    cin >> toSearch;
    int ind = hash_function(char(toSearch[0]), size);
    // checking it initially at the calculated index
    if (HTable[ind].data == toSearch)
    {
        return true;
    }
    else
    {
        // if the next of the index is null means vlaue is not present
        if (HTable[ind].next == NULL)
        {
            return false;
        }
        else
        {
            // otherwise traversing it till we find the value
            struct HNode *curr = HTable[ind].next;
            while (curr->next != NULL)
            {
                if (curr->data == toSearch)
                {
                    return true;
                }
                // moving the cursor forward
                curr = curr->next;
            }
        }
    }
}
int main()
{
    int size = 26;
    HNode Htable[size];
    for (int i = 0; i < size; i++)
    {
        Htable[i].data = "-1";
    }
    chaining(Htable, size, "Hello");
    chaining(Htable, size, "Hi");
    chaining(Htable, size, "Mehak");
    chaining(Htable, size, "Mango");
    chaining(Htable, size, "Awww");
    chaining(Htable, size, "Apple");
    cout << search(Htable, size);
    cout << search(Htable, size);
    cout << search(Htable, size);
    cout << search(Htable, size);
    cout << search(Htable, size);

}