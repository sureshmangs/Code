/*
For a given BST
You need to find the inorder successor and predecessor of a given key

         50
		/  \
       30   70
      /  \ /  \
	20 40 60  80

	For key=65
	Predecessor = 60
	Successor = 70
*/




#include <iostream>
using namespace std;


struct Node {
    int key;
	struct Node *left, *right;
};


void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
	if (!root) return;

	if (root->key == key){
		// the maximum value in left subtree is predecessor
		if(root->left != NULL){
			Node* tmp = root->left;
			while(tmp->right)
				tmp = tmp->right;
			pre = tmp ;
		}

		// the minimum value in right subtree is successor
		if (root->right != NULL){
			Node* tmp = root->right ;
			while (tmp->left)
				tmp = tmp->left ;
			suc = tmp ;
		}
		return;
	}

	// If key is smaller than root's key, go to left subtree
	if (root->key > key){
		suc = root ;
		findPreSuc(root->left, pre, suc, key) ;
	}
	else { // go to right subtree
		pre = root ;
		findPreSuc(root->right, pre, suc, key) ;
	}
}


Node *newNode(int item)
{
	Node *temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}


Node* insert(Node* node, int key)
{
	if (node == NULL) return newNode(key);
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);
	return node;
}


int main(){
/*

         50
		/  \
       30   70
      /  \ /  \
	20  40 60  80

*/
	Node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

    int key = 65;
	Node* pre = NULL, *suc = NULL;

	findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << "Predecessor is " << pre->key << endl;
	else
	cout << "No Predecessor";

	if (suc != NULL)
	cout << "Successor is " << suc->key;
	else
	cout << "No Successor";
	return 0;
}
