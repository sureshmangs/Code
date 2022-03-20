Alice has a cake, and she is going to cut it. She will perform the following operation n-1 times: choose a piece of the cake (initially, the cake is all one piece) with weight w=2 and cut it into two smaller pieces of weight ?w2? and ?w2? (?x? and ?x? denote floor and ceiling functions, respectively).

After cutting the cake in n pieces, she will line up these n pieces on a table in an arbitrary order. Let ai be the weight of the i-th piece in the line.

You are given the array a. Determine whether there exists an initial weight and sequence of operations which results in a.

Input
The first line contains a single integer t (1=t=104) — the number of test cases.

The first line of each test case contains a single integer n (1=n=2·105).

The second line of each test case contains n integers a1,a2,…,an (1=ai=109).

It is guaranteed that the sum of n for all test cases does not exceed 2·105.

Output
For each test case, print a single line: print YES if the array a could have resulted from Alice's operations, otherwise print NO.

You may print each letter in any case (for example, YES, Yes, yes, yEs will all be recognized as positive answer).

Example
inputCopy
14
1
327
2
869 541
2
985214736 985214737
3
2 3 1
3
2 3 3
6
1 1 1 1 1 1
6
100 100 100 100 100 100
8
100 100 100 100 100 100 100 100
8
2 16 1 8 64 1 4 32
10
1 2 4 7 1 1 1 1 7 2
10
7 1 1 1 3 1 3 3 2 3
10
1 4 4 1 1 1 3 3 3 1
10
2 3 2 2 1 2 2 2 2 2
4
999999999 999999999 999999999 999999999
outputCopy
YES
NO
YES
YES
NO
YES
NO
YES
YES
YES
YES
NO
NO
YES
Note
In the first test case, it's possible to get the array a by performing 0 operations on a cake with weight 327.

In the second test case, it's not possible to get the array a.

In the third test case, it's possible to get the array a by performing 1 operation on a cake with weight 1970429473:

Cut it in half, so that the weights are [985214736,985214737].
Note that the starting weight can be greater than 109.
In the fourth test case, it's possible to get the array a by performing 2 operations on a cake with weight 6:

Cut it in half, so that the weights are [3,3].
Cut one of the two pieces with weight 3, so that the new weights are [1,2,3] which is equivalent to [2,3,1] up to reordering.








#include<bits/stdc++.h>
using namespace std;
 
void solve() { 	
	int n;
	cin >> n;
 
	vector <int> v(n);
	
	for (auto &x: v) cin >> x;
	
	if (n == 1) {
		cout << "YES\n"; return;
	}
	
	multiset<int, greater<long long> > s;
	
	for (auto &x: v) s.insert(x);
	
	long long sum = 0;
	
	for (auto &x: v) sum += x;
	
 
	
	queue <long long> q;
	q.push(sum);
	
	while (!s.empty() && !q.empty()) {
		sum = q.front();
		q.pop();
		long long a = floor(sum / 2.0);
		long long b = ceil(sum / 2.0);
		
		if (s.find(a) != s.end()) s.erase(s.find(a));
		else q.push(a);
		
		if (s.find(b) != s.end()) s.erase(s.find(b));
		else q.push(b);
		
		if (q.size() > s.size()) break;
	
	}
	
	if (s.empty() && q.empty()) cout << "YES\n";
	else cout << "NO\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
