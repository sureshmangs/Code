/*
Given two strings X and Y, print the shortest string that has both X and Y as subsequences. If multiple shortest supersequence exists, print any one of them.

Examples:

Input: X = "AGGTAB",  Y = "GXTXAYB"
Output: "AGXGTXAYB" OR "AGGXTXAYB"
OR Any string that represents shortest
supersequence of X and Y

Input: X = "HELLO",  Y = "GEEK"
Output: "GEHEKLLO" OR "GHEEKLLO"
OR Any string that represents shortest
supersequence of X and Y
*/






#include<bits/stdc++.h>
using namespace std;

string SCS(string s1, string s2, int n, int m){
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
    string scs;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            scs.push_back(s1[i-1]);
            i--; j--;
        } else {
            if(dp[i][j-1]>dp[i-1][j]){
                scs.push_back(s2[j-1]);
                j--;
            } else {
                scs.push_back(s1[i-1]);
                i--;
            }
        }
    }
    while(i>0){
        scs.push_back(s1[i-1]);
        i--;
    }
    while(j>0){
        scs.push_back(s2[j-1]);
        j--;
    }

    int scsLen=scs.length();
    for(int i=0, j=scsLen-1; i<scsLen/2; i++, j--){
        swap(scs[i], scs[j]);
    }
    return scs;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int n=s1.length();
        int m=s2.length();
        cout<<SCS(s1, s2, n, m)<<endl;
    }

return 0;
}

