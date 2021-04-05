/*
Bachgold problem is very easy to formulate. Given a positive integer n represent it as a sum of maximum possible number of prime numbers. One can prove that such representation exists for any integer greater than 1.

Recall that integer k is called prime if it is greater than 1 and has exactly two positive integer divisors — 1 and k.

Input
The only line of the input contains a single integer n (2?=?n?=?100?000).

Output
The first line of the output contains a single integer k — maximum possible number of primes in representation.

The second line should contain k primes with their sum equal to n. You can print them in any order. If there are several optimal solution, print any of them.

Examples
inputCopy
5
outputCopy
2
2 3
inputCopy
6
outputCopy
3
2 2 2
*/



#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
  	int n;
  	cin >> n;
  	
  	int res;
  	
  	if (n % 2) {
  		res = 1 + (n - 3) / 2;
  		cout << res << endl;
  		cout << 3 << " ";
  		for (int i = 1; i <= res - 1; i++) cout << 2 << " ";
	  } else {
	  	res = n / 2;
	  	cout << res << endl;
  		for (int i = 1; i <= res; i++) cout << 2 << " ";
	  }
    
    
    return 0;
}
