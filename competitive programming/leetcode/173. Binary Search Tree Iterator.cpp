Implement an iterator over a binary search tree (BST).
Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.



Example:



BSTIterator iterator = new BSTIterator(root);
iterator.next();    // return 3
iterator.next();    // return 7
iterator.hasNext(); // return true
iterator.next();    // return 9
iterator.hasNext(); // return true
iterator.next();    // return 15
iterator.hasNext(); // return true
iterator.next();    // return 20
iterator.hasNext(); // return false


Note:

next() and hasNext() should run in average O(1) time and uses O(h) memory,
where h is the height of the tree.
You may assume that next() call will always be valid, that is,
there will be at least a next smallest number in the BST when next() is called.







// Approach 1: Flatten the list
 // Do inorder traversal and store the result in an array
 // The array will be sorted
 // Time complexity : O(N)
 // Space complexity : O(N)

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
class BSTIterator {
public:
    TreeNode *root = NULL;
    vector <int> in;
    int cur;
    
    void inorder(TreeNode *root, vector <int> &in) {
        if (!root) return;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
    
    BSTIterator(TreeNode* Root) {
        root = Root;
        inorder(root, in);
        cur = 0;
    }
    
    int next() {
       return in[cur++];
    }
    
    bool hasNext() {
        return cur < in.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */










 // Approach 2: Controlled Recursion
 // Implemented above
 // Time complexity : O(N)
 // Space complexity: The space complexity is O(h)





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
class BSTIterator {
public:

    stack<TreeNode*> s;

    void leftmostInorder(TreeNode* root){
        while(root){
            s.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        leftmostInorder(root);
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *topmostNode = s.top();
        s.pop();
        if(topmostNode->right != NULL) leftmostInorder(topmostNode->right);

        return topmostNode->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return s.size() > 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */



 


