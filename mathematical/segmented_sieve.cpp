/Peter wants to generate some prime numbers for his cryptosystem. 
Help him! Your task is to generate all prime numbers between two given numbers!

Input
The input begins with the number t of test cases in a single line (t<=10). 
In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

Output
For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.

Example
Input:
2
1 10
3 5

Output:
2
3
5
7

3
5
*/




#include<bits/stdc++.h>
using namespace std;

#define MAX 100000

vector <int> primes; // storing prime numbers

void segmentedSieve(int l, int r) {
	if (l == 1) l++; // one is not prime
	
	int maxN = r - l + 1;
	
	vector <bool> seg(maxN, true); 
	
	for (auto &p: primes) {
		if (p * p <= r) {
			// first multiple of p in [l, r]
			int i = (l / p) * p;
			if (i < l) i += p;
			
			for (; i <= r; i += p) {
				if (i != p) {
					seg[i - l] = false;
				}
			}
			
			
			
		} else break;
	}
	
	// print primes in [l, r]
	for (int i = 0; i < maxN; i++) {
		if (seg[i] == true) {
			cout << l + i << "\n";
		}
	}
}



void sieveOfEratosthenes (vector <bool> &sieve) {
    for (int i = 2; i * i <= MAX; i++) {
    	if (sieve[i] == true) {
    		for (int j = i * i; j <= MAX; j += i) {
    			sieve[j] = false;
			}
		}
	}
	
	for (int i = 2; i <= MAX; i++) {
		if (sieve[i] == true) {
			primes.push_back(i);
		}
	}
}

 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	// will take l, r range
	// generate prime numbers till sqrt(r)
	// r -> 10^9
	
	vector <bool> sieve(MAX + 1, true);
	
	sieveOfEratosthenes(sieve);
	
	while (t--) {
		int l, r;
		cin >> l >> r;
		
		segmentedSieve(l, r);
		
		cout << "\n";
	}
	
    return 0;
}
