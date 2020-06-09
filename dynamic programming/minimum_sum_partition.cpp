/*
Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.


Output:
In each seperate line print minimum absolute difference.


Constraints:
1<=T<=200
1<=N<=50
1<=A[i]<=200


Example:
Input:
2
4
1 6 5 11
4
36 7 46 40

Output :
1
23

Explaination :
Testcase 1:
Subset1 = {1, 5, 6} ; sum of Subset1 = 12
Subset2 = {11} ;       sum of Subset2 = 11

Testcase 2:
Subset1 = {7, 46} ;   sum = 53
Subset2 = {36, 40} ; sum = 76
*/







#include<bits/stdc++.h>
using namespace std;

int minSumPartion(int a[], int n){
    int range=0;
    for(int i=0;i<n;i++) range+=a[i];

    bool dp[n+1][range+1];

    for(int i=0;i<n+1;i++) dp[i][0]=true;
    for(int j=1;j<range+1;j++) dp[0][j]=false;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<range+1;j++){
            if(a[i-1]<=j){
                dp[i][j]=dp[i-1][j-a[i-1]] || dp[i-1][j];
            } else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    vector<int> v;
    for(int j=0;j<(range)/2 + 1;j++){
        if(dp[n][j]) v.push_back(j);
    }

    int mini=INT_MAX;

    for(auto x: v){
        int tmp=range-2*x;
        if(tmp<mini) mini=tmp;
    }

    return mini;

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
        cout<<minSumPartion(a,n)<<endl;
    }

return 0;
}
