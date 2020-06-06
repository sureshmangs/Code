#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

void leftViewUtil(node* root,int level, int* maxLevel){
    if(!root) return;
    if(*maxLevel<level){
        cout<<root->data<<" ";
        *maxLevel=level;
    }
    leftViewUtil(root->left, level+1, maxLevel);
    leftViewUtil(root->right, level+1, maxLevel);

}


struct node* newNode(int value){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}
void leftView(struct node* root){
        int maxLevel=0;
        leftViewUtil(root, 1, &maxLevel);
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
