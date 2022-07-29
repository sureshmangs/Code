Given a binary search tree root, and k return the kth (0-indexed) smallest value in root. 
It is guaranteed that the tree has at least k + 1 nodes.

Constraints

k = n = 100,000 where n is the number of nodes in root
Example 1
Input
root =

           3
		 /	\
		2	 9
            /  \
           7   12
          / \
         4  8
      

k = 2
Output
4
Example 2
Input
root =

           3
		 /	\
		2	 9
            /  \
           7   12
          / \
         4  8

k = 0
Output
2





/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
void inorder(Tree *root, int &k, int &res) {
    if (!root) return;
    inorder(root->left, k, res);
    if (k == 0) res = root->val;
    k--;
    inorder(root->right, k, res);
}

int solve(Tree* root, int k) {
    int res;
    inorder(root, k, res);
    return res;
}
