You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: Cheapest is: start on cost[1], pay that cost, and go to the top.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: Cheapest is: start on cost[0], and only step on 1s, skipping cost[3].
 

Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999

Hint

Say f[i] is the final cost to climb to the top from step i. Then f[i] = cost[i] + min(f[i+1], f[i+2]).



// TLE

class Solution {
public:
    
    int solve(int i, vector <int> &cost) {
        if (i >= cost.size()) return 0;
        
        int op1 = solve(i + 1, cost);
        int op2 = solve(i + 2, cost);
        
        return min(op1, op2) + cost[i];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        return min(solve(0, cost), solve(1, cost));
    }
};




// Memoization
// Accepted

class Solution {
public:
    
    vector <int> dp;
    
    int solve(int i, vector <int> &cost) {
        if (i >= cost.size()) return 0;
        
        if (dp[i] != -1) return dp[i];
        
        int op1 = solve(i + 1, cost);
        int op2 = solve(i + 2, cost);
        
        return dp[i] = min(op1, op2) + cost[i];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        dp.resize(cost.size(), -1);
        return min(solve(0, cost), solve(1, cost));
    }
};



// DP

class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector <int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for (int i = 2; i < n; i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        
        return min(dp[n - 1], dp[n - 2]);
    }
};
