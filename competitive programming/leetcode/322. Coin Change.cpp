You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.




class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int n=coins.size();
        int dp[n+1][amt+1];

        for(int i=0;i<n+1;i++) dp[i][0]=0;
        for(int j=1;j<amt+1;j++) dp[0][j]=INT_MAX-1;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<amt+1;j++){
                if(coins[i-1]<=j)
                    dp[i][j]=min(dp[i][j-coins[i-1]]+1, dp[i-1][j]);
                else dp[i][j]=dp[i-1][j];
            }
        }

        return dp[n][amt]==INT_MAX-1 ? -1: dp[n][amt];
    }
};
