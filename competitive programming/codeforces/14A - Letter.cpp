/*
A boy Bob likes to draw. Not long ago he bought a rectangular graph (checked) sheet with n rows and m columns. Bob shaded some of the squares on the sheet. Having seen his masterpiece, he decided to share it with his elder brother, who lives in Flatland. Now Bob has to send his picture by post, but because of the world economic crisis and high oil prices, he wants to send his creation, but to spend as little money as possible. For each sent square of paper (no matter whether it is shaded or not) Bob has to pay 3.14 burles. Please, help Bob cut out of his masterpiece a rectangle of the minimum cost, that will contain all the shaded squares. The rectangle's sides should be parallel to the sheet's sides.

Input
The first line of the input data contains numbers n and m (1?=?n,?m?=?50), n — amount of lines, and m — amount of columns on Bob's sheet. The following n lines contain m characters each. Character «.» stands for a non-shaded square on the sheet, and «*» — for a shaded square. It is guaranteed that Bob has shaded at least one square.

Output
Output the required rectangle of the minimum cost. Study the output data in the sample tests to understand the output format better.

Examples
inputCopy
6 7
.......
..***..
..*....
..***..
..*....
..***..
outputCopy
***
*..
***
*..
***
inputCopy
3 3
***
*.*
***
outputCopy
***
*.*
***
*/


#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
  	int n, m;
  	cin >> n >> m;
  	
  	char a[n][m];
  	
  	for (int i  = 0; i < n; i++) {
  		for (int j = 0; j < m; j++) {
  			cin >> a[i][j];
		}
	}
	
	int imin = INT_MAX, jmin = INT_MAX, imax = INT_MIN, jmax = INT_MIN;
	
	for (int i  = 0; i < n; i++) {
  		for (int j = 0; j < m; j++) {
  			if (a[i][j] == '*') {
  				imin = min(imin, i);
  				imax = max(imax, i);
  				jmin = min(jmin, j);
  				jmax = max(jmax, j);
			} 
		}
	}
	
	for (int i = imin; i <= imax; i++) {
		for (int j = jmin; j <= jmax; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
	
	
    
    return 0;
}
