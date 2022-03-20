/*
You are given a decimal representation of an integer x without leading zeros.

You have to perform the following reduction on it exactly once: take two neighboring digits in x and replace them with their sum without leading zeros (if the sum is 0, it's represented as a single 0).

For example, if x=10057, the possible reductions are:

choose the first and the second digits 1 and 0, replace them with 1+0=1; the result is 1057;
choose the second and the third digits 0 and 0, replace them with 0+0=0; the result is also 1057;
choose the third and the fourth digits 0 and 5, replace them with 0+5=5; the result is still 1057;
choose the fourth and the fifth digits 5 and 7, replace them with 5+7=12; the result is 10012.
What's the largest number that can be obtained?

Input
The first line contains a single integer t (1=t=104) — the number of testcases.

Each testcase consists of a single integer x (10=x<10200000). x doesn't contain leading zeros.

The total length of the decimal representations of x over all testcases doesn't exceed 2·105.

Output
For each testcase, print a single integer — the largest number that can be obtained after the reduction is applied exactly once. The number should not contain leading zeros.

Example
inputCopy
2
10057
90
outputCopy
10012
9
Note
The first testcase of the example is already explained in the statement.

In the second testcase, there is only one possible reduction: the first and the second digits.
*/







#include<bits/stdc++.h>
using namespace std;
 
 
void solve() {
	string x, res = "";
	cin >> x;
	
	int n = x.length();
	
	// back
	for (int i = n - 1; i >= 0; i--) {
		int a = x[i] - '0';
		int b = x[i - 1] - '0';
		int c = a + b;
		if (c >= 10) {
			res = x.substr(0, i - 1) + to_string(c) + x.substr(i + 1, n);
			cout << res << endl;
			return;
		}
	}
	
	// front
	for (int i = 0; i < n - 1; i++) {
		int a = x[i] - '0';
		int b = x[i + 1] - '0';
		int c = a + b;
		if (a < c) {
			res = x.substr(0, i) + to_string(c) + x.substr(i + 2, n);
			cout << res << endl;
			return;
		}
	}
	
	// two digit
	if (n == 2) cout << (x[0] - '0') + (x[1] - '0');
	else cout << x.substr(0, n - 1);
	
	cout << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
