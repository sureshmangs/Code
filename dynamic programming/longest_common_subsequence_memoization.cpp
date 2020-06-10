/*
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string str1 and str2 respectively
The next two lines contains the 2 string str1 and str2 .

Output:
For each test case print the length of longest  common subsequence of the two strings .

Constraints:
1<=T<=200
1<=size(str1),size(str2)<=100

Example:
Input:
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC

Output:
3
2

Explanation
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

LCS of "ABC" and "AC" is "AC" of length 2
*/





#include<bits/stdc++.h>
using namespace std;

int dp[102][102];     // set according to constraints

int LCS(string s1, string s2, int n, int m){
    if(n==0 || m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(s1[n-1]==s2[m-1])
        return dp[n][m]=1 + LCS(s1,s2,n-1,m-1);
    else return dp[n][m]=max(LCS(s1,s2,n,m-1), LCS(s1,s2,n-1,m));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s1,s2;
        cin>>s1>>s2;
        memset(dp, -1, sizeof(dp));
        cout<<LCS(s1,s2,n,m)<<endl;
    }

return 0;
}
