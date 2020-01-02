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
void postorder(struct node* root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){

    struct node* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->right->left=newNode(4);
    root->right->left->right=newNode(5);
    postorder(root);


    return 0;
}
