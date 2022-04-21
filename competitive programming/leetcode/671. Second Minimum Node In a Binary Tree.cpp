Given a non-empty special binary tree consisting of nodes with the non-negative value, 
where each node in this tree has exactly two or zero sub-node. 
If the node has two sub-nodes, then this node's value is the smaller value among its 
two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.

Given such a binary tree, you need to output the second minimum value in the set 
made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

 

 

Example 1:


Input: root = [2,2,5,null,null,5,7]
Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:


Input: root = [2,2,2]
Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
 

Constraints:

The number of nodes in the tree is in the range [1, 25].
1 <= Node.val <= 231 - 1
root.val == min(root.left.val, root.right.val) for each internal node of the tree.








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
    long res = LONG_MAX;
    
    void traversal(TreeNode *root, int firstMin) {
        if (!root) return;
        if (root->val > firstMin && root->val < res) {
            res = root->val;
        }
        traversal(root->left, firstMin);
        traversal(root->right, firstMin);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        if (!root->left && !root->right) return -1;
        int firstMin = root->val;
        
        traversal(root, firstMin);
        
        return res == LONG_MAX ? -1: res;
    }
};
TC: O(N), where N is the number of nodes in the binary tree. We need to traverse all the nodes at least one time.

SC: O(h)=O(N) information in the call stack, where h is the height of the tree.







// Approach:
// We can observe that the root->val will be the first smallest element.
// So we can simply store it's value in firstMin = root->val

// Now, we need to find the smallest element which is greater than firstMin, 
// so in this way we can find the secondMin.

// We can do a tree traversal and try to find a value bigger than firstMin 
// and we keep updating our 'res' variable to store the minimum value.
