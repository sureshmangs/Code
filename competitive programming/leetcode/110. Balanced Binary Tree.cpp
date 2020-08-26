Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.



Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.









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

    int isBalancedUtil(TreeNode* root, bool &isBal){
        // base case: tree is empty or tree is not balanced
        if(!root || !isBal)
            return 0;

        int lh=isBalancedUtil(root->left, isBal);
        int rh=isBalancedUtil(root->right, isBal);

         // if absolute difference between height of
        // its left subtree and right subtree is more than 1 tree becomes unbalanced
        if(abs(lh-rh)>1) isBal=false;

        // return height of subtree rooted at current node
        return max(lh, rh)+1;

    }

    bool isBalanced(TreeNode* root) {
        bool isBal=true;  // flag to check if tree is balanced or not
        isBalancedUtil(root, isBal);
        return isBal;
    }
};
