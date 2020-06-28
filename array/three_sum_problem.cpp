/*
Given an array A[] of N numbers and another number x, determine whether or not there exist three elements in A[] whose sum is exactly x.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains n and x. Next line contains array elements.

Output:
Print 1 if there exist three elements in A whose sum is exactly x, else 0.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 103
1 ≤ A[i] ≤ 105

Example:
Input:
2
6 13
1 4 45 6 10 8
5 10
1 2 4 3 6

Output:
1
1

Explanation:
Testcase 1: There is one triplet with sum 13 in the array. Triplet elements are 1, 4, 8, whose sum is 13.
*/







#include<bits/stdc++.h>
using namespace std;


int threeSum(int a[], int n, int x){
    sort(a, a+n);
    for(int i=0;i<n-2;i++){
        int reqSum=x-a[i];
        int l=i+1, r=n-1;
        while(l<r){
            else if(a[l]+a[r]<reqSum) l++;
            else r--;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<threeSum(a, n, x)<<endl;
    }

return 0;
}
