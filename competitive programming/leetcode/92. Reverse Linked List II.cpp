Given the head of a singly linked list and two integers left and right where left <= right, 
reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

Follow up: Could you do it in one pass?





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
    
    ListNode* reverse(ListNode *start, ListNode *end) {
        if (!start) return start;
        
        ListNode *prev = start, *cur = start, *ahead = start->next;
        prev->next= NULL;
        cur = ahead;
        while (ahead!= end) {
            ahead = ahead->next;
            cur->next = prev;
            prev = cur;
            cur = ahead;
        }
        
        return prev;
    }
    
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) return head;
        if (left == right) return head;
        
        ListNode *leftPtr = head, *rightPtr = head, *prevLeft = NULL, *nextRight = NULL;
        
        left--;
        right--;
        
        while (left--) {
            prevLeft = leftPtr;
            leftPtr = leftPtr->next;
        }
        while (right--) {
            rightPtr = rightPtr->next;
        }
        
        nextRight = rightPtr->next;
        
        rightPtr = reverse(leftPtr, rightPtr->next);
        
        if (prevLeft == NULL) {
            head = rightPtr;  // head has changed
        } else prevLeft->next = rightPtr;
        
        leftPtr->next = nextRight;
        
        return head;
    }
};
