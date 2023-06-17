Given the head of a singly linked list and two integers left and right where left <= right,
reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]

Constraints:
The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
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
    ListNode* reverseList(ListNode* start) {
        if (!start) return start;
        ListNode *prev = start, *curr = start, *ahead = start->next;
        prev->next = NULL;
        curr = ahead;
        while (ahead) {
            ahead = ahead->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }
        return prev; // head of the reversed list
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head) return head;
        if (left == right) return head; // no need to do anything

        ListNode *start = head, *end = head, *prevStart = NULL, *nextEnd = NULL;

        left--;
        right--;

        while (left--) {
            prevStart = start;
            start = start->next;
        }

        while (right--) {
            end = end->next;
        }
        nextEnd = end->next;

        end->next = NULL;

        ListNode *reverseListhead = reverseList(start);

        if (prevStart)
            prevStart->next = reverseListhead;
        else head = reverseListhead;
        
        start->next = nextEnd; // list is reversed, so start will be at the end now

        return head;
    }
};

TC -> O(n), n is the length of the linked list
SC -> O(1)
