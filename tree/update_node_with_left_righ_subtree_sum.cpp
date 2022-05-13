Given a binary tree root, return the same tree except every node's value is 
replaced by its original value plus all of the sums of its left and right subtrees.

Constraints

n = 100,000 where n is the number of nodes in root
Example 1
Input
root =
            2
          /   \
         1     4
        /     /
       0     3

Output
            10
          /   \
         1     7
        /     /
       0     3








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
    int totalSum = root->val + leftSum + rightSum;
    root->val += leftSum + rightSum;
    return totalSum;
}

Tree* solve(Tree* root) {
    if (!root) return root;
    int sum = dfs(root);
    return root;
}
