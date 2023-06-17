Given two integer arrays pushed and popped each with distinct values,
return true if this could have been the result of a sequence of push and
pop operations on an initially empty stack, or false otherwise.

Example 1:
Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

Example 2:
Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
 
Constraints:
1 <= pushed.length <= 1000
0 <= pushed[i] <= 1000
All the elements of pushed are unique.
popped.length == pushed.length
popped is a permutation of pushed.
********************************************************************************










# Approach 1:

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0, n = pushed.size();
        stack <int> s;

        while (i < n && j < n) {
            s.push(pushed[i]);
            while (!s.empty() && s.top() == popped[j]) {
                s.pop();
                j++;
            }
            i++;
        }
        
        return j == n;
    }
};

TC -> O(n), n is the size of the pushed
SC -> O(n), n is the size of the pushed
