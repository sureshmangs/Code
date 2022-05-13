Implement a binary search tree iterator with the following methods:

next returns the next smallest element in the tree
hasnext returns whether there is a next element in the iterator
For example, given the following tree

   4
  / \
 2   7
    / \
   5   9
It should return the values in this order 2, 4, 5, 7, 9.

Example 1
Input
methods = ["constructor", "hasnext", "hasnext", "next", "hasnext", "hasnext", "hasnext", "next", "hasnext", "hasnext", "hasnext", "next", "hasnext", "next", "hasnext"]
arguments = [[[2, [1, [0, null, null], null], [3, null, null]]], [], [], [], [], [], [], [], [], [], [], [], [], [], []]`
Output
[null, true, true, 0, true, true, true, 1, true, true, true, 2, true, 3, false]












/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
class BSTIterator {
    public:
    vector <int> in;
    int index;

    void inorder(Tree *root) {
        if (!root) return;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }

    BSTIterator(Tree* root) {
        inorder(root);
        index = 0;
    }

    int next() {
        return in[index++];
    }

    bool hasnext() {
        return index < in.size();
    }
};

// TC -> next -> O(1), hasNext -> O(1)
// SC -> O(n)












/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
class BSTIterator {
    public:
    stack <Tree*> s;

    void pushAll(Tree *root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }

    BSTIterator(Tree* root) {
        pushAll(root);
    }

    int next() {
        Tree *tmp = s.top();
        s.pop();
        pushAll(tmp->right);
        return tmp->val;
    }

    bool hasnext() {
        return !s.empty();
    }
};

// TC -> next -> O(logn), hasNext -> O(1), pushAll -> O(logn)
// TC in case of a skewed tree would be O(n)
// SC -> O(logn)
