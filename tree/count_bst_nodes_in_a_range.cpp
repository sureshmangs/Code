Given a binary search tree root, and integers lo and hi, 
return the count of all nodes in root whose values are between [lo, hi] (inclusive).

Constraints

n = 100,000 where n is the number of nodes in root
Example 1
Input
Visualize
root =
         3
       /   \
      2      9
           /  \
          7   12
         / \
        4   8
      
lo = 5
hi = 10
Output
3
Explanation
Only 7, 8, 9 are between [5, 10].












/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

void dfs(Tree *root, int lo, int hi, int &cnt) {
    if (!root) return;
    if (root->val >= lo && root->val <= hi) {
        cnt++;
        dfs(root->left, lo, hi, cnt);
        dfs(root->right, lo, hi, cnt);
    } else if (root->val < lo) dfs(root->right, lo, hi, cnt);
    else dfs(root->left, lo, hi, cnt);
}

int solve(Tree* root, int lo, int hi) {
    if (!root) return 0;
    int cnt = 0;
    dfs(root, lo, hi, cnt);
    return cnt;
}
