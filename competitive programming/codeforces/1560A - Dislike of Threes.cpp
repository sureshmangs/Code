/*
Polycarp doesn't like integers that are divisible by 3 or end with the digit 3 in their decimal representation. Integers that meet both conditions are disliked by Polycarp, too.

Polycarp starts to write out the positive (greater than 0) integers which he likes: 1,2,4,5,7,8,10,11,14,16,…. Output the k-th element of this sequence (the elements are numbered from 1).

Input
The first line contains one integer t (1=t=100) — the number of test cases. Then t test cases follow.

Each test case consists of one line containing one integer k (1=k=1000).

Output
For each test case, output in a separate line one integer x — the k-th element of the sequence that was written out by Polycarp.

Example
inputCopy
10
1
2
3
4
5
6
7
8
9
1000
outputCopy
1
2
4
5
7
8
10
11
14
1666

*/





#include<bits/stdc++.h>
using namespace std;
 
vector <int> v;
 
void solve() {
	int k;
	cin >> k;
	
	cout << v[k - 1] << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	for (int i = 1; i <= 10000; i++) {
		if (i % 3 == 0 ||  i % 10 == 3) continue;
		v.push_back(i);
	}
	
	while (t--)  solve();
	
    return 0;
}
