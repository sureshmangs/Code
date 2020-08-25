/*
Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. Given a binary tree, print the top view of it. The output nodes can be printed in any order.

A node x is there in output if x is the topmost node at its horizontal distance. Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, and that of right child is horizontal distance of x plus 1.

       1
    /     \
   2       3
  /  \    / \
 4    5  6   7
Top view of the above binary tree is
4 2 1 3 7

        1
      /   \
    2       3
      \
        4
          \
            5
             \
               6
Top view of the above binary tree is
2 1 3 6
*/


// Approach, Use the concept of vertical order traversal and print the first node for each horizontal distance

#include<bits/stdc++.h>
using namespace std;


struct Node
{
	int data; //data of the node
	int hd; //horizontal distance of the node
	Node *left, *right; //left and right references

	Node(int key)
	{
		data = key;
		hd = INT_MAX;
		left = right = NULL;
	}
};


void verticalView(Node *root){
	if(!root) return;

	int hd = 0;

	map<int, vector<int> > mp;
	queue<Node*> q;

	// Assign initialized horizontal distance value to root node and add it to the queue.
	root->hd = hd;
	q.push(root);

	while (!q.empty())
	{
		Node *temp = q.front();
		q.pop();

		hd = temp->hd;

		mp[hd].push_back(temp->data);

		if(temp->left != NULL){
			temp->left->hd = hd-1;
			q.push(temp->left);
		}

		if(temp->right != NULL){
			temp->right->hd = hd+1;
			q.push(temp->right);
		}
	}

	for(auto it = mp.begin(); it != mp.end(); ++it){
        cout<<it->second[0]<<" ";
        cout<<endl;
	}

}


int main()
{
	Node *root = new Node(20);
	root->left = new Node(8);
	root->right = new Node(22);
	root->left->left = new Node(5);
	root->left->right = new Node(3);
	root->right->left = new Node(4);
	root->right->right = new Node(25);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(14);
	verticalView(root);
	return 0;
}
