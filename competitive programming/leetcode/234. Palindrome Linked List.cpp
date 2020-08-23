Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?











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
    };

    ListNode* reverseList(ListNode* head){
    if(head==NULL) return head;
    ListNode *cur=head, *prev=head, *ahead=head->next;
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

    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode* mid=getMiddle(head);
        ListNode* last=reverseList(mid);  // start of reverses list

        while(head!=mid){
            if(head->val!=last->val) return false;
                head=head->next;
                last=last->next;
        }
        return true;

    }
};

// After finding the result, we can again reverse the reversed list and join it back to the original list
