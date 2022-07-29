You are given a binary tree root with each node containing single digits from 0 to 9. 
Each path from the root to the leaf represents a number with its digits in order.

Return the sum of numbers represented by all paths in the tree.

Example 1
Input
root =
  			 3
  		   /   \
  		  5      2
  		       /  \ 
              1    4
Output
680
Explanation
We have the following numbers represented by paths:

35 (3 ? 5)
321 (3 ? 2 ? 1)
324 (3 ? 2 ? 4)
Example 2
Input
root =
  			 1
  		   /   \
  		  2      3	


Output
25
Explanation
We have 12 + 13 = 25.







/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

void dfs(Tree* root, int num, int &res) {
    if (!root) return;
    int newNum = num * 10 + root->val;
    if (!root->left && !root->right) res += newNum;
    dfs(root->left, newNum, res);
    dfs(root->right, newNum, res);
}

int solve(Tree* root) {
    int res = 0;
    if (!root) return res;
    dfs(root, 0, res);
    return res;
}
