/*
Given a String, find the longest palindromic subsequence

Input:
The first line of input contains an integer T, denoting no of test cases. The only line of each test case consists of a string S(only lowercase)

Output:
Print the Maximum length possible for palindromic subsequence.

Constraints:
1<=T<=100
1<=|Length of String|<=1000


Examples:
Input:
2
bbabcbcab
abbaab
Output:
7
4
*/




#include<bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2, int n, int m){
    int dp[n+1][m+1];

    for(int i=0;i<n+1;i++) dp[i][0]=0;
    for(int j=0;j<m+1;j++) dp[0][j]=0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s1[i-1]==s2[j-1])
                 dp[i][j]=1 + dp[i-1][j-1];
            else dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][m];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1;
        int n=s1.length();
        for(int i=n-1;i>=0;i--)  s2.push_back(s1[i]);
        cout<<LCS(s1,s2,n,n)<<endl;
    }

return 0;
}
