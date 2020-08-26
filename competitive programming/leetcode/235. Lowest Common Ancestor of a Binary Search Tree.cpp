Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]




Example 1:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.


Constraints:

All of the nodes' values will be unique.
p and q are different and both values will exist in the BST.








/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


 // Recursive
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

        if(root->val > p->val && root->val > q->val)
            return LCAUtil(root->left, p, q, v1, v2);

        if(root->val < p->val && root->val < q->val)
            return LCAUtil(root->right, p, q, v1, v2);

        return root;
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




// Iterative
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        while(root!=NULL){
            if(root->val > p->val && root->val > q->val)
                root=root->left;
            else if(root->val < p->val && root->val < q->val)
                root=root->right;
            else break;
        }
        return root;
    }
};
