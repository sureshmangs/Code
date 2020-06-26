/*
The task is to count all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down.

Input:
First line consists of T test cases. First line of every test case consists of N and M, denoting the number of rows and number of column respectively.

Output:
Single line output i.e count of all the possible paths from top left to bottom right of a mXn matrix. Since output can be very large number use %10^9+7.

Constraints:
1<=T<=100
1<=N<=100
1<=M<=100

Example:
Input:
1
3 3
Output:
6
*/









#include<bits/stdc++.h>
using namespace std;

#define M 1000000007

int uniquePaths(int m, int n){
    int dp[m][n];
    for(int i=0;i<m;i++) dp[i][0]=1;
    for(int j=0;j<n;j++) dp[0][j]=1;
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%M;
            //+ dp[i-1][j-1]; if diagonal movement is allowed
    }
    return dp[m-1][n-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        cout<<uniquePaths(m, n)<<endl;
    }

return 0;
}
