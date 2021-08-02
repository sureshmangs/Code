/*
Let's call a number a binary decimal if it's a positive integer and all digits in its decimal notation are either 0 or 1. For example, 1010111 is a binary decimal, while 10201 and 787788 are not.

Given a number n, you are asked to represent n as a sum of some (not necessarily distinct) binary decimals. Compute the smallest number of binary decimals required for that.

Input
The first line contains a single integer t (1=t=1000), denoting the number of test cases.

The only line of each test case contains a single integer n (1=n=109), denoting the number to be represented.

Output
For each test case, output the smallest number of binary decimals required to represent n as a sum.

Example
inputCopy
3
121
5
1000000000
outputCopy
2
5
1
Note
In the first test case, 121 can be represented as 121=110+11 or 121=111+10.

In the second test case, 5 can be represented as 5=1+1+1+1+1.

In the third test case, 1000000000 is a binary decimal itself, thus the answer is 1.
*/






#include<bits/stdc++.h>
using namespace std;
 
void solve() {
	int n;
	cin >> n;
	
	int res = 0;
	
	while (n) {
		res = max(res, n % 10);
		n /= 10;
	}
	
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
