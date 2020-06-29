/*
Given a linked list and two keys in it, swap nodes for two given keys. Nodes should be swapped by changing links. Swapping data of nodes may be expensive in many situations when data contains many fields.
It may be assumed that all keys in linked list are distinct.

Examples:

Input:  10->15->12->13->20->14,  x = 12, y = 20
Output: 10->15->20->13->12->14

Input:  10->15->12->13->20->14,  x = 10, y = 20
Output: 20->15->12->13->10->14

Input:  10->15->12->13->20->14,  x = 12, y = 13
Output: 10->15->13->12->20->14
*/











#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* next;
};

struct node* createList(struct node* head, int data){
    struct node *tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->next=NULL;
    if(head==NULL){
        head=tmp;
        return head;
    }
    struct node* p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=tmp;
    return head;
}

void disp(struct node* head){
    struct node* p=head;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}

struct node* swapNodes(struct node* head, int x, int y){
    if(x==y) return head;
    struct node *preX=NULL, *curX=head, *preY=NULL, *curY=head;
    while(curX!=NULL && curX->data!=x){
        preX=curX;
        curX=curX->next;
    }
    while(curY!=NULL && curY->data!=y){
        preY=curY;
        curY=curY->next;
    }

    if(curX==NULL || curY==NULL) return head;

    if(preX!=NULL) preX->next=curY;
    else head=curY;

    if(preY!=NULL) preY->next=curX;
    else head=curX;

    struct node* tmp=curY->next;
    curY->next=curX->next;
    curX->next=tmp;
    return head;
}

int main(){
    struct node* head=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        head=createList(head, data);
    }
    int x, y;
    cin>>x>>y;
    disp(head);
    cout<<endl;
    head=swapNodes(head,x,y);
    disp(head);
}
