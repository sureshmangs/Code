Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *start, *last;
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val <= l2->val){
            start=l1;
            l1=l1->next;
        }
        else {
            start=l2;
            l2=l2->next;
        }
        last=start;
        while(l1 && l2){
            if(l1->val <= l2->val){
                last->next=l1;
                last=last->next;
                l1=l1->next;

            } else {
                last->next=l2;
                last=last->next;
                l2=l2->next;
            }
        }
        if(l1){
            last->next=l1;
        }
        if(l2){
            last->next=l2;
        }
        return start;
    }
};
