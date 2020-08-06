Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?








class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool fr=false, fc=false;  // check if first row or column contains a zero

        for(int i=0;i<m;i++) // col 0
            if(matrix[i][0]==0) fc=true;

        for(int j=0;j<n;j++)  // row 0
            if(matrix[0][j]==0) fr=true;

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[0][j]==0 || matrix[i][0]==0) matrix[i][j]=0;
            }
        }
        if(fr){
            for(int j=0;j<n;j++) matrix[0][j]=0;
        }
        if(fc){
            for(int i=0;i<m;i++) matrix[i][0]=0;
        }
    }
};





/*
Brute force approach would be to create two temporary arrays for row and col and marking them on the basis of 0s and 1s
*/
