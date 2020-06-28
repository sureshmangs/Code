Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]










class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        int n=nums.size();
        if(n<4) return res;

        sort(nums.begin(), nums.end());

        for(int i=0;i<n-3;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){  // check duplicates
                int k1=target-nums[i];
                for(int j=i+1;j<n-2;j++){
                    if(j==i+1 || (j>i+1 && nums[j]!=nums[j-1])){  // check duplicates
                        int k2=k1-nums[j];
                        int low=j+1, high=n-1;
                        while(low<high){
                            if(nums[low]+nums[high]==k2){
                                res.push_back({nums[i], nums[j], nums[low], nums[high]});
                                while(low<high && nums[low]==nums[low+1]) low++;
                                while(low<high && nums[high]==nums[high-1]) high--;
                                low++;
                                high--;
                            }
                            else if(nums[low]+nums[high]>k2) high--;
                            else low++;
                        }
                }

            }
        }
    }
        return res;
    }
};
