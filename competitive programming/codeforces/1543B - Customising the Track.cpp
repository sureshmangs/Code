/*
Highway 201 is the most busy street in Rockport. Traffic cars cause a lot of hindrances to races, especially when there are a lot of them. The track which passes through this highway can be divided into n sub-tracks. You are given an array a where ai represents the number of traffic cars in the i-th sub-track. You define the inconvenience of the track as ?i=1n?j=i+1n|ai-aj|, where |x| is the absolute value of x.

You can perform the following operation any (possibly zero) number of times: choose a traffic car and move it from its current sub-track to any other sub-track.

Find the minimum inconvenience you can achieve.

Input
The first line of input contains a single integer t (1=t=10000) — the number of test cases.

The first line of each test case contains a single integer n (1=n=2·105).

The second line of each test case contains n integers a1,a2,…,an (0=ai=109).

It is guaranteed that the sum of n over all test cases does not exceed 2·105.

Output
For each test case, print a single line containing a single integer: the minimum inconvenience you can achieve by applying the given operation any (possibly zero) number of times.

Example
inputCopy
3
3
1 2 3
4
0 1 1 0
10
8 3 6 11 5 2 1 7 10 4
outputCopy
0
4
21
Note
For the first test case, you can move a car from the 3-rd sub-track to the 1-st sub-track to obtain 0 inconvenience.

For the second test case, moving any car won't decrease the inconvenience of the track.


*/





#include<bits/stdc++.h>
using namespace std;
 
void solve() {
	long long n;
	cin >> n;
	
	long long sum = 0;
	
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		sum += a;
	}
	
	long long extra = sum % n;
	long long res =  extra * (n - extra);
	
	cout << res << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
