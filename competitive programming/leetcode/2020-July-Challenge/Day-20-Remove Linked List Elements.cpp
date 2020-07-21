Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5





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
        if(!head) return head;
        while(head->val==val && head->next!=NULL){
            ListNode* tmp=head;
            head=head->next;
            delete tmp;
        }
        if(head->val==val){
            // last node
            delete head;
            head=NULL;
            return head;
        }
        ListNode *curr=head, *prev=head;
        while(curr->next!=NULL){
            if(curr->val==val){
                prev->next=curr->next;
                delete curr;
                curr=prev->next;
            } else {
                prev=curr;
                curr=curr->next;
            }
        }
        // last node
        if(curr->val==val){
            prev->next=NULL;
            delete curr;

        }
        return head;
    }
};
