/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
*/








#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int value){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}
void disp(struct node* root){
    struct node* p=root;
    stack<node*>s;
    while(1){
        while(p){
            cout<<p->data<<" ";
            s.push(p);
            p=p->left;
        }
        if(s.empty()) break;
        p=s.top();
        s.pop();
        p=p->right;
    }
}
int main(){

    struct node* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->right->left=newNode(4);
    root->right->left->right=newNode(5);
    disp(root);


    return 0;
}
