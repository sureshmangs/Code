Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.



Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently?
How would you optimize the kthSmallest routine?



Constraints:

The number of elements of the BST is between 1 to 10^4.
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.





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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;

        while(true){
            while(root!=NULL){
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            if(--k == 0) return root->val;
            root=root->right;
        }
    }
};











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
    int cnt = 0, res = -1;
    
    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        if (--cnt == 0) {
            res = root->val;
            return;
        }
        inorder(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        cnt = k;
        inorder(root);
        return res;
    }
};





// Approach 1: Recursive Inorder Traversal
// Build an inorder traversal of BST which is an array sorted in the ascending order
// Now the answer is the k - 1th element of this array
// Time complexity : O(N) to build a traversal
// Space complexity : O(N) to keep an inorder traversal

// Approach 2: Iterative Inorder Traversal
// Time complexity: O(H+k), where H is a tree height
// Space complexity: )O(H) to keep the stack, where H is a tree height.
// That makes O(N) in the worst case of the skewed tree
// and O(logN) in the average case of the balanced tree
