Given the head of a linked list, return the list after sorting it in ascending order.

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
The number of nodes in the list is in the range [0, 5 * 10^4].
-10^5 <= Node.val <= 10^5
********************************************************************************










# Approach 1: Top Down Merge Sort

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
    ListNode* middleNode(ListNode* head) {
        if (!head) return NULL;
        ListNode *slow = head, *fast = head, *prev = NULL;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        return slow;
    }

    ListNode *merge(ListNode *list1, ListNode *list2) {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1) tail->next = list1;
        else tail->next = list2;

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *mid = middleNode(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        return merge(left, right);
    }
};

TC -> O(n * logn), n is the length of the linked list
SC -> O(logn), n is the length of the linked list (recursive call stack)

Extra:
	The algorithm can be split into 2 phases, Split and Merge.
	Split: The recursion tree expands in thr form of a complete binary tree, splitting the
	list into two halves recursively. The number of levels in a complete binary tree is given
	by log(2)n.
	Merge: At each level, we merge n nodes which takes O(n) time.
	TC becomes n * logn
	SC: O(logn) as we need logn recursive call stacks, which is equal to the height of the
	binary tree, note that the SC is not equal to the sum of all nodes (i.e 1 + 2 + 4 + 8 + ...),
	it's equal to the height of the tree as only that amount of call stacks are required.
