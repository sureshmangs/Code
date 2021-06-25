/*
You are given an array a consisting of n integers.

Let's call a pair of indices i, j good if 1=i<j=n and gcd(ai,2aj)>1 (where gcd(x,y) is the greatest common divisor of x and y).

Find the maximum number of good index pairs if you can reorder the array a in an arbitrary way.

Input
The first line contains a single integer t (1=t=1000) — the number of test cases.

The first line of the test case contains a single integer n (2=n=2000) — the number of elements in the array.

The second line of the test case contains n integers a1,a2,…,an (1=ai=105).

It is guaranteed that the sum of n over all test cases does not exceed 2000.

Output
For each test case, output a single integer — the maximum number of good index pairs if you can reorder the array a in an arbitrary way.

Example
inputCopy
3
4
3 6 5 3
2
1 7
5
1 4 2 4 1
outputCopy
4
0
9
Note
In the first example, the array elements can be rearranged as follows: [6,3,5,3].

In the third example, the array elements can be rearranged as follows: [4,4,2,1,1].
*/



#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		vector <int> v;
		
		for (int i = 0; i <  n; i++) {
			int a;
			cin >> a;
			if (a % 2) v.push_back(a);
		}
		
		int even = n - v.size();
		int odd = v.size();
		
		long long cnt = n - 1, res = 0;
		
		res += (even * (2 * (n - 1) - (even - 1))) / 2;
		
		for (int i = 0; i < odd; i++) {
			for (int j = i + 1; j < odd; j++) {
				if (__gcd(v[i], v[j]) != 1) res++;
			}
		}
		
		cout << res << "\n";
 
	}
	
    return 0;
}
