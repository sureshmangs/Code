Given a square matrix mat, return the sum of the matrix diagonals.
Only include the sum of all the elements on the primary diagonal and
all the elements on the secondary diagonal that are not part of the primary diagonal.

Example 1:
Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.

Example 2:
Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8

Example 3:
Input: mat = [[5]]
Output: 5

Constraints:
n == mat.length == mat[i].length
1 <= n <= 100
1 <= mat[i][j] <= 100
********************************************************************************










# Approach 1:

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0, n = mat.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || i == n - 1 - j)
                    sum += mat[i][j];
            }
        }

        return sum;
    }
};

TC -> O(n ^ 2), n is the size of matrix
SC -> O(1)

Extra:
	Here, we don't need to subtract mat[n/2][n/2] from sum when n is odd as sum will
	be only incremented for the first condition (i == j) and not for (i == n - 1 - j).
********************************************************************************










# Approach 2:

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0, n = mat.size();

        for (int i = 0; i < n; i++) {
            sum += mat[i][i];
            sum += mat[n - 1 - i][i];
        }

        if (n % 2) sum -= mat[n / 2][n / 2];

        return sum;
    }
};

TC -> O(n), n is the size of matrix
SC -> O(1)

Extra:
	Here, we need to subtract mat[n/2][n/2] from sum when n is odd as sum was
	incremented twice for the middle element in the matrix.
	Also, we can use mat[i][n - 1 - i] instead of mat[n - 1 - i][i].
	When mat[i][n - 1 - i] is used, we are calculating the secondary diagonal
	from top to bottom and if mat[n - 1 - i][i] is used, we are calculating
	the secondary diagonal from bottom to top.
