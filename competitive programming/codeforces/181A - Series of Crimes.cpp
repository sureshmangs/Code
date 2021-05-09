/*
The Berland capital is shaken with three bold crimes committed by the Pihsters, a notorious criminal gang.

The Berland capital's map is represented by an n?×?m rectangular table. Each cell of the table on the map represents some districts of the capital.

The capital's main detective Polycarpus took a map and marked there the districts where the first three robberies had been committed as asterisks. Deduction tells Polycarpus that the fourth robbery will be committed in such district, that all four robbed districts will form the vertices of some rectangle, parallel to the sides of the map.

Polycarpus is good at deduction but he's hopeless at math. So he asked you to find the district where the fourth robbery will be committed.

Input
The first line contains two space-separated integers n and m (2?=?n,?m?=?100) — the number of rows and columns in the table, correspondingly.

Each of the next n lines contains m characters — the description of the capital's map. Each character can either be a "." (dot), or an "*" (asterisk). A character equals "*" if the corresponding district has been robbed. Otherwise, it equals ".".

It is guaranteed that the map has exactly three characters "*" and we can always find the fourth district that meets the problem requirements.

Output
Print two integers — the number of the row and the number of the column of the city district that is the fourth one to be robbed. The rows are numbered starting from one from top to bottom and the columns are numbered starting from one from left to right.

Examples
inputCopy
3 2
.*
..
**
outputCopy
1 1
inputCopy
3 3
*.*
*..
...
outputCopy
2 3

*/




#include<bits/stdc++.h>
using namespace std;

 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector <vector <char> > v(n, vector <char> (m, ' '));
    
    for (int i = 0; i < n; i++) {
    	for (int j  = 0; j < m; j++) {
    		cin >> v[i][j];
		}
	}
	
	int row, col;
	
	for (int i = 0; i < n; i++) {
		int cnt = 0;
    	for (int j  = 0; j < m; j++) {
    		if (v[i][j] == '*') cnt++;
		}
		if (cnt == 1) {
			row = i + 1; break;
		}
	}
	
	for (int j = 0; j < m; j++) {
		int cnt = 0;
    	for (int i  = 0; i < n; i++) {
    		if (v[i][j] == '*') cnt++;
		}
		if (cnt == 1) {
			col = j + 1; break;
		}
	}
	
	cout << row << " " << col;

    return 0;
}
