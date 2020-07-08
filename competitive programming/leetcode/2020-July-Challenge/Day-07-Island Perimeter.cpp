You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.



Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16

Explanation: The perimeter is the 16 yellow stripes in the image below:









class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return ( i>=0 && i<m && j>=0 && j<n);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int peri=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){  // land
                    // top
                    if(isValid(i-1, j, m, n)==false) peri+=1;
                    else if(grid[i-1][j]==0) peri+=1;
                    // right
                    if(isValid(i, j+1, m, n)==false) peri+=1;
                    else if(grid[i][j+1]==0) peri+=1;
                    // down
                    if(isValid(i+1, j, m, n)==false) peri+=1;
                    else if(grid[i+1][j]==0) peri+=1;
                    // left
                    if(isValid(i, j-1, m, n)==false) peri+=1;
                    else if(grid[i][j-1]==0) peri+=1;
                }
            }
        }
        return peri;
    }
};
