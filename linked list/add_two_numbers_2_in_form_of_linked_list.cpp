You are given two non-empty linked lists representing two non-negative integers.
The most significant digit comes first and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Example 2:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

Example 3:
Input: l1 = [0], l2 = [0]
Output: [0]

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
********************************************************************************










# Approach 1: Reversing linked list

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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode *head = NULL, *tail = NULL;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
                
            }
            
            sum += carry;

            carry = sum / 10;
            sum = sum % 10;

            ListNode *node = new ListNode(sum);

            if (head) tail->next = node;
            else head = node; // first time initialization

            tail = node;
        }

        head = reverseList(head);

        return head;
    }
};

TC -> O(n + m), n, m is the length of the linked list l1, l2
SC -> O(1)
********************************************************************************










# Approach 2: Without reversing linked list

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
        if (!l1) return l2;
        if (!l2) return l1;

        stack <int> s1, s2;

        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode *head = NULL, *tail = NULL;
        int carry = 0;

        while (!s1.empty() || !s2.empty() || carry) {
            int sum = 0;
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop(); 
            }

            sum += carry;

            carry = sum / 10;
            sum = sum % 10;

            head = new ListNode(sum);

            head->next = tail;
            tail = head;
        }

        return head;
    }
};

TC -> O(n + m), n, m is the length of the linked list l1, l2
SC -> O(1)
