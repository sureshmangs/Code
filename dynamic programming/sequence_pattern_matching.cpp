/*
Check whether string s1 occurs as a subsequence in string s2
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
        int n,m;
        cin>>n>>m;
        string s1,s2;
        cin>>s1>>s2;
        int lcs=LCS(s1, s2, n, m);
        if(n==lcs) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

return 0;
}



/*
Alternative Approach
Can be solved using O( n+m ) using 2 pointers technique
*/
