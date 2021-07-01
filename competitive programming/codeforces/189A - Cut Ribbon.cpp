/*
Polycarpus has a ribbon, its length is n. He wants to cut the ribbon in a way that fulfils the following two conditions:

After the cutting each ribbon piece should have length a, b or c.
After the cutting the number of ribbon pieces should be maximum.
Help Polycarpus and find the number of ribbon pieces after the required cutting.

Input
The first line contains four space-separated integers n, a, b and c (1?=?n,?a,?b,?c?=?4000) — the length of the original ribbon and the acceptable lengths of the ribbon pieces after the cutting, correspondingly. The numbers a, b and c can coincide.

Output
Print a single number — the maximum possible number of ribbon pieces. It is guaranteed that at least one correct ribbon cutting exists.

Examples
inputCopy
5 5 3 2
outputCopy
2
inputCopy
7 5 5 2
outputCopy
2
Note
In the first example Polycarpus can cut the ribbon in such way: the first piece has length 2, the second piece has length 3.

In the second example Polycarpus can cut the ribbon in such way: the first piece has length 5, the second piece has length 2.
*/










// DP

#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	
	vector <int> dp(n + 1, INT_MIN);
	
	int mini = min(a, min(b, c));
	
	dp[0] = 0;
	
	for (int i = 1; i <= n; i++) {
		if (i - a >= 0 ) dp[i] = max(dp[i], 1 + dp[i - a]);
		if (i - b >= 0 ) dp[i] = max(dp[i], 1 + dp[i - b]);
		if (i - c >= 0 ) dp[i] = max(dp[i], 1 + dp[i - c]);
	}
	
	cout << dp[n];
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	//cin >> t;
	
	while (t--)  solve();
	
    return 0;
}

















// Recurion Memoization

#include<bits/stdc++.h>
using namespace std;

vector <int> dp;

int rec(int n, int a, int b, int c) {
	if (n == 0) return 0;
	if (n < 0) return INT_MIN;
	
	if (dp[n] != -1) return dp[n];
	
	int op1 = INT_MIN, op2 = INT_MIN, op3 = INT_MIN;
	
	op1 = rec(n - a, a, b, c);
	op2 = rec(n - b, a, b, c);
	op3 = rec(n - c, a, b, c);
	
	return dp[n] = 1 + max(op1, max(op2, op3));
}

void solve() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	
	dp.resize(n + 1, -1);
	
	cout << rec(n, a, b, c);
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	//cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
