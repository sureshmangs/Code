Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]










class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        int n=nums.size();
        if(n<3) return res;

        sort(nums.begin(), nums.end());

        for(int i=0;i<n-2;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){ // not taking duplicates
                int sum=0-nums[i];
                int low=i+1, high=n-1;
                while(low<high){
                    if(nums[low]+nums[high]==sum){
                        res.push_back({nums[i], nums[low], nums[high]});
                        while(low<high && nums[low]==nums[low+1]) low++;
                        while(low<high && nums[high]==nums[high-1]) high--;
                        low++; high--;
                    } else if(nums[low]+nums[high]>sum) high--;
                    else low++;
                }

            }
        }
        return res;
    }
};




/*
while(low<high && nums[low]==nums[low+1]) low++;
while(low<high && nums[high]==nums[high-1]) high--;

here, we are doing low++ in the while loop because, for a given sum, we might get result
as A[i], A[low]=x, A[high]=y   ie: (A[i), x, y)
Now if we din't check A[low]==A[low+1] we might get duplicate results,
as if A[low+1]=x, then our solution again will be (A[i], x, y)
*/
