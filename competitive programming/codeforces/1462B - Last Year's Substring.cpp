/*
Polycarp has a string s[1…n] of length n consisting of decimal digits.
Polycarp performs the following operation with the string s no more than once (i.e. he can perform operation 0 or 1 time):

Polycarp selects two numbers i and j (1=i=j=n) and removes characters from the
 s string at the positions i,i+1,i+2,…,j (i.e. removes substring s[i…j]).
  More formally, Polycarp turns the string s into the string s1s2…si-1sj+1sj+2…sn.
For example, the string s="20192020" Polycarp can turn into strings:

"2020" (in this case (i,j)=(3,6) or (i,j)=(1,4));
"2019220" (in this case (i,j)=(6,6));
"020" (in this case (i,j)=(1,5));
other operations are also possible, only a few of them are listed above.
Polycarp likes the string "2020" very much, so he is wondering if it is possible to turn the string s into a string "2020" in no more than one operation? Note that you can perform zero operations.

Input
The first line contains a positive integer t (1=t=1000) — number of test cases in the test. Then t test cases follow.

The first line of each test case contains an integer n (4=n=200) — length of the string s. The next line contains a string s of length n consisting of decimal digits. It is allowed that the string s starts with digit 0.

Output
For each test case, output on a separate line:

"YES" if Polycarp can turn the string s into a string "2020" in no more than one operation (i.e. he can perform 0 or 1 operation);
"NO" otherwise.
You may print every letter of "YES" and "NO" in any case you want (so, for example, the strings yEs, yes, Yes and YES will all be recognized as positive answer).

Example
inputCopy
6
8
20192020
8
22019020
4
2020
5
20002
6
729040
6
200200
outputCopy
YES
YES
YES
NO
NO
NO
Note
In the first test case, Polycarp could choose i=3 and j=6.

In the second test case, Polycarp could choose i=2 and j=5.

In the third test case, Polycarp did not perform any operations with the string.
*/




#include<bits/stdc++.h>
using namespace std;
 
void solve() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	if (s.substr(0, 1) + s.substr(n - 3, 3) == "2020") cout << "YES\n";
	else if (s.substr(0, 2) + s.substr(n - 2, 2) == "2020") cout << "YES\n";
	else if (s.substr(0, 3) + s.substr(n - 1, 1) == "2020") cout << "YES\n";
	else if (s.substr(0, 4) == "2020" || s.substr(n - 4, 4) == "2020") cout << "YES\n";
	else cout << "NO\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  solve();
	
    return 0;
}




