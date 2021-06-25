/*
A and B are preparing themselves for programming contests.

To train their logical thinking and solve problems better, A and B decided to play chess. During the game A wondered whose position is now stronger.

For each chess piece we know its weight:

the queen's weight is 9,
the rook's weight is 5,
the bishop's weight is 3,
the knight's weight is 3,
the pawn's weight is 1,
the king's weight isn't considered in evaluating position.
The player's weight equals to the sum of weights of all his pieces on the board.

As A doesn't like counting, he asked you to help him determine which player has the larger position weight.

Input
The input contains eight lines, eight characters each � the board's description.

The white pieces on the board are marked with uppercase letters, the black pieces are marked with lowercase letters.

The white pieces are denoted as follows: the queen is represented is 'Q', the rook � as 'R', the bishop � as'B', the knight � as 'N', the pawn � as 'P', the king � as 'K'.

The black pieces are denoted as 'q', 'r', 'b', 'n', 'p', 'k', respectively.

An empty square of the board is marked as '.' (a dot).

It is not guaranteed that the given chess position can be achieved in a real game. Specifically, there can be an arbitrary (possibly zero) number pieces of each type, the king may be under attack and so on.

Output
Print "White" (without quotes) if the weight of the position of the white pieces is more than the weight of the position of the black pieces, print "Black" if the weight of the black pieces is more than the weight of the white pieces and print "Draw" if the weights of the white and black pieces are equal.

Examples
inputCopy
...QK...
........
........
........
........
........
........
...rk...
outputCopy
White
inputCopy
rnbqkbnr
pppppppp
........
........
........
........
PPPPPPPP
RNBQKBNR
outputCopy
Draw
inputCopy
rppppppr
...k....
........
........
........
........
K...Q...
........
outputCopy
Black
Note
In the first test sample the weight of the position of the white pieces equals to 9, the weight of the position of the black pieces equals 5.

In the second test sample the weights of the positions of the black and the white pieces are equal to 39.

In the third test sample the weight of the position of the white pieces equals to 9, the weight of the position of the black pieces equals to 16.
*/





#include<bits/stdc++.h>
using namespace std;

unordered_map <char, int> mp = {{'Q', 9}, {'R', 5}, {'B', 3}, {'NN', 3}, {'P', 1}};

void solve() {
	int n = 8, wsum = 0, bsum = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			char a = s[j];
			if (a == '.') continue;
			if (isupper(a)) {
				wsum += mp[a];
			} else {
				bsum += mp[toupper(a)];
			}
		}
	}

	if (wsum > bsum) cout << "White";
	else if (wsum < bsum) cout << "Black";
	else cout << "Draw";
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	//cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
