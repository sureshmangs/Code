Given a binary tree root, repeatedly delete all leaves that have even values. 
That is, if after deletions, a node becomes a leaf with an even value, it too should be deleted.

Constraints

n = 100,000 where n is the number of nodes in root
Example 1
Input
root =
             3
           /   \
          2     4
               /  \
              6   12
             / \
            4   7

Output
             3
              \
               4
               /
              6 
               \
                7
                
                
                


/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

 Tree* dfs(Tree *root) {
     if (!root) return root;
     root->left = dfs(root->left);
     root->right = dfs(root->right);

     if (!root->left && !root->right && root->val % 2 == 0) {
         delete root;
         return NULL;
     }
     return root;
 }
Tree* solve(Tree* root) {
    return dfs(root);
}
    
