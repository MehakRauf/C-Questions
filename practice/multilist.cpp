#include <iostream>
#include <stdlib.h>
using namespace std;

struct Course
{
    int CNo;
    struct Student *sstart;
    struct Course *next;
};
struct Course *start = NULL;

struct Student
{
    int id;
    struct Student *next;
};

void course_insert(int val)
{
    struct Course *temp = (struct Course *)malloc(sizeof(struct Course));
    temp->CNo = val;
    temp->next = NULL;
    temp->sstart = NULL;
    if (start == NULL)
    {
        start = temp;
        return;
    }
    else
    {
        struct Course *curr = start;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}
void student_insert(int cno, int val)
{
    struct Student *temp = (struct Student *)malloc(sizeof(struct Student));
    temp->id = val;
    temp->next = NULL;
    struct Course *curr = start;
    while (curr != NULL)
    {
        if (curr->CNo == cno)
        {
            if (curr->sstart == NULL)
            {
                curr->sstart = temp;
            }
            else
            {
                struct Student *curr1 = curr->sstart;
                while (curr1->next != NULL)
                {
                    curr1 = curr1->next;
                }
                curr1->next = temp;
            }
            break;
        }
        curr = curr->next;
    }
}
void delete_course(int val)
{
    struct Course *curr = start;
    struct Course *prev = NULL;
    while (curr != NULL)
    {
        if (curr->CNo == val)
        {
            if (start->CNo == val)
            {
                start = start->next;
                break;
            }
            struct Course *temp = curr;
            prev->next = curr->next;
            free(temp);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}
void delete_student(int val, int cno)
{
    struct Course *curr = start;
    while (curr != NULL)
    {
        if (curr->CNo == cno)
        {
            struct Student *prev = NULL;
            struct Student *curr2 = curr->sstart;
            if (curr->sstart->id == val)
            {
                curr->sstart = curr->sstart->next;
                break;
            }
            else
            {
                while (curr2 != NULL)
                {
                    if (curr2->id == val)
                    {
                        prev->next = curr2->next;
                        struct Student *temp = curr2;
                        free(temp);
                    }
                    prev = curr2;
                    curr2 = curr2->next;
                }
            }
        }
        curr = curr->next;
    }
}
void print()
{
    struct Course *curr1 = start;
    while (curr1 != NULL)
    {
        cout << "The course no is " << endl;
        cout << curr1->CNo << endl;
        struct Student *curr2 = curr1->sstart;
        cout << "The allocated students are: " << endl;
        while (curr2 != NULL)
        {
            cout << curr2->id << " ";
            curr2 = curr2->next;
        }
        cout << endl;
        curr1 = curr1->next;
    }
}
int main()
{
    course_insert(1);
    course_insert(3);
    course_insert(2);
    course_insert(6);
    course_insert(9);
    student_insert(1, 3);
    student_insert(1, 7);
    student_insert(2, 3);
    student_insert(6, 0);
    student_insert(9, 21);
    student_insert(3, 13);
    student_insert(2, 13);
    delete_course(1);
    delete_student(0,6);
    print();
}