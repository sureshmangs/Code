You are given an array of integers nums and an integer target.
Return the number of non-empty subsequences of nums such that the sum of
the minimum and maximum element on it is less or equal to target.
Since the answer may be too large, return it modulo 109 + 7.

Example 1:
Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)

Example 2:
Input: nums = [3,3,6,8], target = 10
Output: 6
Explanation: There are 6 subsequences that satisfy the condition.
(nums can have repeated numbers).
[3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]

Example 3:
Input: nums = [2,3,3,4,6,7], target = 12
Output: 61
Explanation: There are 63 non-empty subsequences,
two of them do not satisfy the condition ([6,7], [7]).
Number of valid subsequences (63 - 2 = 61).

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6
1 <= target <= 10^6
********************************************************************************










# Approach 1:

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int res = 0, mod = 1e9 + 7;

        sort(nums.begin(), nums.end());

        vector<int> power(nums.size());
        power[0] = 1;

        for (int i = 1; i < nums.size(); i++) power[i] = (power[i - 1] * 2) % mod;

        int start = 0, end = nums.size() - 1;

        while (start <= end) {
            if (nums[start] + nums[end] <= target) {
                res = (res + power[end - start]) % mod;
                start++;
            } else end--;
        }

        return res;
    }
};

TC -> O(n * logn), n is the size of the nums
SC -> O(n), n is the size of nums

Extra:
	After sorting the nums, nums[start] is the minimum element and nums[end] is the
	maximum element, we always start the subsequence from the minimum element, i.e.
	the minimum element is always included in the subsequence, and now apart from the
	minimum element we have (end - start) number of elements which can and cannot be
	the part of the subsequence.
	So, the total number of subsequences starting with nums[start] are equal
	to 2 ^ (end - start).
