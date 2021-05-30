/*
Orac is studying number theory, and he is interested in the properties of divisors.

For two positive integers a and b, a is a divisor of b if and only if there exists an integer c, such that a�c=b.

For n=2, we will denote as f(n) the smallest positive divisor of n, except 1.

For example, f(7)=7,f(10)=2,f(35)=5.

For the fixed integer n, Orac decided to add f(n) to n.

For example, if he had an integer n=5, the new value of n will be equal to 10. And if he had an integer n=6, n will be changed to 8.

Orac loved it so much, so he decided to repeat this operation several times.

Now, for two positive integers n and k, Orac asked you to add f(n) to n exactly k times (note that n will change after each operation, so f(n) may change too) and tell him the final value of n.

For example, if Orac gives you n=5 and k=2, at first you should add f(5)=5 to n=5, so your new value of n will be equal to n=10, after that, you should add f(10)=2 to 10, so your new (and the final!) value of n will be equal to 12.

Orac may ask you these queries many times.

Input
The first line of the input is a single integer t (1=t=100): the number of times that Orac will ask you.

Each of the next t lines contains two positive integers n,k (2=n=106,1=k=109), corresponding to a query by Orac.

It is guaranteed that the total sum of n is at most 106.

Output
Print t lines, the i-th of them should contain the final value of n in the i-th query by Orac.

Example
inputCopy
3
5 1
8 2
3 4
outputCopy
10
12
12
Note
In the first query, n=5 and k=1. The divisors of 5 are 1 and 5, the smallest one except 1 is 5. Therefore, the only operation adds f(5)=5 to 5, and the result is 10.

In the second query, n=8 and k=2. The divisors of 8 are 1,2,4,8, where the smallest one except 1 is 2, then after one operation 8 turns into 8+(f(8)=2)=10. The divisors of 10 are 1,2,5,10, where the smallest one except 1 is 2, therefore the answer is 10+(f(10)=2)=12.

In the third query, n is changed as follows: 3?6?8?10?12.
*/



/*
#include<bits/stdc++.h>
using namespace std;

int getFactor(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return i;
	}
	return n;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while (t--) {
		int n, k;
		cin >> n >> k;
		
		for (int i = 1; i <= k; i++) {
			if (n % 2 == 0) {
				n += 2 * (k - i + 1);
				break;
			} else {
				int lfactor = getFactor(n);
				n += lfactor;
			}
		}
		
		cout << n << "\n";
	}
	
    return 0;
}
*/



#include<bits/stdc++.h>
using namespace std;

int getFactor(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return i;
	}
	return n;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while (t--) {
		int n, k;
		cin >> n >> k;
		
		if (n % 2 == 0) cout << n + (2 * k) << "\n";
		else cout << n + getFactor(n) + 2 * (k - 1) << "\n";
	}
	
    return 0;
}
