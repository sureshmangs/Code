/*
You are given a rectangular cake, represented as an r?×?c grid. Each cell either has an evil strawberry, or is empty. For example, a 3?×?4 cake may look as follows:


The cakeminator is going to eat the cake! Each time he eats, he chooses a row or a column that does not contain any evil strawberries and contains at least one cake cell that has not been eaten before, and eats all the cake cells there. He may decide to eat any number of times.

Please output the maximum number of cake cells that the cakeminator can eat.

Input
The first line contains two integers r and c (2?=?r,?c?=?10), denoting the number of rows and the number of columns of the cake. The next r lines each contains c characters — the j-th character of the i-th line denotes the content of the cell at row i and column j, and is either one of these:

'.' character denotes a cake cell with no evil strawberry;
'S' character denotes a cake cell with an evil strawberry.
Output
Output the maximum number of cake cells that the cakeminator can eat.

Examples
inputCopy
3 4
S...
....
..S.
outputCopy
8
Note
For the first example, one possible way to eat the maximum number of cake cells is as follows (perform 3 eats).*/



#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m, n;
    cin >> m >> n;
    
    char a[m][n];
    
    for (int i = 0; i < m; i++) {
    	for (int j = 0; j < n; j++) {
    		cin >> a[i][j];
		}
	}
	
	int rc = 0, cc = 0;
	
	for (int i = 0; i < m; i++) {
		bool evil = false;
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 'S') {
				evil = true;
				break;
			}
		}
		if (!evil) rc++;
 	}
 	
 	for (int j = 0; j < n; j++) {
		bool evil = false;
		for (int i = 0; i < m; i++) {
			if (a[i][j] == 'S') {
				evil = true;
				break;
			}
		}
		if (!evil) cc++;
 	}
 	
 	cout << rc * n + cc * m - rc * cc;


    return 0;
}
