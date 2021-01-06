/*
Ternary numeric notation is quite popular in Berland. To telegraph the ternary number the Borze alphabet is used. Digit 0 is transmitted as «.», 1 as «-.» and 2 as «--». You are to decode the Borze code, i.e. to find out the ternary number given its representation in Borze alphabet.

Input
The first line contains a number in Borze code. The length of the string is between 1 and 200 characters. It's guaranteed that the given string is a valid Borze code of some ternary number (this number can have leading zeroes).

Output
Output the decoded ternary number. It can have leading zeroes.

Examples
inputCopy
.-.--
outputCopy
012
inputCopy
--.
outputCopy
20
inputCopy
-..-.--
outputCopy
1012

*/



#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	string s;
	cin >> s;
	
	int n = s.length();
	
	string res = "";
	
	for (int i = 0; i < n;  ) {
		if (s[i] == '.') {
			res += '0';
			i++;
		} else if (s[i] == '-' && (i + 1 < n && s[i + 1] == '.')) {
			res += '1';
			i += 2;
		} else {
			res += '2';
			i += 2;
		}
	}
	
	cout << res;

    return 0;
}

