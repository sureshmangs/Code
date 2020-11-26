/*
You are given array consisting of n integers. Your task is to find the maximum length of an increasing subarray of the given array.

A subarray is the sequence of consecutive elements of the array. Subarray is called increasing if each element of this subarray strictly greater than previous.

Input
The first line contains single positive integer n (1 ≤ n ≤ 105) — the number of integers.

The second line contains n positive integers a1, a2, ..., an (1 ≤ ai ≤ 109).

Output
Print the maximum length of an increasing subarray of the given array.

Examples
inputCopy
5
1 7 2 11 15
outputCopy
3
inputCopy
6
100 100 100 100 100 100
outputCopy
1
inputCopy
3
1 2 3
outputCopy
3
*/









#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++) cin >> v[i];

    int cnt = 1, res = 1;

    for(int i = 0; i < n-1; i++){
        if(v[i] < v[i+1]){
            cnt++;
            res = max(res, cnt);
        } else {
            cnt = 1;
        }
    }

    cout << res;

    return 0;
}

