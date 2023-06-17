Given the head of a unsorted linked list, delete all duplicates such that each element appears only once.
Return the head of the linked list as well.

Example 1:
Input: head = [5, 2, 2, 4]
Output: [5, 2, 4]

Example 2:
Input: head = [1,1,1,1,1]
Output: [1]

Constraints:
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
********************************************************************************










# Approach 1:

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        
        unordered_set<int> set;
        ListNode *curr = head, *prev = NULL, *tmp = NULL;

        while (curr) {
            if (set.find(curr->val) != set.end()){
                tmp = curr;
                curr = curr->next;
                delete(tmp);
                prev->next = curr;
            } else {
                set.insert(curr->val);
                prev = curr;
                curr = curr->next;
            }
        }
        
        return head;
    }
};

TC -> O(n), n is the length of the linked list
SC -> O(k), k is the maximum unique characters in the linked list
********************************************************************************










# Approach 2:

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;

        ListNode *curi = head;

        while (curi) {
            ListNode *curj = curi->next, *prev = curi, *tmp = NULL;
            while (curj) {
                if (curi->val == curj->val) {
                    tmp = curj;
                    curj = curj->next;
                    delete(tmp);
                    prev->next = curj;
                } else {
                    prev = curj;
                    curj = curj->next;
                }
            }
            curi = curi->next;
        }

        return head;
    }
};

TC -> O(n^2), n is the length of the linked list
SC -> O(1)
