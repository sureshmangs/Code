You are given an m x n integer matrix grid???, where m and n are both even integers, and an integer k.

The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:



A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. 
To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:


Return the matrix after applying k cyclic rotations to it.

 

Example 1:


Input: grid = [[40,10],[30,20]], k = 1
Output: [[10,20],[40,30]]
Explanation: The figures above represent the grid at every state.
Example 2:

  
Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
Explanation: The figures above represent the grid at every state.
 

Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 50
Both m and n are even integers.
1 <= grid[i][j] <= 5000
1 <= k <= 109












class Solution {
public:
    
    void rotate(vector <int> &v, int k) {
        while (k--) {
            int tmp = v[0];
            for (int i = 0; i < v.size() - 1; i++) v[i] = v[i + 1];
            v[v.size() - 1] = tmp;
        }
    } 
    
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int layer = 0; layer < min(m / 2, n / 2); layer++) {
            int outerLayer = (2 * (m - 2 * layer)) + (2 * ((n - 2) - (2 * layer)));
            int numOfRotation = k;
            if (numOfRotation >= outerLayer) numOfRotation %= outerLayer;
            
            vector <int> v;
            
            // left to right
            for (int i = layer; i < (n - layer - 1); i++) v.push_back(grid[layer][i]);
            
            // right top to bottom
            for (int i = layer; i < (m - layer - 1); i++) v.push_back(grid[i][n - 1 - layer]);
            
            // bottom right to left
            for (int i = n - 1 - layer; i > layer; i--) v.push_back(grid[m - 1 - layer][i]);
            
            // left bottom to top
            for (int i = m - 1 - layer; i > layer; i--) v.push_back(grid[i][layer]);
                 
            rotate(v, numOfRotation);
            
            int p = 0;
            
            // left to right
            for (int i = layer; i < (n - layer - 1); i++) grid[layer][i] = v[p++];
            
            // right top to bottom
            for (int i = layer; i < (m - layer - 1); i++) grid[i][n - 1 - layer] = v[p++];
            
            // bottom right to left
            for (int i = n - 1 - layer; i > layer; i--) grid[m - 1 - layer][i] = v[p++];
            
            // left bottom to top
            for (int i = m - 1 - layer; i > layer; i--) grid[i][layer] = v[p++];
            
        }
        
        return grid;
    }
};
