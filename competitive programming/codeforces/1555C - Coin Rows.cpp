Alice and Bob are playing a game on a matrix, consisting of 2 rows and m columns. The cell in the i-th row in the j-th column contains ai,j coins in it.

Initially, both Alice and Bob are standing in a cell (1,1). They are going to perform a sequence of moves to reach a cell (2,m).

The possible moves are:

Move right — from some cell (x,y) to (x,y+1);
Move down — from some cell (x,y) to (x+1,y).
First, Alice makes all her moves until she reaches (2,m). She collects the coins in all cells she visit (including the starting cell).

When Alice finishes, Bob starts his journey. He also performs the moves to reach (2,m) and collects the coins in all cells that he visited, but Alice didn't.

The score of the game is the total number of coins Bob collects.

Alice wants to minimize the score. Bob wants to maximize the score. What will the score of the game be if both players play optimally?

Input
The first line contains a single integer t (1=t=104) — the number of testcases.

Then the descriptions of t testcases follow.

The first line of the testcase contains a single integer m (1=m=105) — the number of columns of the matrix.

The i-th of the next 2 lines contain m integers ai,1,ai,2,…,ai,m (1=ai,j=104) — the number of coins in the cell in the i-th row in the j-th column of the matrix.

The sum of m over all testcases doesn't exceed 105.

Output
For each testcase print a single integer — the score of the game if both players play optimally.

Example
inputCopy
3
3
1 3 7
3 5 1
3
1 3 9
3 5 1
1
4
7
outputCopy
7
8
0
Note
The paths for the testcases are shown on the following pictures. Alice's path is depicted in red and Bob's path is depicted in blue.







// o(m) accepted

#include<bits/stdc++.h>
using namespace std;
 
void solve() {
	int m;
	cin >> m;
	
	vector <vector<int>> v(2, vector<int> (m));
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <  m; j++) {
			cin >> v[i][j];
		}
	}
	
	vector <vector<int>> psum(2, vector<int> (m));
	
	psum[0][0] = v[0][0];
	psum[1][0] = v[1][0];
	
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <  m; j++) {
			psum[i][j] = psum[i][j - 1] + v[i][j];
		}
	}
	
	int res = INT_MAX;
	
	for (int i = 0; i < m; i++) {
		// 0th row
		int up = psum[0][m - 1] - psum[0][i];
		
		
		// 1st row
		int down = 0;
		
		if (i - 1 >= 0) down = psum[1][i - 1];
		
		res = min(res, max(up, down));
	}
	
	cout << res << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  solve();
	
    return 0;
}







// o(m^2) TLE

#include<bits/stdc++.h>
using namespace std;
 
void solve() {
	int m;
	cin >> m;
	
	vector <vector<int>> v(2, vector<int> (m));
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <  m; j++) {
			cin >> v[i][j];
		}
	}
	
	int res = INT_MAX;
	
	for (int i = 0; i < m; i++) {
		int up = 0;
		
		// 0th row
		for (int j = i + 1; j < m; j++) up += v[0][j];
		
		int down = 0;
		
		// 1st row
		for (int j = 0; j <  i; j++) down += v[1][j];
		
		res = min(res, max(up, down));
	}
	
	cout << res << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
