/*
Given two sequences, print the longest subsequence present in both of them.
Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
*/






#include<bits/stdc++.h>
using namespace std;

string printLCS(string s1, string s2, int n, int m){
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

    int i=n, j=m;
    string s;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            s.push_back(s1[i-1]);
            i--; j--;
        } else {
            if(dp[i][j-1]>dp[i-1][j]) j--;
            else i--;
        }
    }

    int len=s.length();
    for(int i=0, j=len-1; i<len/2; i++, j--){
        swap(s[i],s[j]);
    }

   return s;
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
        cout<<printLCS(s1,s2,n,m)<<endl;
    }

return 0;
}
