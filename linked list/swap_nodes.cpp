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

    if(preX==NULL) head=curY;
    else preX->next=curY;
    if(preY==NULL) head=curX;
    else preY->next=curX;

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
    swapNodes(head,x,y);
    disp(head);
}
