#include <bits/stdc++.h>
using namespace std;


struct Node {
	int data;
	Node *left, *right;
};

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->left = temp->right = NULL;
	temp->data = key;
	return temp;
}

Node* insert(Node* root, int key)
{
	if (!root)
		return newNode(key);
	if (key < root->data)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);
	return root;
}


void findFloorCeil(Node* root, Node* &floor, Node* &ceil, int key){
	if (!root) return;

	if (root->data == key){
		floor = root;
		ceil = root;
	} else if (key < root->data){
		ceil = root;
		findFloorCeil(root->left, floor, ceil, key);
	} else {
		floor = root;
		findFloorCeil(root->right, floor, ceil, key);
	}
}



int main()
{
	/* Let us create following BST
           7
          / \
		 5	 10
		/ \  / \
		3 6 8 12
    */
	Node* root = NULL;
	root = insert(root, 7);
	insert(root, 10);
	insert(root, 5);
	insert(root, 3);
	insert(root, 6);
	insert(root, 8);
	insert(root, 12);

	Node *floor=NULL, *ceil=NULL;
	int key=9;
    findFloorCeil(root, floor, ceil, key);
    cout<<int(floor ? floor->data : -1)<<endl;
    cout<<int(ceil ? ceil->data : -1)<<endl;

	return 0;
}








// Iterative
/*
void findFloorCeil(Node* root, Node* &floor, Node* &ceil, int key){
    while (root){
		if (root->data == key){
			floor = root;
			ceil = root;
			break;
		}
		else if (key < root->data){
			ceil = root;
			root = root->left;
		}
		else {
			floor = root;
			root = root->right;
		}
	}
}




Node *floor=NULL, *ceil=NULL;
int key=9;
findFloorCeil(root, floor, ceil, key);
cout<<int(floor ? floor->data : -1)<<endl;
cout<<int(ceil ? ceil->data : -1)<<endl;
*/
