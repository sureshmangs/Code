Given the head of a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]

Constraints:
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *curr = head, *prev = NULL, *tmp = NULL;

        while (curr) {
            bool deleteCurr = false;
            while (curr->next && curr->val == curr->next->val) {
               tmp = curr->next;
                curr->next = tmp->next;
                delete(tmp);
                deleteCurr = true;
            }

            if (deleteCurr) {
                tmp = curr;
                curr = curr->next;
                delete(tmp);
                if (prev) prev->next = curr;
                else head = curr; // new updated head
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
