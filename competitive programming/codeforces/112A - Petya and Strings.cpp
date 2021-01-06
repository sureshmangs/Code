/*
Little Petya loves presents. His mum bought him two strings of the same size for his birthday. The strings consist of uppercase and lowercase Latin letters. Now Petya wants to compare those two strings lexicographically. The letters' case does not matter, that is an uppercase letter is considered equivalent to the corresponding lowercase letter. Help Petya perform the comparison.

Input
Each of the first two lines contains a bought string. The strings' lengths range from 1 to 100 inclusive. It is guaranteed that the strings are of the same length and also consist of uppercase and lowercase Latin letters.

Output
If the first string is less than the second one, print "-1". If the second string is less than the first one, print "1". If the strings are equal, print "0". Note that the letters' case is not taken into consideration when the strings are compared.

Examples
inputCopy
aaaa
aaaA
outputCopy
0
inputCopy
abs
Abz
outputCopy
-1
inputCopy
abcdefg
AbCdEfF
outputCopy
1
Note
If you want more formal information about the lexicographical order (also known as the "dictionary order" or "alphabetical order"), you can visit the following site:

http://en.wikipedia.org/wiki/Lexicographical_order
*/



#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a, b;
    cin >> a >> b;
    
    int n = a.length();
    
    bool asmall = false, bsmall = false;
    
    for (int i = 0; i < n; i++) {
    	if (tolower(a[i]) < tolower(b[i])) {
    		asmall = true;
    		break;
		} else if (tolower(a[i]) > tolower(b[i])) {
			bsmall = true;
			break;
		}
	}
	
	if (!asmall && !bsmall) cout << 0;
	else if (asmall) cout << -1;
	else cout << 1; 


    return 0;
}
