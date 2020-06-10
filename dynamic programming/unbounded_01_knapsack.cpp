/*
Given weights and values related to n items and the maximum capacity allowed for these items. What is the maximum value we can achieve if we can pick any weights any number of times for a total allowed weight of W?

Input:
The first line of input contains an integer denoting the number of test cases. Then T test cases follow . Each test case contains two integers N and W denoting the number of items and the total allowed weight. In the next two lines are space separated values of the array denoting values of the items (val[]) and their weights (wt[]) respectively.

Output:
For each test case, in a new line, print the  maximum value which we can achieve if we can pick any weights any number of times for a bag of size W.

Constraints:
1 <= T <= 100
1 <= N, W <= 103
1 <= wt[], val[] <= 100

Example:
Input:
2
2 3
1 1
2 1
4 8
1 4 5 7
1 3 4 5
Output:
3
11
*/







#include<bits/stdc++.h>
using namespace std;

int unboundedKnapSack(int wt[], int val[], int n, int w){
    int dp[n+1][w+1];

    for(int i=0;i<n+1;i++) dp[i][0]=0;
    for(int j=0;j<w+1;j++) dp[0][j]=0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]], dp[i-1][j]);
            } else {
                dp[i][j]=dp[i-1][j];
            }
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
        int wt[n], val[n];

        for(int i=0;i<n;i++) cin>>val[i];
        for(int i=0;i<n;i++) cin>>wt[i];

        cout<<unboundedKnapSack(wt,val,n,w)<<endl;
    }

return 0;
}
