Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]






class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        if(n==0) return v;
        int dp[n];
        for(int i=0;i<n;i++) dp[i]=1;

        sort(nums.begin(), nums.end());

        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    dp[i]=max(dp[i], dp[j]+1);
                }
            }
        }

        int maxIndex=0;
        for(int i=0;i<n;i++)
            maxIndex= dp[i]>dp[maxIndex] ? i: maxIndex;

        int divCnt=dp[maxIndex];
        for(int i=maxIndex;i>=0;i--){
            if(nums[maxIndex]%nums[i]==0 && divCnt==dp[i]){
                divCnt--;
                v.push_back(nums[i]);
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }
};
