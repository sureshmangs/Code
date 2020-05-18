Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        struct ListNode *prev=head, *cur=head, *ahead=head->next;
        prev->next=NULL;
        cur=ahead;
        while(ahead!=NULL){
            ahead=ahead->next;
            cur->next=prev;
            prev=cur;
            cur=ahead;
        }
        head=prev;
        return head;
    }
};
