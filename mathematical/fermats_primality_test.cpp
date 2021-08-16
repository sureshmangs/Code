Given the number, you are to answer the question: "Is it prime?"


Input
t – the number of test cases, then t test cases follows. [t <= 500]
Each line contains one integer: N [2 <= N <= 2^63-1]
Output
For each test case output string "YES" if given number is prime and "NO" otherwise.
Example
Input:
5
2
3
4
5
6

Output:
YES
YES
NO
YES
NO










#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

lli mulMod(lli a, lli b, lli c) {
	lli x = 0, y = a % c;
	
	while (b > 0) {
		if (b % 2) {
			x = (x + y) % c;
		}
		
		b /= 2;
		y = (y * 2LL) % c;
	}
	
	return x % c;
}


lli binPower(lli x, lli y, lli mod) {
	lli res = 1;
	
	while (y) {
		if (y % 2) res = mulMod(res, x, mod);
		
		y /= 2;
		x = mulMod(x, x, mod);
	}
	
	return res % mod;
}
 
bool isPrime(lli n, int iterations = 5) {
	if (n <= 4) {
		return n == 2 || n == 3;
	}
	
	for (int i = 1; i <= iterations; i++) {
		lli a = 2 + rand() % (n - 3);   // as 2 <= a <= (n - 2)
		lli res = binPower(a, n - 1, n);   // a^(n - 1) % n
		
		if (res != 1) return false;
	}
	
	return true;
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  {
		lli n;
		cin >> n;
		
		if (isPrime(n)) cout << "YES\n";
		else cout << "NO\n"; 
	}
	
    return 0;
}
