/*
A row of n cells is given, all initially white. Using a stamp, you can stamp any two neighboring cells such that one becomes red and the other becomes blue. A stamp can be rotated, i.e. it can be used in both ways: as BR and as RB.

During use, the stamp must completely fit on the given n cells (it cannot be partially outside the cells). The stamp can be applied multiple times to the same cell. Each usage of the stamp recolors both cells that are under the stamp.

For example, one possible sequence of stamps to make the picture BRBBW could be WWWWW?WWRB–––W?BR–––RBW?BRB–––BW. Here W, R, and B represent a white, red, or blue cell, respectively, and the cells that the stamp is used on are marked with an underline.

Given a final picture, is it possible to make it using the stamp zero or more times?

Input
The first line contains an integer t (1=t=104) — the number of test cases.

The first line of each test case contains an integer n (1=n=105) — the length of the picture.

The second line of each test case contains a string s — the picture you need to make. It is guaranteed that the length of s is n and that s only consists of the characters W, R, and B, representing a white, red, or blue cell, respectively.

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
Output t lines, each of which contains the answer to the corresponding test case. As an answer, output "YES" if it possible to make the picture using the stamp zero or more times, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

Example
inputCopy
12
5
BRBBW
1
B
2
WB
2
RW
3
BRB
3
RBB
7
WWWWWWW
9
RBWBWRRBW
10
BRBRBRBRRB
12
BBBRWWRRRWBR
10
BRBRBRBRBW
5
RBWBW
outputCopy
YES
NO
NO
NO
YES
YES
YES
NO
YES
NO
YES
NO
Note
The first test case is explained in the statement.

For the second, third, and fourth test cases, it is not possible to stamp a single cell, so the answer is "NO".

For the fifth test case, you can use the stamp as follows: WWW?WRB–––?BR–––B.

For the sixth test case, you can use the stamp as follows: WWW?WRB–––?RB–––B.

For the seventh test case, you don't need to use the stamp at all.


*/





#include<bits/stdc++.h>
using namespace std;
 
void solve() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	stringstream ss(s);
	
	string tmp;
	
	while (getline(ss, tmp, 'W')) {
		if (tmp.size() > 0) {
			bool hasR = false, hasB = false;
			for (auto &x: tmp) {
				if (x == 'R') hasR = true;
				else hasB = true;
			}
			if ((hasR && hasB) == false) {
				cout << "NO\n"; return;
			}
		}
	}
	cout << "YES\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
