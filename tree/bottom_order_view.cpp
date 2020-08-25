/*
Given a Binary Tree, we need to print the bottom view from left to right. A node x is there in output if x is the bottommost node at its horizontal distance. Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, and that of right child is horizontal distance of x plus 1.

Examples:

                      20
                    /    \
                  8       22
                /   \      \
              5      3      25
                    / \
                  10    14

For the above tree the output should be 5, 10, 3, 14, 25.

If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottom-most nodes at horizontal distance 0, we need to print 4.


                      20
                    /    \
                  8       22
                /   \    /   \
              5      3 4     25
                    / \
                  10    14
For the above tree the output should be 5, 10, 4, 14, 25.
*/


// Approach, Use the concept of vertical order traversal and print the last node for each horizontal distance

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
        vector<int> v=it->second;
        cout<<v[v.size()-1]<<" ";
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
