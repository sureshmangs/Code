/*
Given a Binary Search Tree (BST) and a positive integer k,
find the k’th largest element in the Binary Search Tree.
For example, in the following BST, if k = 3, then output should be 60

          50
		 /	\
		30	 70
       /  \ /  \
      20 40 60 80
*/







#include<bits/stdc++.h>
using namespace std;

struct Node{
	int key;
	Node *left, *right;
};


Node *newNode(int item){
	Node *temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}


void kthLargestUtil(Node *root, int k, int &c){
	if (!root || c >= k)
		return;

	// reverse inorder traversal so that the largest element is visited first
	kthLargestUtil(root->right, k, c);

	c++;    // Increment count of visited nodes

	// If c becomes k now, then this is the k'th largest
	if(c == k){
        cout<<"Kth largest element is "<< root->key << endl;
		return;
	}

	// Recur for left subtree
	kthLargestUtil(root->left, k, c);
}


void kthLargest(Node *root, int k){
	int c = 0;    // Initialize count of nodes visited as 0

	kthLargestUtil(root, k, c);
}


Node* insert(Node* node, int key){
	if (node == NULL) return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
}


int main(){
/*
          50
		 /	\
		30	 70
       /  \ /  \
      20 40 60 80
*/


	Node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	int c = 0;
	int k=3;
    kthLargest(root, k);

	return 0;
}
