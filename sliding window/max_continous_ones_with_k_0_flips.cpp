Given a binary array nums and an integer k,
return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,(0),1,1,1,1,(0)]
Numbers inside () were flipped from 0 to 1.

Example 2:
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,(1),(1),1,1,1,(1),1,1,0,0,0,1,1,1,1]
Numbers inside () were flipped from 0 to 1.

Constraints:
1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
0 <= k <= nums.length
********************************************************************************










# Approach 1:

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0;
        int start = 0, end = 0; // start and end of the sliding window

        while (end < nums.size()) {
            if (nums[end] == 0 && k > 0) {
                k--;
            } else if (nums[end] == 0 && k == 0){
                while (nums[start] != 0) start++;
                start++; // to next element, no need to update k as it always remains 0  
            }

            res = max(res, end - start + 1);
            end++;
        }

        return res;
    }
};

TC -> O(n), n is the size of nums
SC -> O(1)
