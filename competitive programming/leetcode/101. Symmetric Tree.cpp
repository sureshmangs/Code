Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3


But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3


Follow up: Solve it both recursively and iteratively.








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

    bool isSymmetricUtil(TreeNode *root1, TreeNode *root2){
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL || root2==NULL) return false;

        return (root1->val==root2->val && isSymmetricUtil(root1->left, root2->right) && isSymmetricUtil(root1->right, root2->left));
    }

    bool isSymmetric(TreeNode* root) {
        TreeNode *root1=root, *root2=root;
        return isSymmetricUtil(root1, root2);
    }
};




/*
For two trees to be mirror images, the following three conditions must be true
1 - Their root node's key must be same
2 - left subtree of left tree and right subtree of right tree have to be mirror images
3 - right subtree of left tree and left subtree of right tree have to be mirror images
*/





// Iterative


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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;
        queue<TreeNode*> q;

         // Add root to queue two times so that
        // it can be checked if either one child
        // alone is NULL or not.
        q.push(root);
        q.push(root);

        while(!q.empty()){
            TreeNode *leftNode=q.front();
            q.pop();
            TreeNode *rightNode=q.front();
            q.pop();

            if(leftNode->val!=rightNode->val) return false;

            // Push left child of left subtree node
            // and right child of right subtree node in queue.
            if(leftNode->left && rightNode->right){
                q.push(leftNode->left);
                q.push(rightNode->right);
            }
            // If only one child is present alone
            // and other is NULL, then tree is not symmetric.
            else if(leftNode->left || rightNode->right){
                return false;
            }

            if(leftNode->right && rightNode->left){
                q.push(leftNode->right);
                q.push(rightNode->left);
            }
            else if(leftNode->right || rightNode->left){
                return false;
            }
        }
        return true;
    }
};


/*
Note that for a symmetric, the elements at every level are palindromic.
In other words,
1. The left child of left subtree = right child of right subtree.
2. The right child of left subtree = left child of right subtree.
If we insert the left child of left subtree first followed by right child of the right subtree in the queue,
we only need to ensure that these are equal.
Similarly, If we insert the right child of left subtree followed by left child of the right subtree in the queue,
we again need to ensure that these are equal.
*/
