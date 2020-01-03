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


void disp(struct node* root){
    if(!root) return;
    disp(root->left);
    cout<<root->data<<" ";
    disp(root->right);
}

int main(){
    int arr[]={1,2,3,4,5,6};
    struct node* root=NULL;

    //complete binary tree
    queue<node*>q;
    int n= sizeof(arr)/sizeof(arr[0]);
    if(!n) return 0;
    int i=0;
    root=newNode(arr[i++]);
    q.push(root);

    while(!q.empty() && i<n){
        struct node* tmp=q.front();
        if(!tmp->left) { tmp->left=newNode(arr[i++]);  q.push(tmp->left);  }
        else if(!tmp->right) { tmp->right=newNode(arr[i++]);   q.push(tmp->right);   }
        else q.pop();
    }
    disp(root);
}
