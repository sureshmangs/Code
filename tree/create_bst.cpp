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

node* insertIt(node* root, int key)
{   if(!root){
        root=newNode(key);
    } else if(key<root->data){
        root->left=insertIt(root->left, key);
    } else if(key > root->data){
        root->right=insertIt(root->right, key);
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
    struct node* root=NULL;
    root=insertIt(root,2);
    root=insertIt(root,3);
    root=insertIt(root,1);
    root=insertIt(root,6);
    inorder(root);
    return 0;
}
