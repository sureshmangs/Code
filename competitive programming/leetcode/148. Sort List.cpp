Given the head of a linked list, return the list after sorting it in ascending order.

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?



Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []


Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105








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

    ListNode* merge(ListNode* a, ListNode* b){
        if(!a) return b;
        if(!b) return a;

        ListNode *result=NULL;

        if(a->val <= b->val){
            result=a;
            result->next=merge(a->next, b);
        } else {
            result=b;
            result->next=merge(a, b->next);
        }

        return result;
    }

    ListNode* getMiddle(ListNode* head){
        ListNode *slow=head, *fast=head, *prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(prev) prev->next=NULL;
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* mid=getMiddle(head);
        ListNode* left=sortList(head);
        ListNode* right=sortList(mid);

        return merge(left, right);
    }
};
