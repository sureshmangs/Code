Given the root of a binary search tree, rearrange the tree in in-order 
so that the leftmost node in the tree is now the root of the tree, 
and every node has no left child and only one right child.



Example 1:


Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
Example 2:


Input: root = [5,1,7]
Output: [1,null,5,null,7]


Constraints:

The number of nodes in the given tree will be in the range [1, 100].
0 <= Node.val <= 1000








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

    void inorder(TreeNode *root, vector<int> &v){
        if(!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        TreeNode *res= new TreeNode(0); //dummy
        TreeNode *curr=res;
        for(auto &x: v){
            curr->right=new TreeNode(x);
            curr=curr->right;
        }

        return res->right;
    }
};
// TC-> O(N), SC -> O(N)

















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
    TreeNode *cur; // declared globally because 'cur'would have different values in different call stack
    
    void inorder(TreeNode *root) {
        if (!root) return;
        
        inorder(root->left);
        root->left = NULL;
        cur->right = root;
        cur = root;
        inorder(root->right); 
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *res = new TreeNode(0);
        cur = res;
        
        inorder(root);
        
        return res->right;
    }
};
// TC-> O(N), SC -> O(H), H -> Height of tree and the size of the 
// implicit call stack in our in-order traversal.
