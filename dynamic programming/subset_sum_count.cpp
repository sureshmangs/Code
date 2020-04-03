#include<bits/stdc++.h>
using namespace std;

int subsetsumcount(int a[], int sum, int n){
    bool dp[n+1][sum+1];

    for(int i=0;i<n+1;i++)  dp[i][0]=true;
    for(int j=1;j<sum+1;j++) dp[0][j]=false;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(a[i-1]<=sum){
                dp[i][j]=dp[i-1][j-a[i-1]] || dp[i-1][j];
            }
            else dp[i][j]=dp[i-1][sum];
        }
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            cout<<dp[i][j]<<" ";
        } cout<<endl;
    }
    int cnt=0;
    for(int i=0;i<n+1;i++){
        if(dp[i][sum]==true) cnt++;
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int sum;
        cin>>sum;
        cout<<subsetsumcount(a,sum,n)<<endl;

    }
return 0;
}
