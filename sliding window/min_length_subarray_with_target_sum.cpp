Given an array of positive integers nums and a positive integer target,
return the minimal length of a  subarray whose sum is greater than or equal to target.
If there is no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 
Constraints:
1 <= target <= 10^9
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^4
********************************************************************************










# Approach 1:

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX, sum = 0;
        int start = 0, end = 0; // start and end of the sliding window
        while (end < nums.size()) {
            sum += nums[end];

            while (sum >= target) { // windows complete
                res = min(res, end - start + 1);
                sum -= nums[start];
                start++;    // decrement window size
            }
            end++;  // increment window size
        }

        return res == INT_MAX ? 0 : res;
    }
};

TC -> O(n), n is the size of nums
SC -> O(1)
