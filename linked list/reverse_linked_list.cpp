/*
Given a linked list of N nodes. The task is to reverse this list.

Input:
The first line of input contains the number of test cases T. For each test case, the first line contains the length of the linked list and the next line contains the elements of the linked list.

Output:
For each test case, print the reversed linked list in a new line.

User Task:
The task is to complete the function reverseList() with head reference as the only argument and should return new head after reversing the list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N <= 104

Example:
Input:
2
6
1 2 3 4 5 6
5
2 7 8 9 10
Output:
6 5 4 3 2 1
10 9 8 7 2

Explanation:
Testcase 1: After reversing the list, elements are 6->5->4->3->2->1.
Testcase 2: After reversing the list, elements are 10->9->8->7->2.
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

int main(){
    struct node* head=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        head=createList(head, data);
    }
    cout<<"\nbefore reverse\n";
    disp(head);
    cout<<"\nAfter reverse\n";
    head=reversal(head);
    disp(head);
}
