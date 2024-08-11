#include <iostream>
using namespace std;

struct HNode
{
    int data;
    struct HNode *right;
    struct HNode *left;
};
HNode *insertNode(HNode *root, int data)
{
    // assigning memeory
    struct HNode *newNode = (struct HNode *)malloc(sizeof(struct HNode));
    // assigning values
    newNode->data = data;
    // making the pointers null
    newNode->left = newNode->right = NULL;
    // checking if the root is null
    if (root == NULL)
    {
        root = newNode;
        // returning the node to keep track of the root
        return newNode;
    }
    // checking if the value is lesser
    if (data < root->data)
    {
        // going to left until we found the left as null
        root->left = insertNode(root->left, data);
    }
    // else the value is greater
    else
    {
        // going to right until we found right is null
        root->right = insertNode(root->right, data);
    }
    return root;
}
// inorder traversing
void inOrder(HNode *root)
{
    // if root is null then return means no more values are remaining
    if (root == NULL)
        return;
    // in inorder we access the left values first
    inOrder(root->left);
    // then the root value is written
    cout << root->data << " ";
    // at last we access the right values
    inOrder(root->right);
}
int main()
{
    struct HNode *root = NULL;
    int key, j;
    int arr[] = {15, 10, 20, 8, 12, 16, 25};
    int hold, gap;
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 1; i <= size; i++)
    {
        hold = arr[i];
        gap = i - 1;
        while (gap >= 0 && hold < arr[gap])
        {
            int temp = arr[gap + 1];
            arr[gap + 1] = arr[gap];
            arr[gap] = temp;
            gap--;
        }
    }
    root = insertNode(root, arr[4]);
    for (int i = 0; i < size; i++)
    {
        if (i == 4)
        {
            continue;
        }
        else
        {
            insertNode(root, arr[i]);
        }
    }
    inOrder(root);
}