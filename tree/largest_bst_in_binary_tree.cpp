/*
Given a Binary Tree, write a function that returns the size of the largest subtree which is also a Binary Search Tree (BST).
If the complete Binary Tree is BST, then return the size of the whole tree.
Examples:

Input:
      5
    /  \
   2    4
 /  \
1    3

Output: 3
The following subtree is the
maximum size BST subtree
   2
 /  \
1    3


Input:
       50
     /    \
  30       60
 /  \     /  \
5   20   45    70
              /  \
            65    80
Output: 5
The following subtree is the
maximum size BST subtree
      60
     /  \
   45    70
        /  \
      65    80

*/






#include <bits/stdc++.h>
using namespace std;


struct Node{;
	int data;
	struct Node* left;
	struct Node* right;
};


struct Node* newNode(int data){
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return(node);
}

// Information to be returned by every node in bottom up traversal
struct Info{
	int sz; // Size of subtree
	int max; // Min value in subtree
	int min; // Max value in subtree
	int ans; // Size of largest BST which
	// is subtree of current node
	bool isBST; // If subtree is BST
};


Info largestBSTBT(Node* root){
	if(!root)
		return {0,INT_MIN, INT_MAX, 0, true};
	if(!root->left && !root->right)
		return {1, root->data, root->data, 1, true};

	// Recur for left subtree and right subtrees
	Info l = largestBSTBT(root->left);
	Info r = largestBSTBT(root->right);

	// Create a return variable and initialize its size
	Info ret;
	ret.sz = 1 + l.sz + r.sz;

	// If whole tree rooted under current root is
	// BST.
	if(l.isBST && r.isBST && l.max < root->data && r.min > root->data){
		ret.min = min(l.min, root->data);
		ret.max = max(r.max, root->data);

		// Update answer for tree rooted under current 'root'
		ret.ans = ret.sz;
		ret.isBST = true;

		return ret;
	}

	// If whole tree is not BST, return maximum of left and right subtrees
	ret.ans = max(l.ans, r.ans);
	ret.isBST = false;

	return ret;
}


int main(){

/*

         60
        /  \
       65  70
       /
      50


*/

	struct Node *root = newNode(60);
	root->left = newNode(65);
	root->right = newNode(70);
	root->left->left = newNode(50);
    cout<<largestBSTBT(root).ans;
	return 0;
}



// Time Complexity : O(n)
