/*
Given an array arr[] of length N and an integer X, the task is to find the number of subsets with sum equal to X.

Examples:

Input: arr[] = {1, 2, 3, 3}, X = 6
Output: 3
All the possible subsets are {1, 2, 3},
{1, 2, 3} and {3, 3}



Input: arr[] = {1, 1, 1, 1}, X = 1
Output: 4
*/






#include<bits/stdc++.h>
using namespace std;

int subsetsumcount(int a[], int sum, int n){
    int dp[n+1][sum+1];

    for(int i=0;i<n+1;i++)  dp[i][0]=1;
    for(int j=1;j<sum+1;j++) dp[0][j]=0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(a[i-1]<=j){
                dp[i][j]=dp[i-1][j-a[i-1]] + dp[i-1][j];
            }
            else dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][sum];
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
