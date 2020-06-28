

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.







class Solution {
public:
    int numSquares(int n) {
        if(n<=3) return n;
        int dp[n+1];

        for(int i=0;i<=n;i++){
            dp[i]=i;
            for(int j=1;j*j<=i;j++){
                int sq=j*j;
                dp[i]=min(dp[i], 1+dp[i-sq]);
            }
        }
        return dp[n];
    }
};








//Recursion
class Solution {
    int solve(int n)
    {
        if(n<=3)
            return n;

        int ans=n;
        for(int i=1;i*i<=n;++i)
           ans = min(ans,1+solve(n-i*i));

        return ans;
    }
public:
    int numSquares(int n) {
        int ans = solve(n);
        return ans;
    }
};
