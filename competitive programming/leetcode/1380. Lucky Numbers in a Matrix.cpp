Given a m * n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.



Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]


Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 10^5.
All elements in the matrix are distinct.








class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size();
        int n=matrix[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for(int i=0;i<m;i++){
            int mini=INT_MAX;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<mini) mini=matrix[i][j];
            }
            row[i]=mini;
        }

        for(int j=0;j<n;j++){
            int maxi=INT_MIN;
            for(int i=0;i<m;i++){
                if(matrix[i][j]>maxi) maxi=matrix[i][j];
            }
            col[j]=maxi;
        }


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==row[i] && matrix[i][j]==col[j])
                    res.push_back(matrix[i][j]);
            }
        }
        return res;
    }
};









// Optimized

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size();
        int n=matrix[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for(int i=0;i<m;i++){
            int mini=INT_MAX;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<mini) mini=matrix[i][j];
            }
            row[i]=mini;
        }

        for(int j=0;j<n;j++){
            int maxi=INT_MIN;
            for(int i=0;i<m;i++){
                if(matrix[i][j]>maxi) maxi=matrix[i][j];
            }
            col[j]=maxi;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i]==col[j])
                    res.push_back(row[i]);
            }
        }

        return res;
    }
};
