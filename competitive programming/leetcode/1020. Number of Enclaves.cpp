You are given an m x n binary matrix grid,
where 0 represents a sea cell and 1 represents a land cell.
A move consists of walking from one land cell to another adjacent (4-directionally)
land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary
of the grid in any number of moves.

Example 1:
Input: grid =  [[0,0,0,0],
				[1,0,1,0],
				[0,1,1,0],
				[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is
not enclosed because its on the boundary.

Example 2:
Input: grid =  [[0,1,1,0],
				[0,0,1,0],
				[0,0,1,0],
				[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.
********************************************************************************










# Approach 1: DFS

class Solution {
public:
    vector <pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool isValid (int i, int j, vector<vector<int>> &grid) {
        return (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j]);
    }
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis) {
        vis[i][j] = true;
        for (auto &x: dir) {
            int r = i + x.first;
            int c = j + x.second;
            if (isValid(r, c, grid) && !vis[r][c]) dfs(r, c, grid, vis);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector <bool> (n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && !vis[i][j]) {
                    if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                        dfs(i, j, grid, vis);
                }
            }
        }

        int island = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && !vis[i][j]) island++;
            }
        }

        return island;
    }
};

TC -> O(m * n), m, n is the size of the matrix
SC -> O(m * n), m, n is the size of the matrix
