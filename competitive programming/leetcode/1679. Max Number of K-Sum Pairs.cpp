You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array 
whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

 

Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
Example 2:

Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109








// TC -> O(n)
// SC -> O(n)

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int res = 0;
        unordered_map <int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            int target = k - nums[i];
            if (mp[target] > 0) {
                res++;
                mp[target]--;
            } else  mp[nums[i]]++;
           
        }
        return res;
    }
};








// TC -> O(nlogn), because of sorting
// SC -> O(1)

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int res = 0, start = 0, end = nums.size() - 1;
        
        sort(nums.begin(), nums.end());
        
        while (start < end) {
            int target = nums[start] +nums[end];
            if (target == k) {
                res++;
                start++;
                end--;
            } else if (target < k) {
                start++;
            } else end--;
        }
        
        return res;
    }
};
