Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.



Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]
Example 3:

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]
Example 4:

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]
Example 5:


Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]


Constraints:

Each tree has at most 5000 nodes.
Each node's value is between [-10^5, 10^5].
   Hide Hint #1
Traverse the first tree in list1 and the second tree in list2.
   Hide Hint #2
Merge the two trees in one list and sort it.







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

    void inorder(TreeNode* root,vector<int>& v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans, a,b;
        inorder(root1,a);
        inorder(root2,b);
        int i=0,j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]<b[j]) ans.push_back(a[i++]);
            else ans.push_back(b[j++]);
        }
        while(i<a.size()) ans.push_back(a[i++]);
        while(j<b.size()) ans.push_back(b[j++]);
        return ans;
    }
};
