Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.








class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int ans=INT_MIN, maxVal=1, minVal=1, prevMax;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                maxVal=maxVal*nums[i];
                minVal=min(1, minVal*nums[i]);
            } else if(nums[i]==0){
                maxVal=0;
                minVal=1;
            } else if(nums[i]<0){
                prevMax=maxVal;
                maxVal=minVal*nums[i];
                minVal=prevMax*nums[i];
            }

            ans=max(ans, maxVal);

            if(maxVal<=0)
                maxVal=1;
        }
        return ans;
    }
};
