#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// Node struct to store the tree node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Function to heapify a subtree rooted at given index
void heapify(Node *root)
{
    Node *largest = root;
    Node *left = root->left;
    Node *right = root->right;

    // Check if left child is larger than root
    if (left != NULL && left->data > largest->data)
        largest = left;

    // Check if right child is larger than largest
    if (right != NULL && right->data > largest->data)
        largest = right;

    // If largest is not root, swap and heapify the affected subtree
    if (largest != root)
    {
        swap(root->data, largest->data);
        heapify(largest);
    }
}

// Function to build a max heap
void buildHeap(Node *root)
{
    if (root == NULL)
        return;

    // Recursively build max heap for left and right subtree
    buildHeap(root->left);
    buildHeap(root->right);

    // Finding the largest node in current subtree
    heapify(root);
}

void heapSort(Node *root)
{
    // Build max heap
    buildHeap(root);

    // Swap root with the last leaf node and heapify the reduced heap
    while (root != NULL)
    {
        Node *largest = root;
        Node *left = root->left;
        Node *right = root->right;

        if (left != NULL && left->data > largest->data)
            largest = left;

        if (right != NULL && right->data > largest->data)
            largest = right;

        if (largest != root)
        {
            swap(root->data, largest->data);
            root = largest;
        }
        else
        {
            break;
        }
    }
}

// Function to insert a new node into heap
Node *insertNode(Node *root, int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    if (root == NULL)
    {
        root = temp;
        return root;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (!front->left)
        {
            front->left = temp;
            break;
        }
        else if (!front->right)
        {
            front->right = temp;
            break;
        }

        q.push(front->left);
        q.push(front->right);
    }

    return root;
}

// Function to print inorder traversal of the tree (sorted order)
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Driver code
int main()
{
    Node *root = NULL;
    root = insertNode(root, 4);
    root = insertNode(root, 10);
    root = insertNode(root, 3);
    root = insertNode(root, 5);
    root = insertNode(root, 1);

    cout << "Inorder traversal of the tree before heap sort: ";
    inorder(root);
    cout << endl;

    heapSort(root);

    cout << "Inorder traversal of the tree after heap sort: ";
    inorder(root);
    cout << endl;

    return 0;
}