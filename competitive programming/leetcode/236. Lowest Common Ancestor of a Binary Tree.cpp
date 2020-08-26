Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]




Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.


Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.










/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* LCAUtil(TreeNode* root, TreeNode* p, TreeNode* q, bool &v1, bool &v2){
        if(!root) return NULL;

        if(root==p){
            v1=true;
            return p;
        } else if(root==q){
            v2=true;
            return q;
        }

        TreeNode* lca_left=LCAUtil(root->left, p, q, v1, v2);
        TreeNode* lca_right=LCAUtil(root->right, p, q, v1, v2);

        if(lca_left && lca_right) return root;

        return lca_left!=NULL ? lca_left : lca_right;  // if both are NULL then lca_right is returned which is NULL
    }

    bool find(TreeNode* root, TreeNode* x){
        if(!root) return false;

        return (root==x || find(root->left, x) || find(root->right, x));
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Initialize p and q as not visited
        bool v1=false, v2=false;

        TreeNode* lca=LCAUtil(root, p, q, v1, v2);

        // Return LCA only if both n1 and n2 are present in tree
        if(v1 && v2 || v1 && find(lca, q) || v2 && find(lca, p));
        return lca;

        return NULL;

    }
};
