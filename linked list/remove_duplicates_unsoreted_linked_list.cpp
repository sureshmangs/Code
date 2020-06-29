/*
Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. If all the nodes in the linked list are equal, then remove n-1 nodes.

Input:
The first line of input contains the number of test cases T. For each test case, the first line of input contains a number of nodes in the linked list, and the next line contains node data for N nodes.

Output:
For each test case, print the linked list with no repeating elements.

User Task:
You have to complete the method removeDuplicates() which takes 1 argument: the head of the linked list. You should not read any input from the stdin/console. Your function should return a pointer to a linked list with no duplicate element.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= T <= 100
1 <= size of linked lists <= 104
1 <= numbers in list <= 104

Example:
Input:
2
4
5 2 2 4
5
2 2 2 2 2
Output:
5 2 4
2

Explanation:
Testcase 1: Given linked list elements are 5->2->2->4, in which 2 is repeated only. So, we will delete the extra repeated elements 2 from the linked list and the resultant linked list will contain 5->2->4.
Testcase 2: Given linked list elements are 2->2->2->2->2, in which 2 is repeated. So, we will delete the extra repeated elements 2 from the linked list and the resultant linked list will contain only 2.
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
