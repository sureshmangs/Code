Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false

Constraints:
The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
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
    ListNode* middleNode(ListNode* head) {
            if (!head) return NULL;
            ListNode *slow = head, *fast = head;

            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }

    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode *prev = head, *curr = head, *ahead = head->next;
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

    bool isPalindrome(ListNode* head) {
        if (!head) return true;

        ListNode *mid = middleNode(head);
        ListNode *last = reverseList(mid);

        while (head && last) {
            if (head->val != last->val) return false;
            head = head->next;
            last = last->next;
        }

        return true;
    }
};

TC -> O(n), n is the length of the linked list
SC -> O(1)
