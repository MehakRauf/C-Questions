#include <iostream>
#include <stdlib.h>
using namespace std;

struct queue{
    int id;
    struct queue* next;
    struct queue* prev;
};
struct queue* front=NULL;
struct queue* rear=NULL;

void EnQueue(){
    struct queue* temp=(struct queue*)malloc(sizeof(struct queue));
    cout<<"Enter the id: "<<endl;
    cin>>temp->id;
    temp->next=NULL;
    if(front==NULL){
        front=temp;
        rear=temp;
    }
    else{
        while(rear->next!=NULL){
            rear=rear->next;
        }
        rear->next=temp;
        temp->prev=rear;
    }
}
void deletion(){
    if(front==rear){
        free(front);
        front=NULL;
        rear=NULL;
    }
    struct queue* curr=front;
    if(front==NULL){
        cout<<"Queue is empty."<<endl;
    }
    else{
        front=front->next;
        free(curr);
    }
}
void print(){
    struct queue* curr=front;
    while(curr!=NULL){
        cout<<curr->id<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

int main(){
    EnQueue();
    EnQueue();    
    EnQueue();
    EnQueue();
    print();
    EnQueue();
    EnQueue();
    deletion();
    print();
    }