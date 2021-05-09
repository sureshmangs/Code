/*
As it's the first of April, Heidi is suspecting that the news she reads today are fake, and she does not want to look silly in front of all the contestants. She knows that a newspiece is fake if it contains heidi as a subsequence. Help Heidi assess whether the given piece is true, but please be discreet about it...

Input
The first and only line of input contains a single nonempty string s of length at most 1000 composed of lowercase letters (a-z).

Output
Output YES if the string s contains heidi as a subsequence and NO otherwise.

Examples
inputCopy
abcheaibcdi
outputCopy
YES
inputCopy
hiedi
outputCopy
NO
Note
A string s contains another string p as a subsequence if it is possible to delete some characters from s and obtain p.
*/



#include<bits/stdc++.h>
using namespace std;

 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
   
    string search = "heidi";
   
    int j = 0;
   
	for (int i = 0; i < s.length(); i++) {
   		if (s[i] == search[j]) j++;
	}
	
	j == search.length() ? cout << "YES\n" : cout << "NO\n";
	 

    return 0;
}
