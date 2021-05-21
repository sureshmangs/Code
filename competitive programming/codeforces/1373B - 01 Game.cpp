/*
Alica and Bob are playing a game.

Initially they have a binary string s consisting of only characters 0 and 1.

Alice and Bob make alternating moves: Alice makes the first move, Bob makes the second move, Alice makes the third one, and so on. During each move, the current player must choose two different adjacent characters of string s and delete them. For example, if s=1011001 then the following moves are possible:

delete s1 and s2: 1011001?11001;
delete s2 and s3: 1011001?11001;
delete s4 and s5: 1011001?10101;
delete s6 and s7: 1011001?10110.
If a player can't make any move, they lose. Both players play optimally. You have to determine if Alice can win.

Input
First line contains one integer t (1=t=1000) — the number of test cases.

Only line of each test case contains one string s (1=|s|=100), consisting of only characters 0 and 1.

Output
For each test case print answer in the single line.

If Alice can win print DA (YES in Russian) in any register. Otherwise print NET (NO in Russian) in any register.

Example
inputCopy
3
01
1111
0011
outputCopy
DA
NET
NET
Note
In the first test case after Alice's move string s become empty and Bob can not make any move.

In the second test case Alice can not make any move initially.

In the third test case after Alice's move string s turn into 01. Then, after Bob's move string s become empty and Alice can not make any move.
*/



#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while (t--) {
		string s;
		cin >> s;
		
		int zero = 0, one = 0;
		
		for (auto &x: s) {
			if (x == '0') zero++;
		}
		
		one = s.length() - zero;
		
		int res = min(zero, one);
	
		res % 2 ? cout << "DA\n" : cout << "NET\n";
		
	}

    return 0;
}





/*
#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while (t--) {
		string s;
		cin >> s;
		
		int zero = 0, one = 0;
		
		for (auto &x: s) {
			if (x == '0') zero++;
		}
		
		one = s.length() - zero;
		
		bool res = false;  // true -> Alice Wins
		
		while (zero > 0 && one > 0) {
			for (int i = 0; i < s.length() - 1; i++) {
				if (s[i] != s[i + 1]) {
					s.erase(i, 2);
					res = !res;
					zero -= 1;
					one -= 1;
					i -= 2;
				}
			}
		}
	
		res ? cout << "DA\n" : cout << "NET\n";
		
	}

    return 0;
}
*/
