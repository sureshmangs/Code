#include<bits/stdc++.h>
using namespace std;

int subsetCountDiff(int a[], int x, int n){
    int dp[n+1][x+1];

    for(int i=0;i<n+1;i++)  dp[i][0]=1;
    for(int j=1;j<x+1;j++) dp[0][j]=0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<x+1;j++){
            if(a[i-1]<=j){
                dp[i][j]=dp[i-1][j-a[i-1]] + dp[i-1][j];
            }
            else dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][x];
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

        int diff;
        cin>>diff;

        int sum=0;
        for(int i=0;i<n;i++) sum+=a[i];

        int x=(diff+sum);

        if(x%2!=0) cout<<"0"<<endl;
        else cout<<subsetCountDiff(a, x/2, n)<<endl;
    }
return 0;
}
