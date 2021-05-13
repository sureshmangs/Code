/*
Polycarpus adores TV series. Right now he is ready to finish watching a season of a popular sitcom "Graph Theory". In total, the season has n episodes, numbered with integers from 1 to n.

Polycarpus watches episodes not one by one but in a random order. He has already watched all the episodes except for one. Which episode has Polycaprus forgotten to watch?

Input
The first line of the input contains integer n (2?=?n?=?100000) — the number of episodes in a season. Assume that the episodes are numbered by integers from 1 to n.

The second line contains n?-?1 integer a1,?a2,?...,?an (1?=?ai?=?n) — the numbers of episodes that Polycarpus has watched. All values of ai are distinct.

Output
Print the number of the episode that Polycarpus hasn't watched.

Examples
inputCopy
10
3 8 10 1 7 9 6 5 2
outputCopy
4

*/



#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int res = 0;
    
    for (int i = 0; i < n - 1; i++) {
    	int a;
    	cin >> a;
    	res ^= a;
	}
	
	for (int i = 1; i <= n; i++) res ^= i;
	
	cout << res;

    return 0;
}
