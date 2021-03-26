/*
In the 2022 year, Mike found two binary integers a and b of length n (both of them are written only by digits 0 and 1) that can have leading zeroes. In order not to forget them, he wanted to construct integer d in the following way:

he creates an integer c as a result of bitwise summing of a and b without transferring carry, so c may have one or more 2-s. For example, the result of bitwise summing of 0110 and 1101 is 1211 or the sum of 011000 and 011000 is 022000;
after that Mike replaces equal consecutive digits in c by one digit, thus getting d. In the cases above after this operation, 1211 becomes 121 and 022000 becomes 020 (so, d won't have equal consecutive digits).
Unfortunately, Mike lost integer a before he could calculate d himself. Now, to cheer him up, you want to find any binary integer a of length n such that d will be maximum possible as integer.

Maximum possible as integer means that 102>21, 012<101, 021=21 and so on.

Input
The first line contains a single integer t (1=t=1000) — the number of test cases.

The first line of each test case contains the integer n (1=n=105) — the length of a and b.

The second line of each test case contains binary integer b of length n. The integer b consists only of digits 0 and 1.

It is guaranteed that the total sum of n over all t test cases doesn't exceed 105.

Output
For each test case output one binary integer a of length n. Note, that a or b may have leading zeroes but must have the same length n.

Example
inputCopy
5
1
0
3
011
3
110
6
111000
6
001011
outputCopy
1
110
100
101101
101110
Note
In the first test case, b=0 and choosing a=1 gives d=1 as a result.

In the second test case, b=011 so:

if you choose a=000, c will be equal to 011, so d=01;
if you choose a=111, c will be equal to 122, so d=12;
if you choose a=010, you'll get d=021.
If you select a=110, you'll get d=121.
We can show that answer a=110 is optimal and d=121 is maximum possible.
In the third test case, b=110. If you choose a=100, you'll get d=210 and it's the maximum possible d.

In the fourth test case, b=111000. If you choose a=101101, you'll get d=212101 and it's maximum possible d.

In the fifth test case, b=001011. If you choose a=101110, you'll get d=102121 and it's maximum possible d.
*/




#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		string b;
		cin >> b;
		
		string a = "", res="";
		
		if (b[0] == '0') {
			res += '1';
			a += '1';
		}
		else {
			res += '2';
			a += '1';
		}
		
		for (int i = 1; i < n; i++) {
			if (b[i] == '0') {
				if (res[i - 1] == '0' || res[i - 1] == '2') {
					res += '1';
					a += '1';
				} else if (res [i - 1] == '1') {
					res += '0';
					a += '0';
				}
			} else {
				if (res[i - 1] == '0' || res[i - 1] == '1') {
					res += '2';
					a += '1';
				} else if (res[i - 1] == '2') {
					res += '1';
					a += '0';
				}
			}
		}
		
		cout << a << endl;
	}
 
}
