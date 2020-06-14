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

bool isValidBST(node *root, long long mini, long long maxi){
    if(!root) return true;
    if(root->data<=mini || root->data>=maxi) return false;
    return isValidBST(root->left, mini, root->data) && isValidBST(root->right, root->data, maxi);
}
int main(){

    struct node* root=newNode(5);
    root->left=newNode(1);
    root->right=newNode(9);
    root->right->left=newNode(6);
    root->right->right=newNode(12);
    if(isValidBST(root, (long long)INT_MIN-1, (long long)INT_MAX+1)) cout<<"VALID BST"<<endl;
    else cout<<"INVALID BST"<<endl;

    return 0;
}
