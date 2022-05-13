Given a binary tree root, return the sum of all leaves that are right children.

Constraints

n = 100,000 where n is the number of nodes in root
Example 1
Input
root =

          1
        /  \
       2    3
     /  \     \
    4    5     8 
     \        /  \
      2       6   7

Output :
sum = 14







/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

void dfs(Tree *root, int &sum) {
    if (!root) return;
    // check if roots right child is a leaf node
    if (root->right && !root->right->left && !root->right->right) sum += root->right->val;
    dfs(root->left, sum);
    dfs(root->right, sum);
}

int solve(Tree* root) {
    int sum = 0;
    dfs(root, sum);
    return sum;
}
