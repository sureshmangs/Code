/*
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
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
        if(!root) return ;
        stack<node*> s1,s2;
        s1.push(root);
        while(!s1.empty()){
            node *tmp=s1.top();
            s1.pop();
            s2.push(tmp);
            if(tmp->left) s1.push(tmp->left);
            if(tmp->right) s1.push(tmp->right);
        }
        while(!s2.empty()){
            cout<<s2.top()->data<<" ";
            s2.pop();
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
