Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]

Constraints:
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 10^9
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;

        ListNode *curr= head;
        int len = 0;

        while (curr) {
            len++;
            curr = curr->next;
        }

        k %= len;

        if (k == 0) return head;

        int moveForward = len - k - 1;

        curr = head;
        while (moveForward--) curr = curr->next;

        ListNode *newHead = curr->next; // curr is at the previous of the new head

        curr->next = NULL; // it's the new last node

        curr = newHead;
        while (curr->next) curr = curr->next;

        curr->next = head; // curr is at the end of the original list
        head = newHead;

        return head;
    }
};

TC -> O(n), n is the length of the linked list
SC -> O(1)
********************************************************************************










# Approach 2:

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;

        ListNode *curr= head;
        int len = 1;

        while (curr->next) {
            len++;
            curr = curr->next;
        }

        k %= len;

        if (k == 0) return head;

        curr->next = head; // curr is at the last node, close the list (create a cycle)

        int moveForward = len - k - 1;

        curr = head;
        while (moveForward--) curr = curr->next;

        ListNode *newHead = curr->next; // curr is at the previous of the new head

        curr->next = NULL; // it's the new last node
        
        head = newHead;

        return head;
    }
};

TC -> O(n), n is the length of the linked list
SC -> O(1)
