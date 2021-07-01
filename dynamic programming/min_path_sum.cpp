Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.






// Recursive (TLE)

class Solution {
public:
    
    int solve(int i, int j, vector<vector<int>> &grid) {
        if (i == grid.size() - 1 && j == grid[0].size() - 1) return grid[i][j];
        
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return INT_MAX;
        
        int down = solve(i + 1, j, grid);
        int right = solve(i, j + 1, grid);
        
        return min(down, right) + grid[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        
        return solve(0, 0, grid);
    }
};





//Recursive Memoized (Accepted)

class Solution {
public:
    vector <vector<int>> dp;
        
    int solve(int i, int j, vector<vector<int>> &grid) {
        if (i == grid.size() - 1 && j == grid[0].size() - 1) return grid[i][j];
        
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return INT_MAX;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int down = solve(i + 1, j, grid);
        int right = solve(i, j + 1, grid);
        
        return dp[i][j] = min(down, right) + grid[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        
        dp.resize(m, vector<int> (n, -1));
        
        return solve(0, 0, grid);
    }
};


// O(n2)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();

        int dp[m][n];

        dp[0][0]=grid[0][0];

        for(int i=1;i<m;i++) dp[i][0]=dp[i-1][0]+grid[i][0];
        for(int j=1;j<n;j++) dp[0][j]=dp[0][j-1]+grid[0][j];

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=min(dp[i-1][j], dp[i][j-1])+grid[i][j];
            }
        }

        return dp[m-1][n-1];
    }
};



// using same grid array to store results
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        
        for (int i = 1; i < m; i++) grid[i][0] += grid[i - 1][0];
        for (int j = 1; j < n; j++) grid[0][j] += grid[0][j - 1];
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
            }
        }
        
        return grid[m - 1][n - 1];
    }
};
