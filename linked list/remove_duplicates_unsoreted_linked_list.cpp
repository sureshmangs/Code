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

void removeDuplicate(struct node* head){
    unordered_set<int> s;
    struct node* tmp=head;
    struct node* prev=NULL;
    while(tmp!=NULL){
        if(s.find(tmp->data)!=s.end()){
            prev->next=tmp->next;
            free(tmp);
            tmp=prev->next;

        }
        else {
            s.insert(tmp->data);
            prev=tmp;
            tmp=tmp->next;
        }
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
    removeDuplicate(head);
    disp(head);
}
