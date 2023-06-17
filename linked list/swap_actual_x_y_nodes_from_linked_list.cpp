Given a linked list and two keys in it, swap nodes for two given keys.
Nodes should be swapped by changing links.
Swapping data of nodes may be expensive in many situations when data contains many fields.
It may be assumed that all keys in linked list are distinct.

Example 1:
Input: head = [10, 15, 12, 13, 20, 14], x = 12, y = 20
Output: [10, 15, 20, 13, 12, 14]

Example 2:
Input: head = [10, 15, 12, 13, 20, 14], x = 10, y = 20
Output: [20, 15, 12, 13, 10, 14]

Example 3:
Input: head = [10, 15, 12, 13, 20, 14], x = 12, y = 13
Output: [10, 15, 13, 12, 20, 14]
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
    ListNode* swapNodes(ListNode* head, int x, int y) {
        if (!head) return head;

        if (x == y) return head;

        ListNode *prevX = NULL, *curX = head, *prevY = NULL, *curY = head;

        while (curX && curX->val != x) {
            prevX = curX;
            curX = curX->next;
        }
        while (curY && curY->val != y) {
            prevY = curY;
            curY = curY->next;
        }

        if (!curX || !curY) return head;

        if (prevX) prevX->next = curY;
        else head = curY;

        if (prevY) prevY->next = curX;
        else head = curX;

        ListNode *tmp = curY->next;
        curY->next = curX->next;
        curX->next = tmp;

        return head;
    }
};

TC -> O(n), n is the length of the linked list
SC -> O(1)
