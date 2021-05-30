/*
The only difference between the easy and hard versions is that the given string s in the easy version is initially a palindrome, this condition is not always true for the hard version.

A palindrome is a string that reads the same left to right and right to left. For example, "101101" is a palindrome, while "0101" is not.

Alice and Bob are playing a game on a string s (which is initially a palindrome in this version) of length n consisting of the characters '0' and '1'. Both players take alternate turns with Alice going first.

In each turn, the player can perform one of the following operations:

Choose any i (1=i=n), where s[i]= '0' and change s[i] to '1'. Pay 1 dollar.
Reverse the whole string, pay 0 dollars. This operation is only allowed if the string is currently not a palindrome, and the last operation was not reverse. That is, if Alice reverses the string, then Bob can't reverse in the next move, and vice versa.
Reversing a string means reordering its letters from the last to the first. For example, "01001" becomes "10010" after reversing.

The game ends when every character of string becomes '1'. The player who spends minimum dollars till this point wins the game and it is a draw if both spend equal dollars. If both players play optimally, output whether Alice wins, Bob wins, or if it is a draw.

Input
The first line contains a single integer t (1=t=103). Then t test cases follow.

The first line of each test case contains a single integer n (1=n=103).

The second line of each test case contains the string s of length n, consisting of the characters '0' and '1'. It is guaranteed that the string s is a palindrome and contains at least one '0'.

Note that there is no limit on the sum of n over test cases.

Output
For each test case print a single word in a new line:

"ALICE", if Alice will win the game,
"BOB", if Bob will win the game,
"DRAW", if the game ends in a draw.
Example
inputCopy
2
4
1001
1
0
outputCopy
BOB
BOB
Note
In the first test case of the example,

in the 1-st move Alice has to perform the 1-st operation, since the string is currently a palindrome.
in the 2-nd move Bob reverses the string.
in the 3-rd move Alice again has to perform the 1-st operation. All characters of the string are '1', game over.
Alice spends 2 dollars while Bob spends 0 dollars. Hence, Bob always win
*/




#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		int zero = 0;
		
		for (auto &x: s){
			if (x == '0') zero++;
		}
		
		if (zero == 1) cout << "BOB\n";
		else if (zero % 2) cout << "ALICE\n";
		else cout << "BOB\n";
	}
	

    return 0;
}
