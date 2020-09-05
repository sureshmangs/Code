/*
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place.
The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL.
The order of nodes in DLL must be same as Inorder of the given Binary Tree.
The first node of Inorder traversal (left most node in BT) must be head node of the DLL.

            10
           /  \
        12     15
       /  \    /
    25    30  36

Output:  25 12 30 10 36 15 is a doubly linked list
*/






#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};


void BinaryTree2DoubleLinkedList(node *root, node* &head){
	if(!root) return;

	static node* prev = NULL;

	// Recursively convert left subtree
	BinaryTree2DoubleLinkedList(root->left, head);

	// Now convert this node
	if(prev == NULL)
		head = root;
	else {
		root->left = prev;
		prev->right = root;
	}
	prev = root;

	// Finally convert right subtree
	BinaryTree2DoubleLinkedList(root->right, head);
}


node* newNode(int data){
	node* new_node = new node;
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return (new_node);
}

void printList(node *node){
	while (node!=NULL){
		cout << node->data << " ";
		node = node->right;
	}
}


int main(){
	node *root	 = newNode(10);
	root->left	 = newNode(12);
	root->right	 = newNode(15);
	root->left->left = newNode(25);
	root->left->right = newNode(30);
	root->right->left = newNode(36);

	node *head = NULL;
	BinaryTree2DoubleLinkedList(root, head);

	printList(head);

	return 0;
}
