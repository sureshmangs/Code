Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?



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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        stack<TreeNode*> s1,s2;
        s1.push(root);
        while(!s1.empty()){
            TreeNode *tmp=s1.top();
            s1.pop();
            s2.push(tmp);
            if(tmp->left) s1.push(tmp->left);
            if(tmp->right) s1.push(tmp->right);
        }
        while(!s2.empty()){
            v.push_back(s2.top()->val);
            s2.pop();
        }
        return v;
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        if(!root) return v;
        stack<TreeNode*> s;
        while(1){
            while(root){
                if(root->right) s.push(root->right);
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            if(root->right && !s.empty() && root->right==s.top() ){
                    s.pop();
                    s.push(root);
                    root=root->right;

            } else {
                v.push_back(root->val);
                root=NULL;
            }
            if(s.empty()) break;
        }
        return v;
    }
};
