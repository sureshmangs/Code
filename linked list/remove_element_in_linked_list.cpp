Given the head of a linked list and an integer val,
remove all the nodes of the linked list that has Node.val == val, and return the new head.

Example 1:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:
Input: head = [], val = 1
Output: []

Example 3:
Input: head = [7,7,7,7], val = 7
Output: []

Constraints:
The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;

        ListNode *curr = head, *prev = NULL, *tmp = NULL;

        while (curr) {
            if (curr->val == val) {
                tmp = curr;
                curr = curr->next;
                if (prev) prev->next = curr;
                else head = curr;
                delete(tmp);
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};

TC -> O(n), n is the length of the linked list
SC -> O(1)
