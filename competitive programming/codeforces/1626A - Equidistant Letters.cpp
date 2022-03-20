/*
You are given a string s, consisting of lowercase Latin letters. Every letter appears in it no more than twice.

Your task is to rearrange the letters in the string in such a way that for each pair of letters that appear exactly twice, the distance between the letters in the pair is the same. You are not allowed to add or remove letters.

It can be shown that the answer always exists. If there are multiple answers, print any of them.

Input
The first line contains a single integer t (1=t=103) — the number of testcases.

Each testcase consists of a non-empty string s, consisting of lowercase Latin letters. Every letter appears in the string no more than twice. The length of the string doesn't exceed 52.

Output
For each testcase, print a single string. Every letter should appear in it the same number of times as it appears in string s. For each pair of letters that appear exactly twice, the distance between the letters in the pair should be the same.

If there are multiple answers, print any of them.

Example
inputCopy
3
oelhl
abcdcba
ac
outputCopy
hello
ababcdc
ac
Note
In the first testcase of the example, the only letter that appears exactly twice is letter 'l'. You can rearrange the letters arbitrarily, since there are no distances to compare.

In the second testcase of the example, the letters that appear exactly twice are 'a', 'b' and 'c'. Initially, letters 'a' are distance 6 apart, letters 'b' are distance 4 apart and letters 'c' are distance 2 apart. They are not the same, so we have to rearrange the letters. After rearrangement, letters 'a' are distance 2 apart, letters 'b' are distance 2 apart and letters 'c' are distance 2 apart. They are all the same, so the answer is valid.

In the third testcase of the example, there are no letters that appear exactly twice. Thus, any rearrangement is valid. Including not changing the string at all.
*/




#include<bits/stdc++.h>
using namespace std;
 
 
void solve() {
	string s;
	cin >> s;
	
	vector <int> freq(26, 0);
	
	for (auto &x: s) freq[x - 'a']++;
	
	string twos = "";
	
	for (int i = 0; i < 26; i++) {
		if (freq[i] == 2) 
			twos += i + 'a';
	}
	
	twos += twos;
	
	for (int i = 0; i < 26; i++) {
		if (freq[i] == 1) twos += i + 'a';
	}
	
	cout << twos << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
