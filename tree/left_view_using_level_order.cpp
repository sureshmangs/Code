/*
Given a Binary Tree, print left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from left side.

left-view

Examples:

Input :
                 1
               /   \
              2     3
             / \     \
            4   5     6
Output : 1 2 4

Input :
        1
      /   \
    2       3
      \
        4
          \
            5
             \
               6
Output :1 2 4 5 6
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
void leftView(struct node* root){
       if(!root) return;
       queue<node*>q;
       q.push(root);
       while(!q.empty()){
           int size=q.size();
           while(size){
               node* tmp=q.front();
               q.pop();
               if(size==1) cout<<tmp->data<<" ";
               if(tmp->right) q.push(tmp->right);
               if(tmp->left) q.push(tmp->left);
               size--;
           }
   }

}
int main(){

    struct node* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->right->left=newNode(4);
    root->right->left->right=newNode(5);
    leftView(root);
    return 0;
}
