/*
Given a sorted array A of size N and a number X, you need to find the number of occurrences of X in A.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains two lines of input: The first line contains N and X(element whose occurrence needs to be counted). The second line contains the elements of the array separated by spaces.

Output:
For each testcase, print the count of the occurrences of X in the array, if count is zero then print -1.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 105
1 ≤ A[i] ≤ 103
1 <= X <= 103

Example:
Input:
2
7 2
1 1 2 2 2 2 3
7 4
1 1 2 2 2 2 3
Output:
4
-1

Explanation:
Testcase 1: 2 occurs 4 times in 1 1 2 2 2 2 3
Testcase 2: 4 is not present in 1 1 2 2 2 2 3
*/







#include<bits/stdc++.h>
using namespace std;

int first(int a[], int n, int x){
    int l=0, r=n-1, mid, res=-1;
    while(l<=r){
        mid=l+(r-l)/2;
        if(a[mid]==x){
            res=mid;
            r=mid-1;
        } else if(a[mid]<x) l=mid+1;
        else r=mid-1;
    }
    return res;
}

int last(int a[], int n, int x){
    int l=0, r=n-1, mid, res=-1;
    while(l<=r){
        mid=l+(r-l)/2;
        if(a[mid]==x){
            res=mid;
           l=mid+1;
        } else if(a[mid]<x) l=mid+1;
        else r=mid-1;
    }
    return res;
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
        int f=first(a, n, x);
        int l=last(a, n, x);
        if(f>=0)
            cout<<l-f+1<<endl;
        else cout<<"-1"<<endl;
    }

return 0;
}
