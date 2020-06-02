#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int value){
    struct node* tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=value;
    tmp->left=tmp->right=NULL;
    return tmp;
};


node* invertTree(struct node* root) {
        if(!root) return root;
        queue<node*>q;
        q.push(root);
        while(!q.empty()){
            struct node* cur = q.front();
            q.pop();
            swap(cur->left, cur->right);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return root;
}

void inorder(struct node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    struct node* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->right=newNode(4);
    inorder(root);
    cout<<endl;
    root = invertTree(root);
    inorder(root);
    return 0;
}
