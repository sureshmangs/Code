/*
Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins. The order of coins doesn’t matter. For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'M' denoting the size of array. The second line contains M space-separated integers A1, A2, ..., AN denoting the elements of the array. The third line contains an integer 'N' denoting the cents.

Output:
Print number of possible ways to make change for N cents.

Constraints:
1 ≤ T ≤ 50
1 ≤ N ≤ 300
1 ≤ A[i] ≤ 300

Example:
Input:
2
3
1 2 3
4
4
2 5 3 6
10

Output:
4
5

Explanation:
Testcase 1: The possiblities are as such: {1, 1, 1, 1}, {1, 1, 2}, {1, 3}, {2, 2}.
*/






#include<bits/stdc++.h>
using namespace std;

int coinChange(int coins[], int n, int amt){
    int dp[n+1][amt+1];

    for(int i=0;i<n+1;i++) dp[i][0]=1;
    for(int j=1;j<amt+1;j++) dp[0][j]=0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<amt+1;j++){
            if(coins[i-1]<=j)
                dp[i][j]=dp[i][j-coins[i-1]] + dp[i-1][j];
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][amt];
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

        int coins[n];
        for(int i=0;i<n;i++) cin>>coins[i];

        int amt;
        cin>>amt;

        cout<<coinChange(coins, n, amt)<<endl;

    }



return 0;
}
