Given the head of a linked list, return the node where the cycle begins.
If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again
by continuously following the next pointer.
Internally, pos is used to denote the index of the node that tail's next pointer is connected
to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Example 3:
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

Constraints:
The number of the nodes in the list is in the range [0, 104].
-10^5 <= Node.val <= 10^5
pos is -1 or a valid index in the linked-list.
********************************************************************************










# Approach 1:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return head;

        ListNode *slow = head, *fast = head;
        bool cycle = false;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cycle = true;
                break;
            }
        }
        
        if (cycle) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    
        return NULL;
    }
};

TC -> O(n), n is the length of the linked list
SC -> O(1)

Extra:

	1---2---3----4---5---6---7
					 |		 |
					 |		 |
					10---9---8

	List starts at 1, cycle starts at node 5, slow and fast meet at node 7.
	A: distance b/w node 1 and 5 (start of list and start of cycle).
	B: distance b/w 5 and 7 (start of cycle and where both slow, fast meet).
	C: distance b/w 5 and 10 (length of the cycle)
	x: number of cycles covered by fast
	y: number of cycles covered by slow
	
	distance covered by fast = twice of distance covered by slow
	
	A + xC + B = 2 * (A + yC + B)
	A + xC + B = 2A + 2yC + 2B
	(x - 2y)C = A + B
	or A + B = (x - 2y)C
	
	so A + B is a multiple of cycle C, so to complete a cycle A + B distance has to be covered
	so the distance b/w 5 and 7 is B, so the remaining distance b/w 7 to 5 covered in the cycle would be A.
