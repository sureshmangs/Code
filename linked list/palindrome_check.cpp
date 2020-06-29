/*
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.
Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains length of linked list N and next line contains N integers as data of linked list.

Output:
For each test case output will be 1 if the linked list is a palindrome else 0.

User Task:
The task is to complete the function isPalindrome() which takes head as reference as the only parameter and returns true or false if linked list is palindrome or not respectively.

Constraints:
1 <= T <= 103
1 <= N <= 50

Example:
Input:
2
3
1 2 1
4
1 2 3 4
Output:
1
0

Explanation:
Testcase 1: The given linked list is 1 2 1 , which is a pallindrome and Hence, the output is 1.
Testcase 2: The given linked list is 1 2 3 4 , which is not a pallindrome and Hence, the output is 0.
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
