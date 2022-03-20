/*
Luis has a sequence of n+1 integers a1,a2,…,an+1. For each i=1,2,…,n+1 it is guaranteed that 0=ai<n, or ai=n2. He has calculated the sum of all the elements of the sequence, and called this value s.

Luis has lost his sequence, but he remembers the values of n and s. Can you find the number of elements in the sequence that are equal to n2?

We can show that the answer is unique under the given constraints.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1=t=2·104). Description of the test cases follows.

The only line of each test case contains two integers n and s (1=n<106, 0=s=1018). It is guaranteed that the value of s is a valid sum for some sequence satisfying the above constraints.

Output
For each test case, print one integer — the number of elements in the sequence which are equal to n2.

Example
inputCopy
4
7 0
1 1
2 12
3 12
outputCopy
0
1
3
1
Note
In the first test case, we have s=0 so all numbers are equal to 0 and there isn't any number equal to 49.

In the second test case, we have s=1. There are two possible sequences: [0,1] or [1,0]. In both cases, the number 1 appears just once.

In the third test case, we have s=12, which is the maximum possible value of s for this case. Thus, the number 4 appears 3 times in the sequence.


*/





#include<bits/stdc++.h>
using namespace std;
 
 
void solve() {
	long long n, s;
	cin >> n >> s;
	
	long long res = s / (n * n);
	
	cout << min(res, n + 1) << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
