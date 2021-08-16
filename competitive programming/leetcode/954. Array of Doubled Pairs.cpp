Given an array of integers arr of even length, 
return true if and only if it is possible to reorder 
it such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2.

 

Example 1:

Input: arr = [3,1,3,6]
Output: false
Example 2:

Input: arr = [2,1,2,6]
Output: false
Example 3:

Input: arr = [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
Example 4:

Input: arr = [1,2,4,16,8,4]
Output: false
 

Constraints:

0 <= arr.length <= 3 * 104
arr.length is even.
-105 <= arr[i] <= 105





/*
We need to reorder the array so that we have n/2 pairs of (x, x * 2).
So all we need to do is keep track which numbers we used already for a different pair.
Why do we have to sort?
For example, if we have in the array [2, 4, 8, 1].
We will get to the 2, find it's double - 4, and then the 1 and 8 will stay without a pair!
If we sort, then we go in an ascending order, so it won't happe
*/






class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map <int, int> freq;
        
        for (auto &x: arr) freq[x]++;
        
        sort(arr.begin(), arr.end());
        
        for (auto &x: arr) {
            if (freq[x] && freq[2 * x]) {
                freq[x]--;
                freq[2 * x]--;
            }
        } 
        
        for (auto &[a, b]: freq) {
            if (b) return false;
        }
        
        return true;
    }
};
