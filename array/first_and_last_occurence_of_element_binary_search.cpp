/*
Given a sorted array with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

Note: If the number x is not found in the array just print '-1'.

Input:
The first line consists of an integer T i.e number of test cases. The first line of each test case contains two integers n and x. The second line contains n spaced integers.

Output:
Print index of the first and last occurrences of the number x with a space in between.

Constraints:
1<=T<=100
1<=n,a[i]<=1000

Example:
Input:
2
9 5
1 3 5 5 5 5 67 123 125
9 7
1 3 5 5 5 5 7 123 125

Output:
2 5
6 6
*/







#include<bits/stdc++.h>
using namespace std;

int first(int a[], int n, int item){
    int l=0, r=n-1, mid, res=-1;
    while(l<=r){
        mid=l+(r-l)/2;
        if(a[mid]==item){
            res=mid;    // can be a possible result
            r=mid-1;
        }
        else if(a[mid]<item) l=mid+1;
        else r=mid-1;
    }
    return res;
}

int last(int a[], int n, int item){
    int l=0, r=n-1, mid, res=-1;
    while(l<=r){
        mid=l+(r-l)/2;
        if(a[mid]==item){
            res=mid;    // can be a possible result
            l=mid+1;
        }
        else if(a[mid]<item) l=mid+1;
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
        int n, item;
        cin>>n>>item;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int f=first(a, n, item);
        int l=last(a, n, item);
        if(f>=0)
            cout<<f<<" "<<l<<endl;
        else cout<<"-1"<<endl;
    }

return 0;
}
