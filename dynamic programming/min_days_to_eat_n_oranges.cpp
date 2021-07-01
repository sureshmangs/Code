There are n oranges in the kitchen and you decided to eat some of these oranges every day as follows:

Eat one orange.
If the number of remaining oranges (n) is divisible by 2 then you can eat  n/2 oranges.
If the number of remaining oranges (n) is divisible by 3 then you can eat  2*(n/3) oranges.
You can only choose one of the actions per day.

Return the minimum number of days to eat n oranges.

 

Example 1:

Input: n = 10
Output: 4
Explanation: You have 10 oranges.
Day 1: Eat 1 orange,  10 - 1 = 9.  
Day 2: Eat 6 oranges, 9 - 2*(9/3) = 9 - 6 = 3. (Since 9 is divisible by 3)
Day 3: Eat 2 oranges, 3 - 2*(3/3) = 3 - 2 = 1. 
Day 4: Eat the last orange  1 - 1  = 0.
You need at least 4 days to eat the 10 oranges.
Example 2:

Input: n = 6
Output: 3
Explanation: You have 6 oranges.
Day 1: Eat 3 oranges, 6 - 6/2 = 6 - 3 = 3. (Since 6 is divisible by 2).
Day 2: Eat 2 oranges, 3 - 2*(3/3) = 3 - 2 = 1. (Since 3 is divisible by 3)
Day 3: Eat the last orange  1 - 1  = 0.
You need at least 3 days to eat the 6 oranges.
Example 3:

Input: n = 1
Output: 1
Example 4:

Input: n = 56
Output: 6
 

Constraints:

1 <= n <= 2*10^9






// Best
// Memoization

class Solution {
public:
    unordered_map <int, int> dp;
    
    int solve(int n) {
        if (dp.find(n) != dp.end()) return dp[n];
        
        int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
        
        
        if (n % 2 == 0) op2 = 1 + solve(n / 2);
        
        if (n % 3 == 0) op3 = 1 + solve(n / 3);
        
        if (n % 2 != 0 || n % 3 != 0) op1 = 1 + solve(n - 1);
        
        return dp[n] = min(op1, min(op2, op3));
    }
    
    int minDays(int n) {
        dp[0] = 0;
        dp[1] = 1;
        
        return solve(n);
    }
};







// Memoization but array takes a lot of space  (Run time error)

class Solution {
public:
    vector <int> dp;
    
    int solve(int n) {
        if (n == 0) return 0;
        else if (n == 1) return 1;
        else if (n == 2) return 2;
        else if (n == 3) return 2;
        
        if (dp[n] != -1) return dp[n];
        
        int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
        
        
        if (n % 2 == 0) op2 = 1 + solve(n / 2);
        
        if (n % 3 == 0) op3 = 1 + solve(n / 3);
        
        if (n % 2 != 0 || n % 3 != 0) op1 = 1 + solve(n - 1);
        
        return dp[n] = min(op1, min(op2, op3));
    }
    
    int minDays(int n) {
        dp.resize(n + 1, -1);
        
        return solve(n);
    }
};




// DP (run time error dude to large space taken by array)

class Solution {
public:
    
    int minDays(int n) {
        if (n == 1 || n == 2) return n;
        if (n == 3) return 2;
        vector <int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 2;
        
        for (int i = 4; i <= n; i++) {
            int mini = dp[i - 1];
            if (i % 2 == 0) mini = min(mini, dp[i / 2]);
            if (i % 3 == 0) mini = min(mini, dp[i / 3]);
            
            dp[i] = mini + 1;
        }
        
        return dp[n];
    }
};


