/*
Given a binary tree, print it vertically. 
The following example illustrates vertical order traversal.


           1
        /    \
       2      3
      / \    / \
     4   5  6   7
             \   \
              8   9


The output of print this tree vertically will be:
4
2
1 5 6
3 8
7
9
*/




/*
HD for root is 0, a right edge (edge connecting to right subtree) is considered as +1 horizontal distance
and a left edge is considered as -1 horizontal distance.


For every HD value, we maintain a list of nodes in a hash map.
Whenever we see a node in traversal, we go to the hash map entry and add t
he node to the hash map using HD as a key in a map.
*/


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
        vector<int>v=it->second;
        for(auto &x: v)
            cout<<x<<" ";
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
