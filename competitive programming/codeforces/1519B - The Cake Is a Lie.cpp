/*
There is a n×m grid. You are standing at cell (1,1) and your goal is to finish at cell (n,m).

You can move to the neighboring cells to the right or down. In other words, suppose you are standing at cell (x,y). You can:

move right to the cell (x,y+1) — it costs x burles;
move down to the cell (x+1,y) — it costs y burles.
Can you reach cell (n,m) spending exactly k burles?

Input
The first line contains the single integer t (1=t=100) — the number of test cases.

The first and only line of each test case contains three integers n, m, and k (1=n,m=100; 0=k=104) — the sizes of grid and the exact amount of money you need to spend.

Output
For each test case, if you can reach cell (n,m) spending exactly k burles, print YES. Otherwise, print NO.

You may print every letter in any case you want (so, for example, the strings yEs, yes, Yes and YES are all recognized as positive answer).

Example
inputCopy
6
1 1 0
2 2 2
2 2 3
2 2 4
1 4 3
100 100 10000
outputCopy
YES
NO
YES
NO
YES
NO
Note
In the first test case, you are already in the final cell, so you spend 0 burles.

In the second, third and fourth test cases, there are two paths from (1,1) to (2,2): (1,1) ? (1,2) ? (2,2) or (1,1) ? (2,1) ? (2,2). Both costs 1+2=3 burles, so it's the only amount of money you can spend.

In the fifth test case, there is the only way from (1,1) to (1,4) and it costs 1+1+1=3 burles.
*/


#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
    	int n, m, k;
    	cin >> n >> m >> k;
    	
    	int rd = 1 * (m - 1) + (n - 1) * m;
    	int dr = 1 * (n - 1) + (m - 1) * n;
    	
    	if (k == rd || k == dr) cout << "YES\n";
    	else cout << "NO\n";
	}
  	
    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
    	int n, m, k;
    	cin >> n >> m >> k;
    	
    	n * m - 1 == k ? cout << "YES\n" : cout << "NO\n";
	}
  	
    return 0;
}
*/
