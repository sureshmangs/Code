Given a linked list, swap every two adjacent nodes and return its head.
You must solve the problem without modifying the values in the list's nodes
(i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]

Constraints:
The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
********************************************************************************










# Approach 1: Swap the values inside the node (violates the problem statement)

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *curr = head;

        while (curr && curr->next) {
            swap(curr->val, curr->next->val);
            curr = curr->next->next;
        }

        return head;
    }
};

TC -> O(n), n is the length of the linked list
SC -> O(1)
********************************************************************************










# Approach 2: Iterative swap actual nodes

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *prev = NULL, *curr = head, *ahead = head->next;

        head = head->next; // new updated head
        
        while (curr && ahead) {
            if (prev) prev->next = ahead;
            curr->next = ahead->next;
            ahead->next = curr;
            prev = curr;
            curr = curr->next;
            if (curr) ahead = curr->next;
        }

        return head;
    }
};

TC -> O(n), n is the length of the linked list
SC -> O(1)
********************************************************************************










# Approach 3: Recursive swap actual nodes

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *curr = head, *tmp = NULL;

        if (curr && curr->next) {
            tmp = curr->next;
            curr->next = curr->next->next;
            tmp->next = curr;
            curr->next = swapPairs(curr->next);
        }

        return tmp; // don't update head here
    }
};

TC -> O(n), n is the length of the linked list
SC -> O(n), n is the length of the linked list (recursive call stack)
