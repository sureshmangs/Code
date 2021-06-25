/*
Polycarp is mad about coding, that is why he writes Sveta encoded messages. He calls the median letter in a word the letter which is in the middle of the word. If the word's length is even, the median letter is the left of the two middle letters. In the following examples, the median letter is highlighted: contest, info. If the word consists of single letter, then according to above definition this letter is the median letter.

Polycarp encodes each word in the following way: he writes down the median letter of the word, then deletes it and repeats the process until there are no letters left. For example, he encodes the word volga as logva.

You are given an encoding s of some word, your task is to decode it.

Input
The first line contains a positive integer n (1?=?n?=?2000) � the length of the encoded word.

The second line contains the string s of length n consisting of lowercase English letters � the encoding.

Output
Print the word that Polycarp encoded.

Examples
inputCopy
5
logva
outputCopy
volga
inputCopy
2
no
outputCopy
no
inputCopy
4
abba
outputCopy
baba
Note
In the first example Polycarp encoded the word volga. At first, he wrote down the letter l from the position 3, after that his word looked like voga. After that Polycarp wrote down the letter o from the position 2, his word became vga. Then Polycarp wrote down the letter g which was at the second position, the word became va. Then he wrote down the letter v, then the letter a. Thus, the encoding looked like logva.

In the second example Polycarp encoded the word no. He wrote down the letter n, the word became o, and he wrote down the letter o. Thus, in this example, the word and its encoding are the same.

In the third example Polycarp encoded the word baba. At first, he wrote down the letter a, which was at the position 2, after that the word looked like bba. Then he wrote down the letter b, which was at the position 2, his word looked like ba. After that he wrote down the letter b, which was at the position 1, the word looked like a, and he wrote down that letter a. Thus, the encoding is abba.
*/




#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	string res = s;
	
	int mid = (n - 1) / 2;
	int left = mid - 1, right = mid + 1, k = 0;
	
	res[mid] = s[k++];
	
	while (left >= 0 || right < n) {
		if (n % 2) {
			if (left >= 0) res[left] = s[k++];
			if (right < n) res[right] = s[k++];
		} else {
			if (right < n) res[right] = s[k++];
			if (left >= 0) res[left] = s[k++];
		}
	
		left--;
		right++;
	}
	
	cout << res << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	//cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
