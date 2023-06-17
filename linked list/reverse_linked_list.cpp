Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []

Constraints:
The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
********************************************************************************










# Approach 1: Iterative

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
        if (!head) return head;
        
        ListNode *prev = head, *curr = head, *ahead = head->next;
        prev->next = NULL;
        curr = ahead;
        
        while (ahead) {
            ahead = ahead->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }
        
        head = prev;
        
        return head;
    }
};

TC -> O(n), n is the length of the linked list
SC -> O(1)
********************************************************************************










# Approach 2: Recursive

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
    ListNode* helper(ListNode *head, ListNode *prev) {
        if (!head) return prev;
        
        ListNode *ahead = head->next;
        head->next = prev;
        return helper(ahead, head);
    }

    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        return helper(head, NULL); 
    }
};

TC -> O(n), n is the length of the linked list
SC -> O(n), n is the length of the linked list (recursive call stack)
