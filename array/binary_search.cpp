
/*
Given a sorted array arr[] of N integers and a number K is given. The task is to check if the element K is present in the array or not.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of elements in the array and the number K seperated by space. Next line contains N elements.

Output:
For each testcase, if the element is present in the array print "1" (without quotes), else print "-1" (without quotes).

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= K <= 106
1 <= arr[i] <= 106

Example:
Input:
2
5 6
1 2 3 4 6
5 2
1 3 4 5 6

Output:
1
-1

Explanation:
Testcase 1: Since, 6 is present in the array at index 4 (0-based indexing), so output is 1.
Testcase 2: Since, 2 is not present in the array, so output is -1.
*/







#include<bits/stdc++.h>
using namespace std;

int bSearch(int a[], int n, int item){
    int l=0, r=n-1, mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if(a[mid]==item) return 1; // found
        else if(a[mid]>item) r=mid-1;
        else l=mid+1;
    }
    return -1;
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
        cout<<bSearch(a, n, item)<<endl;
    }

return 0;
}
