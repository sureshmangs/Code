You are given an array a1,a2,…,an of positive integers. A good pair is a pair of indices (i,j) with 1=i,j=n such that, for all 1=k=n, the following equality holds:

|ai-ak|+|ak-aj|=|ai-aj|,
where |x| denotes the absolute value of x.

Find a good pair. Note that i can be equal to j.

Input
The input consists of multiple test cases. The first line contains a single integer t (1=t=1000) — the number of test cases. Description of the test cases follows.

The first line of each test case contains an integer n (1=n=105) — the length of the array.

The second line of each test case contains n integers a1,a2,…,an (1=ai=109) where ai is the i-th element of the array.

The sum of n for all test cases is at most 2·105.

Output
For each test case, print a single line with two space-separated indices i and j which form a good pair of the array. 
The case i=j is allowed. It can be shown that such a pair always exists. If there are multiple good pairs, print any of them.

Example
inputCopy
3
3
5 2 7
5
1 4 2 2 3
1
2
outputCopy
2 3
1 2
1 1
Note
In the first case, for i=2 and j=3 the equality holds true for all k:

k=1: |a2-a1|+|a1-a3|=|2-5|+|5-7|=5=|2-7|=|a2-a3|,
k=2: |a2-a2|+|a2-a3|=|2-2|+|2-7|=5=|2-7|=|a2-a3|,
k=3: |a2-a3|+|a3-a3|=|2-7|+|7-7|=5=|2-7|=|a2-a3|.






#include<bits/stdc++.h>
using namespace std;
 
void solve() {
	int n;
	cin >> n;
	
	vector <int> v(n);
	for (auto &x: v) cin >> x;
	
	int minv = INT_MAX, maxv = INT_MIN, mini = 0, maxi = 0;
	
	for (int i = 0; i < n; i++) {
		if (v[i]  < minv) {
			minv = v[i];
			mini = i;
		}
		if (v[i] > maxv) {
			maxv = v[i];
			maxi = i;
		}
	}
	
	cout << mini + 1 << " " << maxi + 1 << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
