Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
Return the linked list sorted as well.

Example 1:
Input: head = [1,1,2]
Output: [1,2]

Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3]

Constraints:
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
********************************************************************************










# Approach 1: Iterative
	
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

        ListNode *curr = head;

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                ListNode *tmp = curr->next;
                curr->next = tmp->next;
                delete(tmp);
            } else curr = curr->next;
        }

        return head;
    }
};

TC -> O(n), n is the length of the linked list
SC -> O(1)
********************************************************************************










# Approach 2: Recursive

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

        if (head->val == head->next->val) {
            ListNode *tmp = head->next;
            head->next = tmp->next;
            delete(tmp);
            deleteDuplicates(head);
        } else deleteDuplicates(head->next);

        return head;
    }
};

TC -> O(n), n is the length of the linked list
SC -> O(n), n is the length of the linked list (recursive call stack)
