/*
A word or a sentence in some language is called a pangram if all the characters of the alphabet of this language appear in it at least once. Pangrams are often used to demonstrate fonts in printing or test the output devices.

You are given a string consisting of lowercase and uppercase Latin letters. Check whether this string is a pangram. We say that the string contains a letter of the Latin alphabet if this letter occurs in the string in uppercase or lowercase.

Input
The first line contains a single integer n (1?=?n?=?100) — the number of characters in the string.

The second line contains the string. The string consists only of uppercase and lowercase Latin letters.

Output
Output "YES", if the string is a pangram and "NO" otherwise.

Examples
inputCopy
12
toosmallword
outputCopy
NO
inputCopy
35
TheQuickBrownFoxJumpsOverTheLazyDog
outputCopy
YES
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
    
    bool vis[26] = {false};
    
    for (auto &x: s) {
    	vis[tolower(x) - 'a'] = true; 
	}
	
	int cnt = 0;
	
	for (auto &x: vis) {
		if (x == true) cnt++;
	}

	if (cnt == 26) cout << "YES";
	else cout << "NO";

    return 0;
}
