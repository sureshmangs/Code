Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6







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

 // Recursive
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;

        TreeNode *left=root->left;
        TreeNode *right=root->right;

        root->left=NULL;

        flatten(left);
        flatten(right);

        root->right=left;

        TreeNode* curr=root;
        while(curr->right!=NULL) curr=curr->right;

        curr->right=right;
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


 // Iterative
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode *curr=root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                if(curr->right!=NULL){
                    TreeNode *ahead=curr->left;
                    while(ahead->right!=NULL) ahead=ahead->right;
                    ahead->right=curr->right;
                }
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};
