You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.






class Solution {
public:
    
    void dfs(int i, int j, vector <vector<int>> &grid, vector <vector<bool>> &visited, int &area) {
        // base case
        if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || grid[i][j] == 0 || visited[i][j]) return;
        
        area++;
        visited[i][j] = true;
        
        dfs (i + 1, j, grid, visited, area);
        dfs (i, j + 1, grid, visited, area);
        dfs (i - 1, j, grid, visited, area);
        dfs (i, j - 1, grid, visited, area);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        vector <vector<bool> > visited(m, vector <bool> (n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j]) {
                    int area = 0;
                    dfs(i, j, grid, visited, area);
                    res = max(res, area);
                }
                    
            }
        }
        
        return res;
    }
};
