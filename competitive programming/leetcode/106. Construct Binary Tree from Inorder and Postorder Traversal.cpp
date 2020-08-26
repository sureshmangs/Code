Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7









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

    unordered_map<int, int> mp;

    TreeNode* constructTree(vector<int> &postorder, vector<int> &inorder, int start, int end){

        static int pIndex=end;
        if(start>end) return NULL;

        TreeNode* tNode= new TreeNode(postorder[pIndex--]);

        if(start==end) return tNode;

        int index=mp[tNode->val];

        tNode->right=constructTree(postorder, inorder, index+1, end);
        tNode->left=constructTree(postorder, inorder, start, index-1);


        return tNode;

    }

    TreeNode* buildTree(vector<int> &inorder, vector<int>& postorder) {

        int n=inorder.size();

        // Storing data in map for O(1) searching
        for(int i=0;i<n;i++)
            mp[inorder[i]]=i;

        return constructTree(postorder, inorder, 0, n-1);  // <postorder, inorder, start, end>
    }
};

// Code gives Heap buffer overflow error
