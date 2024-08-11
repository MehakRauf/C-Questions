#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
struct Node *root = NULL;

// function to search
void searchNode(Node *node, int val)
{
    // if node is null means no node is left for further execution
    if (node == NULL)
    {
        cout << "Value not found" << endl;
        return;
    }
    // if you find it
    if (node->data == val)
    {
        cout << "Value found" << endl;
        return;
    }
    // if value is lesser than the data on node then go to the left of bst
    if (val < node->data)
    {
        searchNode(node->left, val);
    }
    // if value is greater than the data on node then go to the right of bst
    else
    {
        searchNode(node->right, val);
    }
}
// to delete a node
Node *deleteNode(Node *node, int val)
{
    // if the node is null means there is no more node remaining to check
    if (node == NULL)
    {
        cout << "Value not found" << endl;
    }
    // if value is lesser than the data on node then go to the left of bst
    if (val < node->data)
    {
        node->left = deleteNode(node->left, val);
    }
    // if value is greater than the data on node then go to the right of bst
    else if (val > node->data)
    {
        node->right = deleteNode(node->right, val);
    }
    // when the value is found
    else
    {
        // means the searched node has 1 or 0 child
        // in this case chceking for left child
        if (node->left == NULL)
        {
            // if not present then linking the right node (either null or not)
            struct Node *temp = node->right;
            // free the memory
            free(node);
            return temp;
        }
        // in this case chceking for right child
        if (node->right == NULL)
        {
            // if not present then linking the left node (either null or not)
            struct Node *temp = node->left;
            free(node);
            return temp;
        }
        // when both the children are available
        else
        {
            // for iteration
            struct Node *temp = node->right;
            // until we reach the last node
            // and get the node with smallest node
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            int sm = temp->data;
            // copying the data
            node->data = sm;
            // updating the right node links
            node->right = deleteNode(node->right, val);
        }
    }
}
Node *insertNode(Node *root, int data)
{
    // assigning memeory
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
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
void inOrder(Node *root)
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
// postorder traversing
void postOrder(Node *root)
{
    // if root is null then return means no more values are remaining
    if (root == NULL)
    {
        return;
    }
    // in postorder left value is accessed first
    postOrder(root->left);
    // then the right value
    postOrder(root->right);
    // atlast the root value
    cout << root->data << " ";
}
// preorder traversing
void preOrder(Node *root)
{
    // if root is null means no more values are remaining
    if (root == NULL)
    {
        return;
    }
    // we access the root value first
    cout << root->data << " ";
    // then the left value
    preOrder(root->left);
    // then the right value
    preOrder(root->right);
}

int main()
{
    // initializing root as null
    struct Node *root = NULL;
    int op = 0;
    //menu driven program for BST
    while (op >=0)
    {
        cout << "For insertion enter (1)\nFor deletion enter(2)\nFor searching enter(3)\nFor inorder traversing enter(4)\nFor postorder traversing enter(5)\nFor preorder traversing enter(6)\nFor exit enter(7):" << endl;
        cin >> op;
        if (op == 1)
        {
            int val;
            cout << "Enter the value you want to insert: " << endl;
            cin >> val;
            if (root == NULL)
            {
                root = insertNode(root, val);
            }
            else
            {
                insertNode(root, val);
            }
        }
        else if (op == 2)
        {
            int val;
            cout << "Enter the value you want to delete: " << endl;
            cin >> val;
            deleteNode(root, val);
        }
        else if (op == 3)
        {
            int val;
            cout << "Enter the value you want to search: " << endl;
            cin >> val;
            searchNode(root, val);
        }
        else if (op == 4)
        {
            cout << "Inorder traversal:" << endl;
            inOrder(root);
            cout << endl;
        }
        else if (op == 5)
        {
            cout << "Postorder traversal:" << endl;
            postOrder(root);
            cout << endl;
        }
        else if (op == 6)
        {
            cout << "Preorder traversal:" << endl;
            preOrder(root);
            cout << endl;
        }
        else if (op == 7)
        {
            cout << "Loop exited." << endl;
            break;
        }
        else
        {
            cout << "Operation is invalid." << endl;
        }
    }
    return 0;
}