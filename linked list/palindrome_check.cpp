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

struct node* findMid(struct node* head){
    struct node *slow=head, *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
};

struct node* reversal(struct node* head){
    if(head==NULL) return head;
    struct node *cur=head, *prev=head, *ahead=head->next;
    prev->next=NULL;
    cur=ahead;
    while(ahead!=NULL){
        ahead=ahead->next;
        cur->next=prev;
        prev=cur;
        cur=ahead;
    }
    head=prev;
    return head;
}

bool palindromeCheck(struct node *head){
        struct node *mid=findMid(head);
        struct node*last=reversal(mid);

        while(head!=mid){
            if(head->data!=last->data) return false;
                head=head->next;
                last=last->next;
        }
        return true;
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
    if(palindromeCheck(head)){
        cout<<"\nLinked List is Palindrome\n";
    } else {
        cout<<"\nLinked List is not Palindrome\n";
    }
}
