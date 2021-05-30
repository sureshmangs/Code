/*
Two-gram is an ordered pair (i.e. string of length two) of capital Latin letters. For example, "AZ", "AA", "ZA" — three distinct two-grams.

You are given a string s consisting of n capital Latin letters. Your task is to find any two-gram contained in the given string as a substring (i.e. two consecutive characters of the string) maximal number of times. For example, for string s = "BBAABBBA" the answer is two-gram "BB", which contained in s three times. In other words, find any most frequent two-gram.

Note that occurrences of the two-gram can overlap with each other.

Input
The first line of the input contains integer number n (2=n=100) — the length of string s. The second line of the input contains the string s consisting of n capital Latin letters.

Output
Print the only line containing exactly two capital Latin letters — any two-gram contained in the given string s as a substring (i.e. two consecutive characters of the string) maximal number of times.

Examples
inputCopy
7
ABACABA
outputCopy
AB
inputCopy
5
ZZZAA
outputCopy
ZZ
Note
In the first example "BA" is also valid answer.

In the second example the only two-gram "ZZ" can be printed because it contained in the string "ZZZAA" two times.


*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	unordered_map <string, int> mp;
	
	for (int i = 0; i < n - 1; i++) {
		string tmp = "";
		tmp = tmp + s[i] + s[i + 1];
		mp[tmp]++;
	}
	
	string res = "";
	int maxi = INT_MIN;
	
	for (auto &it: mp) {
		if (it.second > maxi) {
			maxi = it.second;
			res = it.first;
		}
	}
	
	cout << res;
	
    return 0;
}
