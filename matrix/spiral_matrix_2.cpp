Given a positive integer n, generate an n x n matrix filled with
elements from 1 to n^2 in spiral order.

Example 1:
Input: n = 3
Output: [[1,2,3],
		 [8,9,4],
		 [7,6,5]]

Example 2:
Input: n = 1
Output: [[1]]

Constraints:
1 <= n <= 20
********************************************************************************










# Approach 1: Clockwise spiral

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int num = 1;

        int r = 0, c = 0;
        int m = n;

        while (r < m && c < n) {
            for (int i = c; i < n; i++) res[r][i] = num++;
            r++;

            for (int i = r; i < m; i++) res[i][n - 1] = num++;
            n--;

            if (r >= m || c >= n) break;

            for (int i = n - 1; i >= c; i--) res[m - 1][i] = num++;
            m--;

            for (int i = m - 1; i >= r; i--) res[i][c] = num++;
            c++;
        }

        return res;
    }
};

TC -> O(n ^ 2), n is the size of the matrix
SC -> O(1)
