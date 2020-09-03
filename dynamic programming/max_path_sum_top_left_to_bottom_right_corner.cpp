/*
Given an n*m matrix, the task is to find the maximum sum of elements of cell starting from the cell (0, 0) to cell (n-1, m-1).
However, the allowed moves are right, downwards or diagonally right, i.e, from location (i, j) next move can be (i+1, j), or, (i, j+1), or (i+1, j+1). Find the maximum sum of elements satisfying the allowed moves.
Examples:


Input:
mat[][] = {{100, -350, -200},
           {-100, -300, 700}}
Output: 500
Explanation:
Path followed is 100 -> -300 -> 700

Input:
mat[][] = {{500, 100, 230},
           {1000, 300, 100},
           {200, 1000, 200}}
Output:
3000
Explanation:
Path followed is 500 -> 1000 -> 300 -> 1000 -> 200
*/








#include <bits/stdc++.h>
using namespace std;

#define SIZE 10

int maxSum(int mat[SIZE][SIZE], int m, int n){
    int dp[m][n];

    dp[0][0]=mat[0][0];

    for(int i=1;i<m;i++) dp[i][0]=dp[i-1][0]+mat[i][0];
    for(int j=1;j<n;j++) dp[0][j]=dp[0][j-1]+mat[0][j];

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=max(dp[i][j-1],  max(dp[i-1][j-1], dp[i-1][j]))+mat[i][j];
        }
    }

    return dp[m-1][n-1];
}


int main(){
	int mat[SIZE][SIZE] = {{100, -350, -200},
                            {-100, -300, 700}};

	cout<<"Maximum Sum = "<<maxSum(mat, 4,4);

	return 0;
}
