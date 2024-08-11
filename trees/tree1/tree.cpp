#include <iostream>
#include <queue>
using namespace std;

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *root = NULL;

struct tree *insert(struct tree *node, int val)
{
    if (node == NULL)
    {
        struct tree *temp = new struct tree;
        temp->data = val;
        temp->left = temp->right = NULL;
        return temp;
    }
    else
    {
        queue<struct tree *> q;
        q.push(node);

        while (!q.empty())
        {
            struct tree *currNode = q.front();
            q.pop();

            if (currNode->left == NULL)
            {
                struct tree *temp = new struct tree;
                temp->data = val;
                temp->left = temp->right = NULL;
                currNode->left = temp;
                return node;
            }
            else
            {
                q.push(currNode->left);
            }

            if (currNode->right == NULL)
            {
                struct tree *temp = new struct tree;
                temp->data = val;
                temp->left = temp->right = NULL;
                currNode->right = temp;
                return node;
            }
            else
            {
                q.push(currNode->right);
            }
        }
    }
    return node;
}

void heapify(struct tree *node)
{
    if (node == NULL)
    {
        return;
    }

    struct tree *largest = node;
    struct tree *left = node->left;
    struct tree *right = node->right;

    if (left != NULL && left->data > largest->data)
    {
        largest = left;
    }

    if (right != NULL && right->data > largest->data)
    {
        largest = right;
    }

    if (largest != node)
    {
        swap(node->data, largest->data);
        heapify(largest);
    }
}

void buildHeap(struct tree *node)
{
    if (node == NULL)
    {
        return;
    }

    buildHeap(node->left);
    buildHeap(node->right);
    heapify(node);
}

void heapSort(struct tree *node)
{
    buildHeap(node);

    while (node != NULL && (node->left != NULL || node->right != NULL))
    {
        swap(root->data, node->data);
        heapify(node);
        while (node->left != NULL)
        {
            node = node->left;
            heapify(node);
        }
        if (node->right != NULL) {
            node = node->right;
        } else {
            break;
        }
    }
}

void inorder(struct tree *node)
{
    if (node == NULL)
    {
        return;
    }

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main()
{
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 80);
    root = insert(root, 10);
    root = insert(root, 50);
    root = insert(root, 25);
    root = insert(root, 18);
    root = insert(root, 97);
    root = insert(root, 40);

    heapSort(root);
    inorder(root);

    return 0;
}