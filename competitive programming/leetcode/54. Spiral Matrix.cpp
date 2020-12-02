Given an m x n matrix, return all elements of the matrix in spiral order.



Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100







class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        int m=matrix.size();
        int n=matrix[0].size();

        int r=0, c=0;

        while(r<m && c<n){
            for(int i=c;i<n;i++){
                res.push_back(matrix[r][i]);
            }
            r++;
            for(int i=r;i<m;i++){
                res.push_back(matrix[i][n-1]);
            }
            n--;
            if(r<m){
                for(int i=n-1;i>=c;i--){
                    res.push_back(matrix[m-1][i]);
                }
                m--;
            }
            if(c<n){
                for(int i=m-1;i>=r;i--){
                    res.push_back(matrix[i][c]);
                }
                c++;
            }
        }
        return res;
    }
};
