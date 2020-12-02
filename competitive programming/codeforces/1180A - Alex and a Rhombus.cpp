/*
While playing with geometric figures Alex has accidentally invented a concept of a n-th order rhombus in a cell grid.

A 1-st order rhombus is just a square 1×1 (i.e just a cell).

A n-th order rhombus for all n≥2 one obtains from a n−1-th order rhombus adding all cells which have a common side with it to it (look at the picture to understand it better).


Alex asks you to compute the number of cells in a n-th order rhombus.

Input
The first and only input line contains integer n (1≤n≤100) — order of a rhombus whose numbers of cells should be computed.

Output
Print exactly one integer — the number of cells in a n-th order rhombus.

Examples
inputCopy
1
outputCopy
1
inputCopy
2
outputCopy
5
inputCopy
3
outputCopy
13
Note
Images of rhombus corresponding to the examples are given in the statement.


*/




#include<bits/stdc++.h>
using namespace std;

int solve(int n){
    if(n == 1) return 1;
    return solve(n-1) + 4 * (n - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << solve(n);

    return 0;
}
