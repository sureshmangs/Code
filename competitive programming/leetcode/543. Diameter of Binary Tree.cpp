Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.










/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int getDiameter(TreeNode* root, int &res){
        if(!root) return 0;

        int l=getDiameter(root->left, res);
        int r=getDiameter(root->right, res);

        int tmp=max(l,r)+1;
        int ans=max(tmp, l+r+1);
        res=max(res, ans);

        return tmp;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int res=INT_MIN;
        getDiameter(root, res);
        return res-1;
    }
};
