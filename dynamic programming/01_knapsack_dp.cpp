#include<bits/stdc++.h>
using namespace std;

int maxi(int a, int b) { return (a > b)? a : b; }

int knapsack(int wt[], int val[], int w, int n){
    int dp[n+1][w+1];

    for(int i=0;i<n+1;i++)
        dp[i][0]=0;
    for(int j=0;j<w+1;j++)
        dp[0][j]=0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j)
                dp[i][j]=maxi(val[i-1]+dp[i-1][w-wt[i-1]], dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][w];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,w;
        cin>>n>>w;
        int wt[n],val[n];
        for(int i=0;i<n;i++) cin>>wt[i];
        for(int i=0;i<n;i++) cin>>val[i];
        cout<<knapsack(wt,val,w,n)<<endl;
    }
return 0;
}
