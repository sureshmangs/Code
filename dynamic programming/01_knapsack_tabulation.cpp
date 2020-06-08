/*
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of four lines.
The first line consists of N the number of items.
The second line consists of W, the maximum capacity of the knapsack.
In the next line are N space separated positive integers denoting the values of the N items,
and in the fourth line are N space separated positive integers denoting the weights of the corresponding items.

Output:
For each testcase, in a new line, print the maximum possible value you can get with the given conditions that you can obtain for each test case in a new line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ v[i] ≤ 1000

Example:
Input:
2
3
4
1 2 3
4 5 1
3
3
1 2 3
4 5 6
Output:
3
0
Explanation:
Test Case 1: With W = 4, you can either choose the 0th item or the 2nd item. Thus, the maximum value you can generate is the max of val[0] and val[2], which is equal to 3.
Test Case 2: With W = 3, there is no item you can choose from the given list as all the items have weight greater than W. Thus, the maximum value you can generate is 0.
*/







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
                dp[i][j]=maxi(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
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
        for(int i=0;i<n;i++) cin>>val[i];
        for(int i=0;i<n;i++) cin>>wt[i];
        cout<<knapsack(wt,val,w,n)<<endl;
    }
return 0;
}

