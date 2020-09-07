Given a Binary Search Tree and a target number,
return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:

Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True


Example 2:

Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False







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

    bool inorder(TreeNode* root, int k, set<int> &s){
        if(!root) return false;
        if(s.find(k-root->val)!=s.end()) return true;
        s.insert(root->val);
        return inorder(root->left, k, s) || inorder(root->right, k, s);
    }

    bool findTarget(TreeNode* root, int k) {
        set<int> s;
        return inorder(root, k, s);
    }
};



// Approach 1
// Using simple hashset

// Approach 2
// Store the inorder traversal result in an array
// The inorder traversal is sorted
// Apply two pointer technique to get the result
