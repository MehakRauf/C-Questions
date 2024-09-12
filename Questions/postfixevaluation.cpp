#include <iostream>
#include <stdlib.h>
using namespace std;

struct stack
{
    char c;
    stack *next;
    stack *prev;
};
stack *top = NULL;

int prec(char c1)
{
    if (c1 == '*' || c1 == '/')
    {
        return 5;
    }
    else if (c1 == '+' || c1 == '-')
    {
        return 4;
    }
    else if (c1 == '>' || c1 == '<' || c1 == '!')
    {
        return 3;
    }
    else if (c1 == '&')
    {
        return 2;
    }
    else if (c1 == '|')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
void insert(char c1)
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    temp->c = c1;
    temp->next = NULL;
    temp->prev = NULL;
    if (top == NULL)
    {
        top = temp;
    }
    else
    {
        temp->next = top;
        top->prev = temp;
        top = temp;
    }
}
struct stack* pop()
{
    struct stack *curr = top;
    struct stack *curr1 = top;
    top = top->next;
    free(curr);
    return top;
}
string postfix()
{
    string c;
    string res;
    cout << "Enter the equation: " << endl;
    cin >> c;
    for (int i = 0; i < c.length(); i++)
    {
        if (c[i] >= '0' && c[i] <= '9')
        {
            res += c[i];
        }
        else if (c[i] == '(')
        {
            insert(c[i]);
        }
        else if (c[i] == ')')
        {
            while (top != NULL && top->c != '(')
            {
                res += top->c;
                pop();
            }
            if (top != NULL)
            {
                pop();
            }
        }
        else
        {
            if (c[i] == '&' || c[i] == '|' || c[i] == '!')
            {
                i++;
            }
            while (top != NULL && prec(top->c) >= prec(c[i]))
            {
                res += top->c;
                pop();
            }
            insert(c[i]);
        }
    }
    while (top != NULL)
    {
        res = res + top->c;
        pop();
    }
    return res;
}
int main()
{
    string ptfix = postfix();
    for (int i = 0; i < ptfix.length(); i++)
    {
        if (ptfix[i] >= '0' && ptfix[i] <= '9')
        {
            insert(ptfix[i]);
        }
        else
        {
            while (top != NULL && prec(top->c) >= prec(ptfix[i]))
            {
                pop();
                pop();
            }
        }
    }
    cout<<ptfix;
}
