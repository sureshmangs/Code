Given a singly linked list head whose values are integers, 
determine whether the linked list forms a palindrome.

Constraints

n = 100,000 where n is the length of node

Example 1:
Input
node = [5, 3, 5]
Output
true
Explanation
5 -> 3 -> 5 is a palindrome.

Example 2:
Input
node = [12, 8, 12]
Output
true
Explanation
The values of the linked list are the same forwards and backwards.











/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */

LLNode* getMiddle(LLNode *head) {
    LLNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

LLNode* reverseLinkedList(LLNode *head) {
    if (!head) return head;
    LLNode *prev = head, *curr = head, *ahead = head->next;
    prev->next = NULL;
    curr = ahead;
    while (ahead) {
        ahead = ahead->next;
        curr->next = prev;
        prev = curr;
        curr = ahead;
    }
    head = prev;
    return head;
}

bool solve(LLNode* head) {
    if (!head) return true;
    LLNode *mid = getMiddle(head);
    LLNode *last = reverseLinkedList(mid);
    

    while (head && last) {
        if (head->val != last->val) return false;
        head = head->next;
        last = last->next;
    }

    return true;
}
