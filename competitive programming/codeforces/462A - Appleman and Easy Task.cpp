/*
Toastman came up with a very easy task. He gives it to Appleman, but Appleman doesn't know how to solve it. Can you help him?

Given a n?×?n checkerboard. Each cell of the board has either character 'x', or character 'o'. Is it true that each cell of the board has even number of adjacent cells with 'o'? Two cells of the board are adjacent if they share a side.

Input
The first line contains an integer n (1?=?n?=?100). Then n lines follow containing the description of the checkerboard. Each of them contains n characters (either 'x' or 'o') without spaces.

Output
Print "YES" or "NO" (without the quotes) depending on the answer to the problem.

Examples
inputCopy
3
xxo
xox
oxx
outputCopy
YES
inputCopy
4
xxxo
xoxo
oxox
xxxx
outputCopy
NO

*/



#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, int n) {
	return (i >= 0 && i < n && j >=0 && j < n);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    char a[n][n];
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		cin >> a[i][j];
		}
	}
	
	bool flag = true;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cnt = 0;
			
			
			
			if(isSafe(i - 1, j, n) && a[i - 1][j]=='o') cnt++;
			if(isSafe(i, j + 1, n) && a[i][j + 1]=='o') cnt++;
			if(isSafe(i, j - 1, n) && a[i][j - 1]=='o') cnt++;
			if(isSafe(i + 1, j, n) && a[i + 1][j]=='o') cnt++;
			
			if (cnt % 2 != 0) {
			flag = false;
			break;
		}
		}
		 
	}
	
	if (flag) cout << "YES";
	else cout << "NO";


    return 0;
}
