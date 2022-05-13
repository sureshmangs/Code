Given a complete binary tree root, return the number of nodes in the tree.

This should be done in O((log n)^2)
 ).

Constraints

n = 100,000 where n is the number of nodes in root
Example 1
Input
root =         1
             /   \
            2     3
           /  \
          4    5
        

Output
5
Example 2
Input
root =          1
             /    \
            2       3
           /  \   /   \
          4    5  6    7

Output
7















/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

int getLeftHeight (Tree *root) {
    int height = 0;
    while (root) {
        height++;
        root = root->left;
    }
    return height;
}

int getRightHeight (Tree *root) {
    int height = 0;
    while (root) {
        height++;
        root = root->right;
    }
    return height;
}

int totalNodes(Tree *root) {
    if (!root) return 0;
    int leftHeight = getLeftHeight(root);
    int rightHeight = getRightHeight(root);

    if (leftHeight == rightHeight) return pow(2, leftHeight) - 1;
    return 1 + totalNodes(root->left) + totalNodes(root->right);
}

int solve(Tree* root) {
    return totalNodes(root);
}






// A full binary tree has it's left and right substree height equal
// with number of nodes equal to 2^h - 1
