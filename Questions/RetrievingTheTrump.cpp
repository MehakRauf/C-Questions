#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
    int num;
    struct node* next;
};
struct node* start=NULL;
int arr[]={1,2};
void GetTrump(){
    struct node* curr=start;
    struct node* runner=start;
    struct node* prev=NULL;
    while(runner!=NULL && runner->next!=NULL){
        prev=curr;
        curr=curr->next;
        runner=runner->next->next;
    }
    if(runner==NULL){
        cout<<prev->num<<" "<<prev->next->num<<endl;
    }
    else{
        cout<<curr->num;
    }
}

void ADD(){
    struct node* curr;
    
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    cout<<"Enter the number: "<<endl;
    cin>>temp->num;
    temp->next=NULL;
    if(start==NULL){
        start=temp;
    }
    else{
        curr=start;    
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=temp;
    }
    
       
}
void DELETE(){
    struct node* curr=start;
    struct node* prev=NULL;
    while(curr->next!=NULL){
        prev=curr;
        curr=curr->next;
    }
    prev->next=NULL;
    free(curr);
}
void PRINT(){
    struct node* curr=start;
    while(curr!=NULL){
        cout<<curr->num<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
int main(){
ADD();
DELETE();
PRINT();
}