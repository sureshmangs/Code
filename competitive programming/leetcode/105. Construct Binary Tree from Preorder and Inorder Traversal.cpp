












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


// Recursive Approach might give Heap Buffer Overflow Error

class Solution {
public:

    unordered_map<int, int> mp;

    TreeNode* constructTree(vector<int> &preorder, vector<int> &inorder, int start, int end){
        static int pIndex=0;

        if(start>end) return NULL;

        TreeNode* tNode= new TreeNode(preorder[pIndex++]);

        if(start==end) return tNode;

        int index=mp[tNode->val];

        tNode->left=constructTree(preorder, inorder, start, index-1);
        tNode->right=constructTree(preorder, inorder, index+1, end);

        return tNode;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n=inorder.size();

        // Storing data in map for O(1) searching
        for(int i=0;i<n;i++)
            mp[inorder[i]]=i;

        return constructTree(preorder, inorder, 0, n-1);  // <preorder, inorder, start, end>
    }
};




// Follow Up-----> iterative Approach
