The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

 

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537
 

Constraints:

0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.



// Memoization

class Solution {
public:
    vector <int> dp;
    
    int solve(int n) {
        if (n == 0 || n == 1) return n;
        if (n == 2) return 1;
        
        if (dp[n] != -1) return dp[n];
        
        return dp[n] = solve(n - 1) + solve(n - 2) + solve(n - 3);
    }
    
    int tribonacci(int n) {
        dp.resize(n + 1, -1);
        
        return solve(n);
    }
};





// DP

class Solution {
public:
    
    int tribonacci(int n) {
        if (n == 0 || n == 1) return n;
        vector <int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        
        for (int i = 3; i <= n ; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};



// DP (less space)

class Solution {
public:
    
    int tribonacci(int n) {
        if (n == 0 || n == 1) return n;
        vector <int> dp = {0, 1, 1};
        
        for (int i = 3; i <= n ; i++) {
            dp[i % 3] = dp[0] + dp[1] + dp[2];
        }
        return dp[n % 3];
    }
};
