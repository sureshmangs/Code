#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    int cnt;
    struct node* left;
    struct node* right;
};

struct node* newNode(int value){
    struct node* tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=value;
    tmp->cnt=1;
    tmp->left=tmp->right=NULL;
    return tmp;
};

node* insertIt(node* root, int key)
{   if(!root){
        root=newNode(key);
    } else if(root->data==key){
        root->cnt++;
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
    cout<<root->data<<"("<<root->cnt<<")"<<" ";
    inorder(root->right);
}

int main(){
    struct node* root=NULL;
    root = insertIt(root, 12);
    root = insertIt(root, 10);
    root = insertIt(root, 20);
    root = insertIt(root, 9);
    root = insertIt(root, 11);
    root = insertIt(root, 10);
    root = insertIt(root, 12);
    root = insertIt(root, 12);
    inorder(root);
    return 0;
}
