/*
A magic number is a number formed by concatenation of numbers 1, 14 and 144. We can use each of these numbers any number of times. Therefore 14144, 141414 and 1411 are magic numbers but 1444, 514 and 414 are not.

You're given a number. Determine if it is a magic number or not.

Input
The first line of input contains an integer n, (1?=?n?=?109). This number doesn't contain leading zeros.

Output
Print "YES" if n is a magic number or print "NO" if it's not.

Examples
inputCopy
114114
outputCopy
YES
inputCopy
1111
outputCopy
YES
inputCopy
441231
outputCopy
NO

*/





#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	
	int n = s.length();
	
	string tmp = "";
	
	bool res = false;
	for (int i = 0; i <  n; i++) {
		res = false;
		tmp += s[i];
		
		if (tmp.length() >= 3 && s.substr(i -2, 3) == "144") res = true;
		if (tmp.length() >= 2 && s.substr(i - 1, 2) == "14") res = true;
		if (tmp.length() >= 1 && s.substr(i, 1) == "1") res = true; 
		
		if (!res) break;
	}
	
	res ? cout << "YES\n" : cout << "NO\n";
	
    return 0;
}
