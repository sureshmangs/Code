Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.



Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3









class Solution {
public:
    bool isSafe(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j){
        return (i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]=='1' && !vis[i][j]);
    }
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j){
        vis[i][j]=true;
        if(isSafe(grid, vis, i-1, j))  dfs(grid, vis, i-1, j); // top

        if(isSafe(grid, vis, i, j-1))  dfs(grid, vis, i, j-1);  // left

        if(isSafe(grid, vis, i+1, j)) dfs(grid, vis, i+1, j);  // down

        if(isSafe(grid, vis, i, j+1)) dfs(grid, vis, i, j+1);  // right

    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();

        vector<vector<bool> > vis(m, vector<bool>(n,false));
        int island=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    island++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return island;
    }
};
