You are given the head of a linked list.
Remove every node which has a node with a strictly greater value anywhere to the right side of it.
Return the head of the modified linked list.

Example 1:
Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.

Example 2:
Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.

Constraints:

The number of the nodes in the given list is in the range [1, 10^5].
1 <= Node.val <= 10^5
********************************************************************************










# Approach 1: Monotonic stack

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
    ListNode* removeNodes(ListNode* head) {
        if (!head) return head;

        stack<ListNode*> s;

        ListNode *curr = head, *tmp = NULL;

        while (curr) {
            while (!s.empty() && s.top()->val < curr->val) {
                tmp = s.top();
                s.pop();
                delete(tmp);
            }

            if (s.empty()) head = curr; // new updated head
            else s.top()->next = curr;
            
            s.push(curr);
            curr = curr->next;
        }
        
        return head;
    }
};

TC -> O(n), n is the length of the linked list
SC -> O(n), n is the length of the linked list
********************************************************************************










# Approach 2: Recursion


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
    ListNode* removeNodes(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *highestValuedRightNode = removeNodes(head->next);

        if (highestValuedRightNode->val > head->val) {
            ListNode *tmp = head;
            delete(tmp);
            return highestValuedRightNode;
        }

        head->next = highestValuedRightNode;

        return head;
    }
};

TC -> O(n), n is the length of the linked list
SC -> O(n), n is the length of the linked list (recursive call stack)
