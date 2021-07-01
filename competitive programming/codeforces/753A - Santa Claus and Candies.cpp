/*
Santa Claus has n candies, he dreams to give them as gifts to children.

What is the maximal number of children for whose he can give candies if Santa Claus want each kid should get distinct positive integer number of candies. Santa Class wants to give all n candies he has.

Input
The only line contains positive integer number n (1?=?n?=?1000) — number of candies Santa Claus has.

Output
Print to the first line integer number k — maximal number of kids which can get candies.

Print to the second line k distinct integer numbers: number of candies for each of k kid. The sum of k printed numbers should be exactly n.

If there are many solutions, print any of them.

Examples
inputCopy
5
outputCopy
2
2 3
inputCopy
9
outputCopy
3
3 5 1
inputCopy
2
outputCopy
1
2 
*/





#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	
	int children = ((int)sqrt(1 + 8 * n) - 1) / 2;
	
	cout << children << "\n";
	
	for (int i = 1; i < children; i++) cout << i << " ";
	cout << n - ((children - 1) * (children)) / 2;
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	//cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
