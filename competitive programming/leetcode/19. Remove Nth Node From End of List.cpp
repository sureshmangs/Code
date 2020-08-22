Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?







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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        // remove kth node from back
        if(!head) return head;
        ListNode *slow=head, *fast=head;
        k+=1;
        while(k--){
            if(fast->next==NULL && k!=0){
                // we have reached end of list, meaning we have to delete first element of list
                ListNode *nodeToDelete=head;
                head=head->next;
                delete nodeToDelete;
                return head;
            }
            fast=fast->next;
        }
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode *nodeToDelete=slow->next;
        slow->next=slow->next->next;
        delete nodeToDelete;
        return head;
    }
};


// We can delete the (N - K + 1)th node from beginning
