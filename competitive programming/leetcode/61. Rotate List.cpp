Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL










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
        if(!head) return head;
        ListNode* curr=head;
        int len=0;
        while(curr!=NULL){
            len++;
            curr=curr->next;
        }
        k=k%len;
        if(k==0) return head;
        int ahead=len-k;
        ahead--;
        curr=head;
        while(ahead--){
            curr=curr->next;
        }
        ListNode* newHead=curr->next;
        curr->next=NULL;
        ListNode* newLast=newHead;
        while(newLast->next!=NULL){
            newLast=newLast->next;
        }
        newLast->next=head;
        head=newHead;
        return head;

    }
};
