#include <iostream>
#include <stdlib.h>

using namespace std;
struct tree
{
    string data;
    struct tree *left;
    struct tree *right;
};

struct tree *newNode(string val)
{
    struct tree *temp = new struct tree;
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

tree *insert(struct tree *node, string val)
{
    if (node == NULL)
    {
        return newNode(val);
    }
    else if (val < node->data)
    {
        node->left = insert(node->left, val);
    }
    else
    {
        node->right = insert(node->right, val);
    }
    return node;
}

bool mirror(struct tree *node1, struct tree *node2)
{
    if (node1 == NULL && node2 == NULL)
    {
        return true;
    }
    if (node1 == NULL || node2 == NULL)
    {
        return false;
    }
    if (node1->data == node2->data)
    {
        return mirror(node1->left, node2->right) && mirror(node1->right, node2->left);
    }
    return false;
}

bool issymmetric(struct tree *t1, struct tree *t2)
{
    return mirror(t1, t2);
}

int main()
{
    struct tree *root1 = NULL;
    root1 = insert(root1, "Hello");
    insert(root1, "HIII");
    insert(root1, "Shakeela");
    insert(root1, "Shabaz");

    struct tree *root2 = NULL;
    root2 = insert(root2, "Shakeela");
    insert(root2, "HIII");
    insert(root2, "Shabaz");
    insert(root2, "Hello");

    if (issymmetric(root1, root2))
    {
        cout << "The trees are mirror images." << endl;
    }
    else
    {
        cout << "The trees are not mirror images." << endl;
    }

    return 0;
}