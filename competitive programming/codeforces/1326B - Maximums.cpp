/*
Alicia has an array, a1,a2,…,an, of non-negative integers. For each 1=i=n, she has found a non-negative integer xi=max(0,a1,…,ai-1). Note that for i=1, xi=0.

For example, if Alicia had the array a={0,1,2,0,3}, then x={0,0,1,2,2}.

Then, she calculated an array, b1,b2,…,bn: bi=ai-xi.

For example, if Alicia had the array a={0,1,2,0,3}, b={0-0,1-0,2-1,0-2,3-2}={0,1,1,-2,1}.

Alicia gives you the values b1,b2,…,bn and asks you to restore the values a1,a2,…,an. Can you help her solve the problem?

Input
The first line contains one integer n (3=n=200000) – the number of elements in Alicia's array.

The next line contains n integers, b1,b2,…,bn (-109=bi=109).

It is guaranteed that for the given array b there is a solution a1,a2,…,an, for all elements of which the following is true: 0=ai=109.

Output
Print n integers, a1,a2,…,an (0=ai=109), such that if you calculate x according to the statement, b1 will be equal to a1-x1, b2 will be equal to a2-x2, ..., and bn will be equal to an-xn.

It is guaranteed that there exists at least one solution for the given tests. It can be shown that the solution is unique.

Examples
inputCopy
5
0 1 1 -2 1
outputCopy
0 1 2 0 3 
inputCopy
3
1000 999999000 -1000000000
outputCopy
1000 1000000000 0 
inputCopy
5
2 1 2 2 3
outputCopy
2 3 5 7 10 
Note
The first test was described in the problem statement.

In the second test, if Alicia had an array a={1000,1000000000,0}, then x={0,1000,1000000000} and b={1000-0,1000000000-1000,0-1000000000}={1000,999999000,-1000000000}.
*/




#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector <int> v(n);
	
	for (auto &x: v) cin >> x;
	
	long long maxi = v[0];
	
	cout << v[0] << " "; // first element will remain same
	
	for (int i = 1; i < n; i++) {
		long long next = maxi + v[i];
		cout << next << " ";
		maxi = max(maxi,  next);
	}
	
    return 0;
}
