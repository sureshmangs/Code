/*
Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1 (or true) then make all the cells of ith row and jth column as 1.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is r and c, r is the number of rows and c is the number of columns.
The second line of each test case contains all the elements of the matrix in a single line separated by a single space.

Output:
Print the modified array.

Constraints:
1 ≤ T ≤ 100
1 ≤ r, c ≤ 1000
0 ≤ A[i][j] ≤ 1

Example:
Input:
3
2 2
1 0
0 0
2 3
0 0 0
0 0 1
4 3
1 0 0
1 0 0
1 0 0
0 0 0

Output:
1 1
1 0
0 0 1
1 1 1
1 1 1
1 1 1
1 0 0

Explanation:
Testcase1: Since only first element of matrix has 1 (at index 1,1) as value, so first row and first column are modified to 1.
*/







#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool fr=false, fc=false;  // check if first row or column contains a zero

        for(int i=0;i<m;i++) // col 0
            if(matrix[i][0]==1) fc=true;

        for(int j=0;j<n;j++)  // row 0
            if(matrix[0][j]==1) fr=true;

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==1){
                    matrix[0][j]=1;
                    matrix[i][0]=1;
                }
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[0][j]==1 || matrix[i][0]==1) matrix[i][j]=1;
            }
        }
        if(fr){
            for(int j=0;j<n;j++) matrix[0][j]=1;
        }
        if(fc){
            for(int i=0;i<m;i++) matrix[i][0]=1;
        }
    }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int r, c;
        cin>>r>>c;
        vector<vector<int> > matrix(r, vector<int> (c, 0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int ch; cin>>ch;
                matrix[i][j]=ch;
            }
        }

        setZeroes(matrix);

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
return 0;
}



/*
Brute force approach would be to create two temporary arrays for row and col and marking them on the basis of 0s and 1s
*/
