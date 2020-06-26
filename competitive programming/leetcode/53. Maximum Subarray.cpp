Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.











class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        // kadanes algorithm
        int max_sum_so_far=INT_MIN, max_sum_till_here=0;
        for(int i=0;i<n;i++){
            max_sum_till_here+=nums[i];
            if(max_sum_so_far<max_sum_till_here) max_sum_so_far=max_sum_till_here;
            if(max_sum_till_here<0) max_sum_till_here=0;
        }
        return max_sum_so_far;
    }
};

