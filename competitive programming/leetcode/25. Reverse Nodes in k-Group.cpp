Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.









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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;
        ListNode* ahead = NULL;
        ListNode* prev = NULL;
        int count = 0;

        int len=0;
        ListNode* curr=head;
        while(curr!=NULL){
            len++;
            curr=curr->next;
        }

        // reverse first k nodes of the linked list
        while (current != NULL && count < k)
        {
            ahead = current->next;
            current->next = prev;
            prev = current;
            current = ahead;
            count++;
        }

        // ahead is now a pointer to (k+1)th node
        // Recursively call for the list starting from current.
        // And make rest of the list as next of first node */
        if (ahead != NULL && count+k <= len)
            head->next = reverseKGroup(ahead, k);
        else head->next=ahead;

        // prev is new head of the input list
        return prev;
    }
};
