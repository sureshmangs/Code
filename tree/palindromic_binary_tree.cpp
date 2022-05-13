Given a binary tree root where each node contains a digit from 0-9, 
return whether its in-order traversal is a palindrome.

Bonus: solve in  O(h) space where h is height of the tree.

Constraints

n = 100,000 where n is the number of nodes in root
Example 1
Input
Visualize
root =
          5
        /   \
       1     5
            /  \
           9    1	

Output
true
Explanation
The in-order traversal is [1, 5, 9, 5, 1] which is a palindrome

Example 2
Input
Visualize
root =
          1
        /   \
       2     3
      

Output
false







/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool solve(Tree* root) {
    Tree *root1 = root, *root2 = root;
    stack <Tree *> s1, s2;

    while (root1 || root2 || !s1.empty() || !s2.empty()) {
        while (root1) {
            s1.push(root1); root1=root1->left;
        }
        while (root2) {
            s2.push(root2); root2 = root2->right;
        }

        root1 = s1.top();
        s1.pop();
        root2 = s2.top();
        s2.pop();

        if (root1 == root2) return true; // odd length tree
        if (root1->val != root2->val) return false;

        root1 = root1->right;
        root2 = root2->left;
    }

    return true;
}




/*
The problem goes quite simply in O(h) space by using two stacks, 
one is to keep track of the left children and the 
other for the right children.

For odd-length Trees, we can make an improvisation when 
the addresses of the middle element become same
*/
