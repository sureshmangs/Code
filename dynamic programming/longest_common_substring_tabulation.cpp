/*
Given two strings X and Y. The task is to find the length of the longest common substring.

Input:
First line of the input contains number of test cases T. Each test case consist of three lines, first of which contains 2 space separated integers N and M denoting the size of string X and Y strings respectively. The next two lines contains the string X and Y.

Output:
For each test case print the length of longest  common substring of the two strings .

Constraints:
1 <= T <= 200
1 <= N, M <= 100

Example:
Input:
2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC

Output:
4
1

Example:
Testcase 1: CDGH is the longest substring present in both of the strings.
*/




#include<bits/stdc++.h>
using namespace std;

int LCSubstring(string x, string y, int m, int n){
    int dp[m+1][n+1];

    for(int i=0;i<m+1;i++) dp[i][0]=0;
    for(int j=0;j<n+1;j++) dp[0][j]=0;

    int maxi=0;

    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1]==y[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=0;
            maxi=max(maxi, dp[i][j]);
        }
    }
    return maxi;
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
        string x, y;
        cin>>x>>y;
        cout<<LCSubstring(x,y,m,n)<<endl;
    }

return 0;
}
