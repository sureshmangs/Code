Given an n x n binary matrix grid, return the length of the shortest 
clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell 
(i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected 
(i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1









/*
Here DFS give TLE because we search for every path and then take min out of all that paths
But BFS work ?? why ?
because we do traverse in DFS manner so first time when we get target cell a[n-1][n-1] 
then this path is always minimum as we do DFS

Both solution are mentioned below
*/


// dfs (TLE)

class Solution {
public:
    int shortestPath = INT_MAX;
    vector <vector<bool>> vis;
    vector <pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    
    bool isValid(int i, int j, vector<vector<int>> &grid) {
        return (i >= 0 && i < grid.size() && j >= 0 && j < grid.size() && !vis[i][j] && grid[i][j] == 0);
    }
    
    void dfs(int i, int j, int path, vector<vector<int>> &grid) {
        if (i == grid.size() - 1 && j == grid.size() - 1) {
            path++;
            shortestPath = min(shortestPath, path);
            return;
        }
        
        vis[i][j] = true;
        
        for (auto direction: directions) {
            int x = i + direction.first;
            int y = j + direction.second;
            if (isValid(x, y, grid)) dfs(x, y, path + 1, grid);
        }
        
        vis[i][j] = false; // backtrack
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vis.resize(n, vector<bool>(n, false));
        
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1; // no path possible
        
        dfs(0, 0, 0, grid);
        
        return shortestPath != INT_MAX ? shortestPath : -1;
    }
};









// bfs

class Solution {
public:
    int shortestPath = INT_MAX;
    vector <vector<bool>> vis;
    vector <pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    
    bool isValid(int i, int j, vector<vector<int>> &grid) {
        return (i >= 0 && i < grid.size() && j >= 0 && j < grid.size() && !vis[i][j] && grid[i][j] == 0);
    }
    
    void bfs(int i, int j, int path, vector<vector<int>> &grid) {
        queue <pair<int, int>> q;
        
        q.push({i, j});
        
        while (!q.empty()) {
            int size = q.size();
            path++;
            
            while (size--) {
                
                i = q.front().first;
                j = q.front().second;
                q.pop();

                if (i == grid.size() - 1 && j == grid.size() - 1) {
                    shortestPath = min(shortestPath, path);
                    return;
                }

                for (auto direction: directions) {
                    int x = i + direction.first;
                    int y = j + direction.second;

                    if (isValid(x, y, grid)) {
                        vis[x][y] = 1; // mark visited
                        // here we don't mark vis[i][j] as visted
                        q.push({x, y});
                    }
                }
            }
        }
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vis.resize(n, vector<bool>(n, false));
        
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1; // no path possible
        
        bfs(0, 0, 0, grid);
        
        return shortestPath != INT_MAX ? shortestPath : -1;
    }
};









// OPtimization
// We can use the grid to make track of the visited nodes, update grid[i][j] = 1,
// so that we don't visite it again
