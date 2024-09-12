// #include <stdio.h>
// #include <iostream>
// #include <stdlib.h>
// using namespace std;

// struct Node
// {
//     int key;
//     struct Node *left;
//     struct Node *right;
//     int height;
// };

// int getHeight(struct Node *n)
// {
//     if (n == NULL)
//         return 0;
//     return n->height;
// }

// int max(int a, int b)
// {
//     return (a > b) ? a : b;
// }

// int getBalanceFactor(struct Node *n)
// {
//     if (n == NULL)
//     {
//         return 0;
//     }
//     return getHeight(n->left) - getHeight(n->right);
// }

// struct Node *rightRotate(struct Node *y)
// {
//     struct Node *x = y->left;
//     struct Node *T2 = x->right;

//     x->right = y;
//     y->left = T2;

//     x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
//     y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

//     return x;
// }

// struct Node *leftRotate(struct Node *x)
// {
//     struct Node *y = x->right;
//     struct Node *T2 = y->left;

//     y->left = x;
//     x->right = T2;

//     x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
//     y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

//     return y;
// }

// struct Node *insert(struct Node *node, int key)
// {
//     struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
//     temp->key = key;
//     temp->left = temp->right = NULL;
//     temp->height = 1;

//     if (node == NULL)
//         return temp;

//     if (key < node->key)
//         node->left = insert(node->left, key);
//     else if (key > node->key)
//         node->right = insert(node->right, key);

//     node->height = 1 + max(getHeight(node->left), getHeight(node->right));
//     int bf = getBalanceFactor(node);

//     // Left Left Case
//     if (bf > 1 && key < node->left->key)
//     {
//         return rightRotate(node);
//     }
//     // Right Right Case
//     if (bf < -1 && key > node->right->key)
//     {
//         return leftRotate(node);
//     }
//     // Left Right Case
//     if (bf > 1 && key > node->left->key)
//     {
//         node->left = leftRotate(node->left);
//         return rightRotate(node);
//     }
//     // Right Left Case
//     if (bf < -1 && key < node->right->key)
//     {
//         node->right = rightRotate(node->right);
//         return leftRotate(node);
//     }
//     return node;
// }

// void preOrder(struct Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     cout<<root->key<<" ";
//     preOrder(root->left);
//     preOrder(root->right);
// }

// int main()
// {
//     struct Node *root = NULL;

//     root = insert(root, 1);
//     root = insert(root, 2);
//     root = insert(root, 4);
//     root = insert(root, 5);
//     root = insert(root, 6);
//     root = insert(root, 3);
//     preOrder(root);
//     return 0;
// }

#include <iostream>
#include <stdlib.h>
using namespace std;

// Tree structure
struct avl
{
    int height;
    int data;
    avl *left;
    avl *right;
};

// to get the height of the node
int getHeight(avl *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

// to get the balance factor i.e: left-right
int balance_factor(avl *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return (getHeight(node->left) - getHeight(node->right));
}
// shift left function
struct avl *shiftleft(struct avl *node)
{
    // creating a new noode
    avl *Nnode = node->right;
    // left child of the new node
    avl *LC = Nnode->left;
    // assgning the new node as root
    Nnode->left = node;
    // assigning the LC of the Nnode to the node
    node->right = LC;
    // assgning the heights
    node->height = max(getHeight(node->right), getHeight(node->left)) + 1;
    Nnode->height = max(getHeight(Nnode->right), getHeight(Nnode->left)) + 1;

    // return the new node
    return Nnode;
}
// shift right function
struct avl *shiftright(struct avl *node)
{
    avl *Nnode = node->left;
    avl *RC = Nnode->right;
    Nnode->right = node;
    node->left = RC;
    node->height = max(getHeight(node->right), getHeight(node->left)) + 1;
    Nnode->height = max(getHeight(Nnode->right), getHeight(Nnode->left)) + 1;

    return Nnode;
}
// to insert a node
struct avl *insert(struct avl *node, int val)
{
    // memory allocation
    struct avl *temp = (struct avl *)malloc(sizeof(struct avl));
    temp->data = val;
    temp->left = temp->right = NULL;
    temp->height = 1;
    // if tree is null
    if (node == NULL)
    {
        return temp;
    }
    // if values is smaller than the root node value
    if (val < node->data)
    {
        node->left = insert(node->left, val);
    }
    // if alue is greater
    else
    {
        node->right = insert(node->right, val);
    }
    // calculating the height of the node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    // taking the balance factor
    int bf = balance_factor(node);
    // shift right (left left case)
    if (bf > 1 && val < node->left->data)
    {
        return shiftright(node);
    }
    // shift left (right right case)
    if (bf < -1 && val > node->right->data)
    {
        return shiftleft(node);
    }
    // double shift (left right case)
    if (bf > 1 && val > node->left->data)
    {
        node->left = shiftleft(node->left);
        return shiftright(node);
    }
    // double shift (right left case)
    if (bf < -1 && val < node->right->data)
    {
        node->right = shiftright(node->right);
        return shiftleft(node);
    }
    // returning the node itself if it is already balanced
    return node;
}
// preorder traversal of the tree
void preOrder(avl *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}
int main()
{
    struct avl *root = NULL;

    // storing the root value every time because of unbalancing
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    root = insert(root, 15);
    root = insert(root, 7);
    root = insert(root, 10);

    preOrder(root);
    return 0;
}