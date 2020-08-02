You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step


Constraints:

1 <= n <= 45
   Hide Hint #1
To reach nth step, what could have been your previous steps? (Think about the step sizes)












// recursive (TLE)

class Solution {
public:

    int rec(int n){
        if(n<=1) return 1;    // Only one way to reach
        return rec(n-1) + rec(n-2);
    }

    int climbStairs(int n) {
        return rec(n);
    }
};







// Memoization

class Solution {
public:

    int rec(int n, int dp[]){
       if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        dp[n-1]=rec(n-1, dp);
        dp[n-2]=rec(n-2, dp);
        dp[n]=dp[n-1]+dp[n-2];
        return dp[n];
    }

    int climbStairs(int n) {
        int dp[n+1];
        fill(dp, dp+n+1, -1);
        return rec(n, dp);
    }
};
