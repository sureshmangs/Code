/*
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)


length   | 1   2   3   4   5   6   7   8
--------------------------------------------
price    | 1   5   8   9  10  17  17  20
And if the prices are as following, then the maximum obtainable value is 24 (by cutting in eight pieces of length 1)

length   | 1   2   3   4   5   6   7   8
--------------------------------------------
price    | 3   5   8   9  10  17  17  20
*/





#include<bits/stdc++.h>
using namespace std;

int rodCutting(int rl[], int val[], int n, int len){
    int dp[n+1][len+1];

    for(int i=0;i<n+1;i++) dp[i][0]=0;
    for(int j=0;j<len+1;j++) dp[0][j]=0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<len+1;j++){
            if(rl[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i][j-rl[i-1]], dp[i-1][j]);
            } else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][len];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,len;
        cin>>n>>len;
        int rl[n], val[n];

        for(int i=0;i<n;i++) cin>>val[i];
        for(int i=0;i<n;i++) cin>>rl[i];

        cout<<rodCutting(rl,val,n,len)<<endl;
    }

return 0;
}
