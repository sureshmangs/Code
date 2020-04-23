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

void pairWiseSwap(struct node* head) {
    if(head==NULL) return ;
    struct node *p1=head, *p2=head->next;
    while(p2!=NULL){
        int tmp=p2->data;
        p2->data=p1->data;
        p1->data=tmp;

        if(p2->next!=NULL && p2->next->next!=NULL){
            p1=p2->next;
            p2=p1->next;
        } else break;
    }
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
    disp(head);
    cout<<endl;
    pairWiseSwap(head);
    disp(head);
}
