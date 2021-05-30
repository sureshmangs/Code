/*
Mishka wants to buy some food in the nearby shop. Initially, he has s burles on his card.

Mishka can perform the following operation any number of times (possibly, zero): choose some positive integer number 1=x=s, buy food that costs exactly x burles and obtain ?x10? burles as a cashback (in other words, Mishka spends x burles and obtains ?x10? back). The operation ?ab? means a divided by b rounded down.

It is guaranteed that you can always buy some food that costs x for any possible value of x.

Your task is to say the maximum number of burles Mishka can spend if he buys food optimally.

For example, if Mishka has s=19 burles then the maximum number of burles he can spend is 21. Firstly, he can spend x=10 burles, obtain 1 burle as a cashback. Now he has s=10 burles, so can spend x=10 burles, obtain 1 burle as a cashback and spend it too.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1=t=104) — the number of test cases.

The next t lines describe test cases. Each test case is given on a separate line and consists of one integer s (1=s=109) — the number of burles Mishka initially has.

Output
For each test case print the answer on it — the maximum number of burles Mishka can spend if he buys food optimally.

Example
inputCopy
6
1
10
19
9876
12345
1000000000
outputCopy
1
11
21
10973
13716
1111111111

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
		
		long long res = 0;
		
		while (n > 0) {
			if (n < 10) {
				res += n;
				n /= 10;
			} else {
				long long c = log10(n);
				res += (long long)pow(10, c);
				n = n - (long long)pow(10, c) + (long long)pow(10, c - 1);
			}
		}
		
		cout << res << "\n";
	}
	

    return 0;
}
