#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

struct avl
{
    int height;
    int data;
    avl *left;
    avl *right;
};
int getHeight(avl *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

int balance_factor(avl *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return (getHeight(node->left) - getHeight(node->right));
}
struct avl *shiftleft(struct avl *node)
{
    avl *Nnode = node->right;
    avl *LC = Nnode->left;
    node->right = LC;
    Nnode->left = node;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    Nnode->height = max(getHeight(Nnode->left), getHeight(Nnode->right)) + 1;

    return Nnode;
}
struct avl *shiftright(struct avl *node)
{
    avl *Nnode = node->left;
    avl *RC = Nnode->right;
    node->left = RC;
    Nnode->right = node;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    Nnode->height = max(getHeight(Nnode->left), getHeight(Nnode->right)) + 1;

    return Nnode;
}
struct avl *insert(struct avl *node, int val)
{
    struct avl *temp = (struct avl *)malloc(sizeof(struct avl));
    temp->data = val;
    temp->left = temp->right = NULL;
    temp->height = 1;
    if (node == NULL)
    {
        return temp;
    }
    if (val < node->data)
    {
        node->left = insert(node->left, val);
    }
    else
    {
        node->right = insert(node->right, val);
    }
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = balance_factor(node);
    if (bf > 1 && val < node->left->data)
    {
        return shiftright(node);
    }
    if (bf < -1 && val > node->right->data)
    {
        return shiftleft(node);
    }
    if (bf > 1 && val > node->left->data)
    {
        node->left = shiftleft(node->left);
        return shiftright(node);
    }
    if (bf < -1 && val < node->right->data)
    {
        node->right = shiftright(node->right);
        return shiftleft(node);
    }
    return node;
}
void preOrder(avl *node)
{
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}
int main()
{
    struct avl *root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);
    return 0;
}