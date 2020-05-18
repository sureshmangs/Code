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
void deleteDeepest(struct node* root, struct node* last){
    if(!root) return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        struct node *tmp=q.front();
        q.pop();
        if(tmp->left){
            if(tmp->left==last){
                tmp->left=NULL;
                delete last;
                return;
            } else q.push(tmp->left);
        }if(tmp->right){
         if(tmp->right==last){
                tmp->right=NULL;
                delete last;
                return;
            } else q.push(tmp->right);
        }
    }
}

node* deletion(struct node* root, int key)
{
    if(!root) return root;
    if(!root->left && !root->right){
        if(root->data==key){
            struct node* tmp=root;
            root=NULL;
            delete tmp;
            return root;
        } else return root;
    }
    queue<node*>q;
    q.push(root);
    struct node* last=NULL;
    struct node* todel=NULL;
    struct node* tmp=NULL;
    while(!q.empty()){
        tmp=q.front();
        q.pop();
        if(tmp->left) q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
        if(tmp->data==key) todel=tmp;
    }
    last=tmp;
    if(todel){
        todel->data=last->data;
        deleteDeepest(root, last);
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

    struct node* root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->left->right = newNode(12);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);
    inorder(root);
    cout<<endl;
    root=deletion(root,8);
    inorder(root);
    return 0;
}
