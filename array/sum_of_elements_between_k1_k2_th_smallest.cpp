//*
Given an array of positive integers and two positive integers K1 and K2. Find sum of all elements greater tha K1th and smaller than K2th smallest elements of array.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N, denoting the length of the array. Next line contains N space seperated integers of the array. Third line contains two space seperated integers denoting K1th and K2th smallest elements.

Output:
For each test case, output the sum of all the elements between K1th and K2th smallest elements.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= K1, K2 <= 1014

Example:
Input
2
7
20 8 22 4 12 10 14
3 6
6
10 2 50 12 48 13
2 6

Output:
26
73

Explanation:
Test Case 1:
3rd smallest element is 10
6th smallest element is 20
Sum of all element between K1 & K2 is 12 + 14 = 26
*/







#include<bits/stdc++.h>
using namespace std;


pair<long long, long long> getKthSmall(long long a[], long long n, long long k1, long long k2){
    priority_queue<int> maxh;  // max heap
    long long k=max(k1, k2);
    for(long long i=0;i<n;i++){
        maxh.push(a[i]);
        if(maxh.size()>k) maxh.pop();
    }
    long long mink=min(k1, k2);
    long long lg=maxh.top();   // large
    while(maxh.size()>mink){
        maxh.pop();
    };
    long long sm=maxh.top();   // small

    pair<long long, long long> res;
    res.first=sm;
    res.second=lg;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long long n, k1, k2;
        cin>>n;
        long long a[n];
        for(long long i=0;i<n;i++) cin>>a[i];
        cin>>k1>>k2;
        pair<long long, long long > sk=getKthSmall(a, n, k1, k2);
        long long sk1=sk.first;   // small
        long long sk2=sk.second;  // large
        long long sum=0;
        for(long long i=0;i<n;i++){
            if(a[i]>sk1 && a[i]<sk2){
                sum+=a[i];
            }
        }
        cout<<sum<<endl;
    }

return 0;
}
