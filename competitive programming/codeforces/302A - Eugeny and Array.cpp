/*
Eugeny has array a?=?a1,?a2,?...,?an, consisting of n integers. Each integer ai equals to -1, or to 1. Also, he has m queries:

Query number i is given as a pair of integers li, ri (1?=?li?=?ri?=?n).
The response to the query will be integer 1, if the elements of array a can be rearranged so as the sum ali?+?ali?+?1?+?...?+?ari?=?0, otherwise the response to the query will be integer 0.
Help Eugeny, answer all his queries.

Input
The first line contains integers n and m (1?=?n,?m?=?2·105). The second line contains n integers a1,?a2,?...,?an (ai?=?-1,?1). Next m lines contain Eugene's queries. The i-th line contains integers li,?ri (1?=?li?=?ri?=?n).

Output
Print m integers — the responses to Eugene's queries in the order they occur in the input.

Examples
inputCopy
2 3
1 -1
1 1
1 2
2 2
outputCopy
0
1
0
inputCopy
5 5
-1 1 1 1 -1
1 1
2 3
3 5
2 5
1 5
outputCopy
0
1
0
1
0

*/




#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n, m;
	cin >> n >> m;
	
	int pos = 0, neg = 0;
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1) pos++;
		else neg++;
	}
	
	while (m--) {
		int l, r;
		cin >> l >> r;
		
		int slots = r - l + 1;
		
		if (slots % 2 == 0 && pos >= slots / 2 && neg >= slots / 2) cout << 1 << "\n";
		else cout << 0 << "\n";
		
	}
	
    
    return 0;
}
