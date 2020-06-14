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

int maxPathSumUtil(node* root, int &res){
    if(!root) return 0;
    int l=maxPathSumUtil(root->left, res);
    int r=maxPathSumUtil(root->right, res);
    int temp=max(max(l,r)+root->data, root->data);
    int ans=max(temp, l+r+root->data);
    res=max(res, ans);

    return temp;
}

int maxPathSum(node* root) {
    int res=INT_MIN;
    maxPathSumUtil(root, res);
    return res;
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
    root->right->left=newNode(4);
    root->right->left->right=newNode(5);
    cout<<maxPathSum(root)<<endl;

    return 0;
}
