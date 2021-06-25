/*
Three friends are going to meet each other. Initially, the first friend stays at the position x=a, the second friend stays at the position x=b and the third friend stays at the position x=c on the coordinate axis Ox.

In one minute each friend independently from other friends can change the position x by 1 to the left or by 1 to the right (i.e. set x:=x-1 or x:=x+1) or even don't change it.

Let's introduce the total pairwise distance — the sum of distances between each pair of friends. Let a', b' and c' be the final positions of the first, the second and the third friend, correspondingly. Then the total pairwise distance is |a'-b'|+|a'-c'|+|b'-c'|, where |x| is the absolute value of x.

Friends are interested in the minimum total pairwise distance they can reach if they will move optimally. Each friend will move no more than once. So, more formally, they want to know the minimum total pairwise distance they can reach after one minute.

You have to answer q independent test cases.

Input
The first line of the input contains one integer q (1=q=1000) — the number of test cases.

The next q lines describe test cases. The i-th test case is given as three integers a,b and c (1=a,b,c=109) — initial positions of the first, second and third friend correspondingly. The positions of friends can be equal.

Output
For each test case print the answer on it — the minimum total pairwise distance (the minimum sum of distances between each pair of friends) if friends change their positions optimally. Each friend will move no more than once. So, more formally, you have to find the minimum total pairwise distance they can reach after one minute.

Example
inputCopy
8
3 3 4
10 20 30
5 5 5
2 4 3
1 1000000000 1000000000
1 1000000000 999999999
3 2 5
3 2 6
outputCopy
0
36
0
0
1999999994
1999999994
2
4

*/




#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n = 3;
	
	vector <int> v(n);
	
	for (auto &x: v) cin >> x;
	
	sort(v.begin(), v.end());
	
	long long res = 0;
	
	if (v[0] == v[2]) res = 0;
	else if (v[0] == v[1]) {
		v[0] += 1;
		v[1] += 1;
		if (v[0] == v[2]) res = 0;
		else {
			v[2] -= 1;
			res = abs(v[0] - v[1]) + abs(v[0] - v[2]) + abs(v[1] - v[2]);
		}
	} else if (v[1] == v[2]) {
		v[1] -= 1;
		v[2] -= 1;
		if (v[0] == v[2]) res = 0;
		else {
			v[0] += 1;
			res = abs(v[0] - v[1]) + abs(v[0] - v[2]) + abs(v[1] - v[2]);
		}	
	} else {
		v[0] += 1;
		v[2] -= 1;
		res = abs(v[0] - v[1]) + abs(v[0] - v[2]) + abs(v[1] - v[2]);
	}
	
	cout << res << "\n";
	
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
