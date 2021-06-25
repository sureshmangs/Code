/*
You are given an array a consisting of n positive integers. Find a non-empty subset of its elements such that their sum is even (i.e. divisible by 2) or determine that there is no such subset.

Both the given array and required subset may contain equal values.

Input
The first line contains a single integer t (1=t=100), number of test cases to solve. Descriptions of t test cases follow.

A description of each test case consists of two lines. The first line contains a single integer n (1=n=100), length of array a.

The second line contains n integers a1,a2,…,an (1=ai=100), elements of a. The given array a can contain equal values (duplicates).

Output
For each test case output -1 if there is no such subset of elements. Otherwise output positive integer k, number of elements in the required subset. Then output k distinct integers (1=pi=n), indexes of the chosen elements. If there are multiple solutions output any of them.

Example
inputCopy
3
3
1 4 3
1
15
2
3 5
outputCopy
1
2
-1
2
1 2
Note
There are three test cases in the example.

In the first test case, you can choose the subset consisting of only the second element. Its sum is 4 and it is even.

In the second test case, there is only one non-empty subset of elements consisting of the first element, however sum in it is odd, so there is no solution.

In the third test case, the subset consisting of all array's elements has even sum.
*/




#include<bits/stdc++.h>
using namespace std;
 
void solve() {
	int n;
	cin >> n;
	
	vector <int>  v(n);
	
	for (auto &x: v) cin >> x;
	
	int eindex = -1;
	
	for (int i = 0; i <  n; i++) {
		if (v[i] % 2 == 0) {
			eindex = i + 1;
			break;
		}
	}
	
	if (eindex != -1) cout << "1\n" << eindex << "\n";
	else if (n > 1) cout << "2\n" << "1 2\n";
	else cout << "-1\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
