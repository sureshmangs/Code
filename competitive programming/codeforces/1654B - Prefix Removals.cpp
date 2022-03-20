You are given a string s consisting of lowercase letters of the English alphabet. You must perform the following algorithm on s:

Let x be the length of the longest prefix of s which occurs somewhere else in s as a contiguous substring (the other occurrence may also intersect the prefix). If x=0, break. Otherwise, remove the first x characters of s, and repeat.
A prefix is a string consisting of several first letters of a given string, without any reorders. An empty prefix is also a valid prefix. For example, the string "abcd" has 5 prefixes: empty string, "a", "ab", "abc" and "abcd".

For instance, if we perform the algorithm on s= "abcabdc",

Initially, "ab" is the longest prefix that also appears somewhere else as a substring in s, so s= "cabdc" after 1 operation.
Then, "c" is the longest prefix that also appears somewhere else as a substring in s, so s= "abdc" after 2 operations.
Now x=0 (because there are no non-empty prefixes of "abdc" that also appear somewhere else as a substring in s), so the algorithm terminates.
Find the final state of the string after performing the algorithm.

Input
The first line contains a single integer t (1=t=104) — the number of test cases.

This is followed by t lines, each containing a description of one test case. Each line contains a string s. The given strings consist only of lowercase letters of the English alphabet and have lengths between 1 and 2·105 inclusive.

It is guaranteed that the sum of the lengths of s over all test cases does not exceed 2·105.

Output
For each test case, print a single line containing the string s after executing the algorithm. It can be shown that such string is non-empty.

Example
inputCopy
6
abcabdc
a
bbbbbbbbbb
codeforces
cffcfccffccfcffcfccfcffccffcfccf
zyzyzwxxyyxxyyzzyzzxxwzxwywxwzxxyzzw
outputCopy
abdc
a
b
deforces
cf
xyzzw
Note
The first test case is explained in the statement.

In the second test case, no operations can be performed on s.

In the third test case,

Initially, s= "bbbbbbbbbb".
After 1 operation, s= "b".
In the fourth test case,

Initially, s= "codeforces".
After 1 operation, s= "odeforces".
After 2 operations, s= "deforces".








#include<bits/stdc++.h>
using namespace std;
 
 
void solve() { 	
	string s;
	cin >> s;
	
	vector <int> f(26, 0);
	
	for (auto &x: s) {
		f[x - 'a']++;
	}
	
	string res = "";
	
	for (int i = 0; i < s.length(); i++) {
		if (f[s[i] - 'a'] > 1) f[s[i] - 'a']--;
		else {
			for (int j = i; j < s.length(); j++) cout << s[j];
			cout << endl;
			return;
		}
	}
	
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
