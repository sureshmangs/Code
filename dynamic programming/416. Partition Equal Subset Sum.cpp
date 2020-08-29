Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.


Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].


Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.








class Solution {
public:

    int knapsack(vector<int> &nums, int x){
        int n=nums.size();
        bool dp[n+1][x+1];

        for(int i=0;i<n+1;i++) dp[i][0]=true;
        for(int j=1;j<x+1;j++) dp[0][j]=false;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<x+1;j++){
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][x];
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int &num: nums)
            sum+=num;
        if(sum%2!=0) return false;
        return knapsack(nums, sum/2);
    }
};
