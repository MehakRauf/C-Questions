#include <iostream>
#include <stdlib.h>
using namespace std;

struct stack
{
    struct stack *next;
    char c;
};
struct stack *start = NULL;
bool check_char(char c)
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
    {
        return true;
    }
    return false;
}
int precedence(char c)
{
    if (c == '*' || c == '/')
    {
        return 5;
    }
    else if (c == '+' || c == '-')
    {
        return 4;
    }
    else if (c == '>' || c == '<')
    {
        return 3;
    }
    else if (c == '&')
    {
        return 2;
    }
    else
    {
        return 1;
    }
}
void push(char c1)
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    temp->c = c1;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->next = start;
        start = temp;
    }
}
struct stack *pop()
{
    struct stack *curr = start;
    start = start->next;
    free(curr);
    return start;
}
string postfix(string equation)
{
    string res;
    for (int i = 0; i < equation.length(); i++)
    {
        if (check_char(equation[i]))
        {
            res = res + equation[i];
        }
        else if (equation[i] == '(')
        {
            push(equation[i]);
        }
        else if (equation[i] == ')')
        {
            while (start != NULL && start->c != '(')
            {
                res += start->c;
                pop();
            }
            if (start != NULL)
            {
                pop();
            }
        }
        else
        {
            
            if (equation[i] == '&' || equation[i] == '|' || equation[i] == '!')
            {
                i++;
            }
            while (start != NULL && precedence(equation[i]) <= precedence(start->c))
            {
                res = res + start->c;
                pop();
            }
            push(equation[i]);
        }
    }
    while (start != NULL)
    {
        res = res + start->c;
        pop();
    }
    return res;
}
int main()
{
    string str;
    cout<<"Enter the equation: "<<endl;
    cin>>str;
    string postfix_eqn=postfix(str);
    for (int i=0;i<postfix_eqn.length();i++){
        cout<<postfix_eqn[i];
        if(postfix_eqn[i]=='&' ){
            cout<<'&';
        }
        else if(postfix_eqn[i]=='|' ){
            cout<<'|';
        }
        else if(postfix_eqn[i]=='!' ){
            cout<<'=';
        }
    }
}