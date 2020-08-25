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
        if(!root) return;
        stack<node*> s;
        while(1){
            while(root){
                if(root->right) s.push(root->right);
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            if(root->right && !s.empty() && root->right==s.top() ){
                    s.pop();
                    s.push(root);
                    root=root->right;

            } else {
                cout<<root->data<<" ";
                root=NULL;
            }
            if(s.empty()) break;
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
