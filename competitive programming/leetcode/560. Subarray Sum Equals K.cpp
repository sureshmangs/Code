Given an array of integers nums and an integer k, 
return the total number of continuous subarrays whose sum equals to k.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107



// TLE -> O(N*N)

class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
        int n = nums.size(), res = 0;
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == target) res++;
            }
        }
        
        return res;
    }
};



// O(N)

class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
        int n = nums.size(), sum = 0, res = 0;
        
        unordered_map <int, int> m = {{0, 1}};
        
        for (auto &x: nums) {
            sum += x;
            res += m[sum - target];
            m[sum]++;
        }
        
        return res;
    }
};
