Given a singly linked list node, swap each pair of nodes and return the new head.

Constraints
n = 100,000 where n is the number of nodes in node

Example 1
Input
node = [0, 1, 3, 4]
Output
[1, 0, 4, 3]

Example 2
Input
node = [1, 2, 3]
Output
[2, 1, 3]















/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */

// Swapping values instead of actual nodes
LLNode* solve(LLNode* head) {
    if (!head || !head->next) return head;
    LLNode *curr = head;
    while (curr && curr->next) {
        swap(curr->val, curr->next->val);
        curr = curr->next->next;
    }
    return head;
}







/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
 
// Swapping actual nodes
LLNode* solve(LLNode* head) {
    if (!head || !head->next) return head;
    LLNode *curr = head, *tmp = NULL;

    if (curr && curr->next) {
        tmp = curr->next;
        curr->next = curr->next->next;
        tmp->next = curr;
        curr->next = solve(curr->next);
    }
    return tmp;
}
