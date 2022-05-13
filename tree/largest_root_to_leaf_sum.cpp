Given the root to a binary tree root, 
return the largest sum of any path that goes from the root to a leaf.

Constraints

n = 100,000 where n is the number of nodes in root
Example 1
Input
root =
			  1
			/   \
		   5      4
		        /   \
		       7     12
		      /  \
			 4    8


Output
20
Explanation
The path with the largest sum is 1 -> 4 -> 7 -> 8








/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

int dfs(Tree *root) {
    if (!root) return 0;
    int leftSum = dfs(root->left);
    int rightSum = dfs(root->right);
    return root->val + max(leftSum, rightSum);
}

int solve(Tree* root) {
    return dfs(root);
}
