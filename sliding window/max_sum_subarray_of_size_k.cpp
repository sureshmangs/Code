Given an array of integers nums of size n and a number k.
Return the maximum sum of a subarray of size k.

Example 1:
Input:  [4 3 9 5 1 2], k = 3
Output: 17
Explanation: The subarray of size 3 with maximum sum 17 is [3 9 5].

Example 2:
Input:  [1 2 3], k = 2
Output: 5
Explanation: The subarray of size 2 with maximum sum is [2 3].

Constraints:
1<=n<=10^5
1<=k<=n
********************************************************************************
 









# Approach 1:

class Solution {
public:
    int maximumSumSubarray(vector<int>& nums, int k) {
    	int sum = 0, res = INT_MIN;
        int start = 0, end = 0; // start and end of the sliding window

        while (end < nums.size()) {
            sum += nums[end];
            if (end - start + 1 == k) { // windows complete
                res = max(res, sum);
                sum -= nums[start];
                start++;    // slide the window
            }
            end++;  // increment window size
        }

        return res;
    }
};

TC -> O(n), n is the size of nums
SC -> O(1)
