/*
You have probably registered on Internet sites many times. And each time you should enter your invented password. Usually the registration form automatically checks the password's crypt resistance. If the user's password isn't complex enough, a message is displayed. Today your task is to implement such an automatic check.

Web-developers of the company Q assume that a password is complex enough, if it meets all of the following conditions:

the password length is at least 5 characters;
the password contains at least one large English letter;
the password contains at least one small English letter;
the password contains at least one digit.
You are given a password. Please implement the automatic check of its complexity for company Q.

Input
The first line contains a non-empty sequence of characters (at most 100 characters). Each character is either a large English letter, or a small English letter, or a digit, or one of characters: "!", "?", ".", ",", "_".

Output
If the password is complex enough, print message "Correct" (without the quotes), otherwise print message "Too weak" (without the quotes).

Examples
inputCopy
abacaba
outputCopy
Too weak
inputCopy
X12345
outputCopy
Too weak
inputCopy
CONTEST_is_STARTED!!11
outputCopy
Correct
*/




#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    if (s.length() < 5) cout << "Too weak";
    else {
    	bool big = false, small = false, digit = false;
    	for (auto &x: s) {
    		if (x >= 'a' && x <= 'z') small = true;
    		else if (x >= 'A' && x <= 'Z') big = true;
    		else if (x >= '0' && x <= '9') digit = true;
		}
		if (small && big && digit) cout << "Correct";
		else cout << "Too weak";
	}

    return 0;
}
