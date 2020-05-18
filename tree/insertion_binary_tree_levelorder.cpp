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

void insertIt(struct node* root,int value){
    if(!root) return;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        struct node* tmp=q.front();
        if(tmp->left) q.push(tmp->left);
        else { tmp->left=newNode(value); break; }
        if(tmp->right) q.push(tmp->right);
        else { tmp->right=newNode(value);  break;  }
        q.pop();
    }
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

    //add element
    insertIt(root,7);

    inorder(root);

    return 0;
}
