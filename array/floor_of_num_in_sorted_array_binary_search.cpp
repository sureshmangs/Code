/*
Given a sorted array arr[] of size N without duplicates, and given a value x. Find the floor of x in given array. Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of elements in the array and element whose floor is to be searched. Last line of input contains array elements.

Output:
Output the index of floor of x if exists, else print -1.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
1 ≤ arr[i] ≤ 1018
0 ≤ X ≤ arr[n-1]

Example:
Input:
3
7 0
1 2 8 10 11 12 19
7 5
1 2 8 10 11 12 19
7 10
1 2 8 10 11 12 19

Output:
-1
1
3

Explanation:
Testcase 1: No element less than 0 is found. So output is "-1".
Testcase 2: Number less than 5 is 2, whose index is 1(0-based indexing).
*/








#include<bits/stdc++.h>
using namespace std;

int getFloor(long long a[], int n, int x){
    int l=0, h=n-1, mid, res=-1;
    while(l<=h){
        mid=l+(h-l)/2;
        if(a[mid]==x){
            return mid;
            h=mid-1;
        }
       else  if(a[mid]<x){
           res=mid;  // possible result
           l=mid+1;
       } else h=mid-1;
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
        long long a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<getFloor(a, n, x)<<endl;
    }

return 0;
}
