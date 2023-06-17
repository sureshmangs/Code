You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps.
In how many distinct ways can you climb to the top?

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
********************************************************************************










# Approach 1: Recursion (TLE)

class Solution {
public:
    int solve(int n) {
        if (n <= 1) return 1;    // only one way to reach
        return solve(n - 1) + solve(n - 2);
    }

    int climbStairs(int n) {
        return solve(n);
    }
};

TC -> O(2 ^ n), n is the number of steps
SC -> O(2 ^ n) , n is the number of steps

Extra:
	TC is 2 ^ n as we have n steps and at every step there are 2 choices.
	So the total choices becomes 2 * 2 * 2 * ...n times, which is 2 ^ n.
	SC is also 2 ^ n as we will need this many recursive call stacks
	to hold the result.
********************************************************************************










# Approach 2: Memoization

class Solution {
public:
    int solve(int n, vector <int> &dp) {
        if (n <= 1) return 1;    // only one way to reach
        if (dp[n] != -1) return dp[n];
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

    int climbStairs(int n) {
        vector <int> dp(n + 1, -1);
        return solve(n, dp);
    }
};

TC -> O(n), n is the number of steps
SC -> O(n), n is the number of steps
********************************************************************************










# Approach 2:

class Solution {
public:
    int climbStairs(int n) {
        vector <int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};

TC -> O(n), n is the number of steps
SC -> O(n), n is the number of steps
