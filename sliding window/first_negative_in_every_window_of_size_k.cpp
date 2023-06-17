Given an array nums and a positive integer k,
find the first negative integer for each window(contiguous subarray) of size k.
If a window does not contain a negative integer, then print 0 for that window.

Example 1:
Input: nums[] = [-8, 2, 3, -6, 10] k = 2
Output :  [-8, 0, -6, -6]
Explanation:
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
 
Example 2:
Input: nums[] = [12, -1, -7, 8, -15, 30, 16, 28] k = 3
Output: [-1, -1, -7, -15, -15, 0] 

Constraints:
1 <= n <= 10^5
1 <= nums[i] <= 10^5
1 <= k <= n
********************************************************************************










# Approach 1:

class Solution {
public:
    vector<int> firstNegativeInteger(vector<int>& nums, int k) {
        vector<int> res;
        queue <int> q;
        
        int start = 0, end = 0; // start and end of the sliding window

        while (end < nums.size()) {
            if (nums[end] < 0) q.push(nums[end]);
            
            if (end - start + 1 == k) { // windows complete
                if (q.empty()) res.push_back(0);
                else {
                    res.push_back(q.front());
                    if (q.front() == nums[start]) q.pop();
                }
                start++;	// slide the window
            }
            end++;  // increment window size
        }
        return res;
    }
};

TC -> O(n), n is the size of nums
SC -> O(k), k is the window size, we store maximum k elements in the queue
