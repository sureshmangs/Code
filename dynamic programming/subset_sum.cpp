/*
Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Each test case constitutes of two lines. First line contains 'N', representing the number of elements in the set and the second line contains the elements of the set.

Output:
Print YES if the given set can be partioned into two subsets such that the sum of elements in both subsets is equal, else print NO.

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= arr[i] <= 1000

Example:
Input:
2
4
1 5 11 5
3
1 3 5

Output:
YES
NO

Explanation:
Testcase 1: There exists two subsets such that {1, 5, 5} and {11}.
*/


#include<bits/stdc++.h>
using namespace std;

bool subsetsum(int a[], int sum, int n){
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
        int sum=0;
        for(int i=0;i<n;i++) sum+=a[i];
        if(sum%2!=0) cout<<"NO"<<endl;
        else {
            sum/=2;
            if(subsetsum(a,sum,n)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }

    }
return 0;
}
