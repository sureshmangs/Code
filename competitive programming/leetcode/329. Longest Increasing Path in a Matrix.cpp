Hard

5889

95

Add to List

Share
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. 
You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

Example 1:


Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:


Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 2^31 - 1











// Approach 1: Recursion (TLE)
// TC -> O((N*M)*4^(N*M))
// SC -> O(N*M)

class Solution {
public:
    
    vector <pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int longestIncPath = 1;
    
    bool isValid(int i, int j, vector<vector<int>>& matrix) {
        return (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size());
    }
    
    int solve(int i, int j, vector<vector<int>>& matrix) {
        int path = 1;
        
        for (auto direction: directions) {
            int x = i + direction.first;
            int y = j + direction.second;
            
            if (isValid(x, y, matrix) && matrix[x][y] > matrix[i][j]) 
                path = max(path, 1 + solve(x, y, matrix));
        }
        
        return path;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        dp.resize(m, vector<int> (n, -1));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                longestIncPath = max(longestIncPath, solve(i, j, matrix));
            }
        }
        
        return longestIncPath;
    }
};











// Approach 2: memoization (Accepted)
// TC -> O(NM)
// SC -> O(NM)
class Solution {
public:
    
    vector <pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int longestIncPath = 1;
    vector<vector<int>> dp;
    
    bool isValid(int i, int j, vector<vector<int>>& matrix) {
        return (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size());
    }
    
    int solve(int i, int j, vector<vector<int>>& matrix) {
        if (dp[i][j] != -1) return dp[i][j];
        dp[i][j] = 1;
        
        for (auto direction: directions) {
            int x = i + direction.first;
            int y = j + direction.second;
            
            if (isValid(x, y, matrix) && matrix[x][y] > matrix[i][j]) 
                dp[i][j] = max(dp[i][j], 1 + solve(x, y, matrix));
        }
        
        return dp[i][j];
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        dp.resize(m, vector<int> (n, -1));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                longestIncPath = max(longestIncPath, solve(i, j, matrix));
            }
        }
        
        return longestIncPath;
    }
};	

