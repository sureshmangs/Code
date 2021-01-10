/*
Dreamoon wants to climb up a stair of n steps. He can climb 1 or 2 steps at each move. Dreamoon wants the number of moves to be a multiple of an integer m.

What is the minimal number of moves making him climb to the top of the stairs that satisfies his condition?

Input
The single line contains two space separated integers n, m (0?<?n?=?10000,?1?<?m?=?10).

Output
Print a single integer — the minimal number of moves being a multiple of m. If there is no way he can climb satisfying condition print ?-?1 instead.

Examples
inputCopy
10 2
outputCopy
6
inputCopy
3 5
outputCopy
-1
Note
For the first sample, Dreamoon could climb in 6 moves with following sequence of steps: {2, 2, 2, 2, 1, 1}.

For the second sample, there are only three valid sequence of steps {2, 1}, {1, 2}, {1, 1, 1} with 2, 2, and 3 steps respectively. All these numbers are not multiples of 5.
*/



#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	bool flag = false;
	
	for (int y = 0; y <= n; y++) {
		for (int x = 0; x <= n / 2; x++) {
			if(2 * x + y == n && (x + y) % m == 0) {
				cout << x + y;
				flag = true;
				break;
			}
		}
		if(flag) break;
	}
	
	if(!flag) cout << -1;

    return 0;
}
