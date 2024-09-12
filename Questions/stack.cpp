// // #include <iostream>

// // using namespace std;

// // struct stack1
// // {
// //     char id;
// //     struct stack1 *next;
// // };
// // struct stack1 *top = NULL;

// // int prec(char c)
// // {
// //     if (c == '^')
// //     {
// //         return 3;
// //     }
// //     else if (c == '/' || c == '*')
// //     {
// //         return 2;
// //     }
// //     else if (c == '+' || c == '-')
// //     {
// //         return 1;
// //     }
// //     else
// //     {
// //         return -1;
// //     }
// // }
// // void insertion(char c)
// // {
// //     struct stack1 *temp = (struct stack1 *)malloc(sizeof(struct stack1));
// //     temp->id = c;
// //     temp->next = NULL;
// //     if (top == NULL)
// //     {
// //         top = temp;
// //     }
// //     else
// //     {
// //         temp->next = top;
// //         top = temp;
// //     }
// // }
// // void pop()
// // {
// //     struct stack1 *curr = top;
// //     top = top->next;
// //     free(curr);
// // }
// // int main()
// // {
// //     string c = "(a-b/c)*(a/k-l)";
// //     string res;
// //     for (int i = 0; i < c.length(); i++)
// //     {
// //         if (c[i] >= 'a' && c[i] <= 'z' || c[i] >= 'A' && c[i] <= 'Z')
// //         {
// //             res += c[i];
// //         }
// //         else if (c[i] == '(')
// //         {
// //             insertion(c[i]);
// //         }
// //         else if (c[i] == ')')
// //         {
// //             while (top != NULL && top->id != '(')
// //             {
// //                 res += top->id;
// //                 pop();
// //             }
// //             if (top != NULL)
// //             {
// //                 pop();
// //             }
// //         }
// //         else
// //         {
// //             while (top != NULL && prec(top->id) > prec(c[i]))
// //             {
// //                 res += top->id;
// //                 pop();
// //             }
// //             insertion(c[i]);
// //         }
// //     }
// //     while (top != NULL)
// //     {
// //         res = res + top->id;
// //         pop();
// //     }
// //     cout << res;
// // }

// #include <iostream>
// #include <algorithm>

// using namespace std;

// struct stack1
// {
//     char id;
//     struct stack1 *next;
// };
// struct stack1 *top = NULL;

// int prec(char c)
// {
//     if (c == '^')
//     {
//         return 3;
//     }
//     else if (c == '/' || c == '*')
//     {
//         return 2;
//     }
//     else if (c == '+' || c == '-')
//     {
//         return 1;
//     }
//     else
//     {
//         return -1;
//     }
// }
// void insertion(char c)
// {
//     struct stack1 *temp = (struct stack1 *)malloc(sizeof(struct stack1));
//     temp->id = c;
//     temp->next = NULL;
//     if (top == NULL)
//     {
//         top = temp;
//     }
//     else
//     {
//         temp->next = top;
//         top = temp;
//     }
// }
// void pop()
// {
//     struct stack1 *curr = top;
//     top = top->next;
//     free(curr);
// }
// int main()
// {
//     string c = "(a-b/c)*(a/k-l)";
//     reverse(c.begin(), c.end());
//     string res;
//     for (int i = 0; i < c.length(); i++)
//     {
//         if (c[i] >= 'a' && c[i] <= 'z' || c[i] >= 'A' && c[i] <= 'Z')
//         {
//             res += c[i];
//         }
//         else if (c[i] == '(')
//         {
//             insertion(c[i]);
//         }
//         else if (c[i] == ')')
//         {
//             while (top != NULL && top->id != '(')
//             {
//                 res += top->id;
//                 pop();
//             }
//             if (top != NULL)
//             {
//                 pop();
//             }
//         }
//         else
//         {
//             while (top != NULL && prec(top->id) > prec(c[i]))
//             {
//                 res += top->id;
//                 pop();
//             }
//             insertion(c[i]);
//         }
//     }
//     while (top != NULL)
//     {
//         res = res + top->id;
//         pop();
//     }
//     reverse(res.begin(), res.end());
//     cout << res;
// }

#include <iostream>
#include <stdlib.h>
using namespace std;

struct stack
{
    char c;
    stack *next;
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
    else if (c1 == '>' || c1 == '<' || c1=='!')
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
    if (top == NULL)
    {
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
}
void pop()
{
    struct stack *curr = top;
    top = top->next;
    free(curr);
}
int main()
{
    string c;
    string res;
    cout << "Enter the equation: " << endl;
    cin >> c;
    for (int i = 0; i < c.length(); i++)
    {
        if (c[i] >= 'a' && c[i] <= 'z' || c[i] >= 'A' && c[i] <= 'Z')
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
            if (c[i] == '&' || c[i] == '|' || c[i]=='!')
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
    for(int i=0;i<res.length();i++){
        if(res[i]=='&' || res[i]=='|'){
            cout<<res[i];
            cout<<res[i]<<" ";
        }
        else if(res[i]=='!'){
            cout<<res[i];
            cout<<'='<<" ";
        }
        else{
            cout<<res[i];
        }
    }
}

