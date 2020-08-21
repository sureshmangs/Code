Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

















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

    ListNode* getMiddle(ListNode* head){
        ListNode *slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head){
        if(!head) return head;
        ListNode *prev=head, *curr=head, *ahead=head->next;
        prev->next=NULL;
        curr=ahead;
        while(ahead!=NULL){
            ahead=ahead->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
        }
        head=prev;
        return head;
    }

    void reorderList(ListNode* head) {
        if(!head) return;
        if(head->next==NULL) return; // only one element

        // find middle of the list
        ListNode *mid=getMiddle(head);

        // Making middles previous equal to NULL
        ListNode *curr=head;
        while(curr->next!=mid){
            curr=curr->next;
        }
        curr->next=NULL;

        // reverse the list after mid
        ListNode *revHead=reverseList(mid);

        // connecting both the nodes in zigzag manner
        ListNode *h1=head, *h2=revHead, *ahead=NULL;
        while(h1!=NULL && h2!=NULL){
            ahead=h1->next;
            h1->next=h2;
            h1=h2;
            h2=ahead;
        }
    }
};
