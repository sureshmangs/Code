Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
********************************************************************************










# Approach 1:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;

        ListNode *slow = head, *fast = head, *prev = NULL;

        // finding nth node from beginining
        while (--n) {
            fast = fast->next;
        }

        // finding nth node from end
        while (fast->next) {
            prev = slow; // update prev only for slow
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *tmp = slow;   // nth node from end
        slow = slow->next;
        if (prev) prev->next = slow;
        else head = slow;
        delete(tmp);

        return head;
    }
};

TC -> O(n), n is the length of the linked list
SC -> O(1)
