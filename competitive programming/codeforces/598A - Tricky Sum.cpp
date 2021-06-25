/*
In this problem you are to calculate the sum of all integers from 1 to n, but you should take all powers of two with minus in the sum.

For example, for n?=?4 the sum is equal to ?-?1?-?2?+?3?-?4?=??-?4, because 1, 2 and 4 are 20, 21 and 22 respectively.

Calculate the answer for t values of n.

Input
The first line of the input contains a single integer t (1?=?t?=?100) — the number of values of n to be processed.

Each of next t lines contains a single integer n (1?=?n?=?109).

Output
Print the requested sum for each of t integers n given in the input.

Examples
inputCopy
2
4
1000000000
outputCopy
-4
499999998352516354
Note
The answer for the first sample is explained in the statement.


*/




#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while (t--) {
		long long n;
		cin >> n;
		
		long long k = (long long)log2(n);
		
		long long res = (n * (n + 1)) / 2;
		
		long long twos = (long long)pow(2, k + 1) - 1;
		
		res = res - 2 * twos;
		
		cout << res << "\n";
	}
	
    return 0;
}
