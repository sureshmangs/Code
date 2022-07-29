Given two binary trees node0 and node1, return a merge of the two trees 
where each value is equal to the sum of the values of the corresponding 
nodes of the input trees. If only one input tree has a node in a given position, 
the corresponding node in the new tree should match that input node.

Constraints

n = 100,000 where n is the number of nodes in node0
m = 100,000 where m is the number of nodes in node1

Example:

Input: 
     Tree 1            Tree 2 
	                  
       2                 3                             
      / \               / \                            
     1   4             6   1                        
    /                   \   \                      
   5                     2   7                  

Output: Merged tree:
         5
        / \
       7   5
      / \   \ 
     5   2   7
     
     
     






/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

Tree* merge(Tree *node0, Tree *node1) {
    if (!node0) return node1;
    if (!node1) return node0;

    node0->val += node1->val;
    node0->left = merge(node0->left, node1->left);
    node0->right = merge(node0->right, node1->right);
    return node0;
}

Tree* solve(Tree* node0, Tree* node1) {
    return merge(node0, node1);
}
