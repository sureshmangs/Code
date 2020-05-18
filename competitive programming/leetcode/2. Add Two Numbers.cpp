You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry=false;
        struct ListNode *l3=NULL, *l3Tail=NULL;
        while(l1!=NULL && l2!=NULL){
            int dSum=l1->val+l2->val+int(carry);
            if(dSum>=10){
                dSum%=10;
                carry=true;
            } else carry=false;
            struct ListNode *tmp= new ListNode(dSum);
            if(l3==NULL){
                l3=tmp;
                l3Tail=tmp;
            } else {
                l3Tail->next=tmp;
                l3Tail=l3Tail->next;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
                int dSum=l1->val+int(carry);
                if(dSum>=10){
                dSum%=10;
                carry=true;
                } else carry=false;
                struct ListNode *tmp= new ListNode(dSum);
                if(l3==NULL){
                    l3=tmp;
                    l3Tail=tmp;
                } else {
                    l3Tail->next=tmp;
                    l3Tail=l3Tail->next;
                }
                l1=l1->next;
        }
        while(l2!=NULL){
                int dSum=l2->val+int(carry);
                if(dSum>=10){
                dSum%=10;
                carry=true;
                } else carry=false;
                struct ListNode *tmp= new ListNode(dSum);
                if(l3==NULL){
                    l3=tmp;
                    l3Tail=tmp;
                } else {
                    l3Tail->next=tmp;
                    l3Tail=l3Tail->next;
                }
                l2=l2->next;
        }
        if(carry){
            struct ListNode *tmp= new ListNode(int(carry));
            l3Tail->next=tmp;
        }
        return l3;
    }
};
