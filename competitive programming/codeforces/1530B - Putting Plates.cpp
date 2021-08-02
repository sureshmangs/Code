/*
To celebrate your birthday you have prepared a festive table! Now you want to seat as many guests as possible.

The table can be represented as a rectangle with height h and width w, divided into h×w cells. Let (i,j) denote the cell in the i-th row and the j-th column of the rectangle (1=i=h; 1=j=w).

Into each cell of the table you can either put a plate or keep it empty.

As each guest has to be seated next to their plate, you can only put plates on the edge of the table — into the first or the last row of the rectangle, or into the first or the last column. Formally, for each cell (i,j) you put a plate into, at least one of the following conditions must be satisfied: i=1, i=h, j=1, j=w.

To make the guests comfortable, no two plates must be put into cells that have a common side or corner. In other words, if cell (i,j) contains a plate, you can't put plates into cells (i-1,j), (i,j-1), (i+1,j), (i,j+1), (i-1,j-1), (i-1,j+1), (i+1,j-1), (i+1,j+1).

Put as many plates on the table as possible without violating the rules above.

Input
The first line contains a single integer t (1=t=100) — the number of test cases.

Each of the following t lines describes one test case and contains two integers h and w (3=h,w=20) — the height and the width of the table.

Output
For each test case, print h lines containing w characters each. Character j in line i must be equal to 1 if you are putting a plate into cell (i,j), and 0 otherwise. If there are multiple answers, print any.

All plates must be put on the edge of the table. No two plates can be put into cells that have a common side or corner. The number of plates put on the table under these conditions must be as large as possible.

You are allowed to print additional empty lines.

Example
inputCopy
3
3 5
4 4
5 6
outputCopy
10101
00000
10101

0100
0001
1000
0010

010101
000000
100001
000000
101010
Note
For the first test case, example output contains the only way to put 6 plates on the table.

For the second test case, there are many ways to put 4 plates on the table, example output contains one of them.

Putting more than 6 plates in the first test case or more than 4 plates in the second test case is impossible.
*/




#include<bits/stdc++.h>
using namespace std;
 
void solve() {
	int n, m;
	cin >> n >> m;
	
	
	vector <vector<int> > v(n, vector <int> (m, 0));
	
	for (int i = 0; i < m; i += 2) v[0][i] = 1;
	
	if (v[0][m - 1] == 1 || v[0][m - 2] == 1) for (int i = 2; i < n; i += 2) v[i][m - 1] = 1;
	else for (int i = 1; i < n; i += 2) v[i][m - 1] = 1;
	
	if (v[n - 1][m - 1] == 1 || v[n - 2][m - 1] == 1) for (int i = m - 3; i >= 0; i -= 2) v[n - 1][i] = 1;
	else for (int i = m - 2; i >= 0; i -= 2) v[n - 1][i] = 1;
 
	if (v[n - 1][0] == 1  || v[n - 1][1] == 1) for (int i = n - 3; i > 1; i -= 2) v[i][0] = 1;
	else for (int i = n - 2; i > 1; i -= 2) v[i][0] = 1;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << v[i][j]; 
		}
		cout << "\n";
	}
	cout << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
