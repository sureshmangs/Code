/*
Given a string str we need to tell minimum characters to be added at front of string to make string palindrome.

Examples:

Input  : str = "ABC"
Output : 2
We can make above string palindrome as "CBABC"
by adding 'B' and 'C' at front.

Input  : str = "AACECAAAA";
Output : 2
We can make above string palindrome as AAAACECAAAA
by adding two A's at front of string.


*/



#include <bits/stdc++.h>
using namespace std;


vector<int> computeLPSArray(string str){
	int M = str.length();
	vector<int> lps(M);

	int len = 0;
	lps[0] = 0; // lps[0] is always 0

	// the loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while(i < M){
		if(str[i] == str[len]){
			len++;
			lps[i] = len;
			i++;
		}
		else { // (str[i] != str[len])
			// This is tricky. Consider the example.
			// AAACAAAA and i = 7. The idea is similar
			// to search step.
			if(len != 0){
				len = lps[len-1];
				// Also, note that we do not increment i here
			}
			else { // if (len == 0)
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}


int getMinCharToAddedToMakeStringPalin(string str){
	string revStr = str;
	reverse(revStr.begin(), revStr.end());

	// Get concatenation of string, special character and reverse string
	string concat = str + "$" + revStr;

	vector<int> lps = computeLPSArray(concat);

	// By subtracting last entry of lps vector from string length, we will get our result
	return (str.length() - lps.back());
}


int main(){
	string str = "ALPHA";
	cout << getMinCharToAddedToMakeStringPalin(str);
	return 0;
}




/*
Naive Approach
Start checking the string each time if it is a palindrome and if not,
then delete the last character and check again.
When the string gets reduced to wither a palindrome or empty
then the number of characters deleted from the end till now will be the answer
as those characters could have been inserted at the beginning of the original string
in the order which will will make the string a palindrome



Source: https://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/
*/
