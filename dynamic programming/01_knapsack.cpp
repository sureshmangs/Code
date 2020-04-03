#include<bits/stdc++.h>
using namespace std;

int dp[100][1000];

int maxi(int a, int b) { return (a > b)? a : b; }

int knapsack(int wt[], int val[], int w, int n){
    if(n==0 || w==0) return 0;
    if(dp[n][w]!=-1) return dp[n][w];
    if(wt[n-1]<=w)
        return dp[n][w]=maxi(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1), knapsack(wt,val,w,n-1));
    else return dp[n][w]=knapsack(wt,val,w,n-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        int n,w;
        cin>>n>>w;
        int wt[n],val[n];
        for(int i=0;i<n;i++) cin>>wt[i];
        for(int i=0;i<n;i++) cin>>val[i];
        cout<<knapsack(wt,val,w,n)<<endl;
    }
return 0;
}
