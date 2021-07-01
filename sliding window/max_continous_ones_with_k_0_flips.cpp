Given a binary array nums and an integer k, 
return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length













class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, end = 0, res = 0;
        
        while (end < nums.size()) {
            if (nums[end] == 0 && k > 0) {
                k--;
            } else if (nums[end] == 0 && k == 0){
                while (nums[start] != 0) start++;
                start++; // to next element
            }
            
            res = max(res, end - start + 1);
            
            end++;
        }
        return res;
    }
};










// can be done without ones variable

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, end = 0, res = 0, ones = 0;
        
        while (end < nums.size()) {
            if (nums[end] == 1) ones++;
            else if (nums[end] == 0 && k > 0) {
                ones++;
                k--;
            } else {
                while (nums[start] != 0) start++;
                start++; // to next element
            }
            res = max(res, end - start + 1);
            end++;
        }
        return res;
    }
};
