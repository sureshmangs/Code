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
void levelorder(struct node* root){
    queue<node*>q;
    if(!root) return;
    q.push(root);
    while(!q.empty()){
        struct node* tmp=q.front();
        q.pop();
        cout<<tmp->data<<" ";
        if(tmp->left) q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
    }
}
int main(){

    struct node* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->right->left=newNode(4);
    root->right->left->right=newNode(5);
    levelorder(root);


    return 0;
}
