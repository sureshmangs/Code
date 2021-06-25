/*
Polycarp has n friends, the i-th of his friends has ai candies. Polycarp's friends do not like when they have different numbers of candies. In other words they want all ai to be the same. To solve this, Polycarp performs the following set of actions exactly once:

Polycarp chooses k (0=k=n) arbitrary friends (let's say he chooses friends with indices i1,i2,…,ik);
Polycarp distributes their ai1+ai2+…+aik candies among all n friends. During distribution for each of ai1+ai2+…+aik candies he chooses new owner. That can be any of n friends. Note, that any candy can be given to the person, who has owned that candy before the distribution process.
Note that the number k is not fixed in advance and can be arbitrary. Your task is to find the minimum value of k.

For example, if n=4 and a=[4,5,2,5], then Polycarp could make the following distribution of the candies:

Polycarp chooses k=2 friends with indices i=[2,4] and distributes a2+a4=10 candies to make a=[4,4,4,4] (two candies go to person 3).
Note that in this example Polycarp cannot choose k=1 friend so that he can redistribute candies so that in the end all ai are equal.

For the data n and a, determine the minimum value k. With this value k, Polycarp should be able to select k friends and redistribute their candies so that everyone will end up with the same number of candies.

Input
The first line contains one integer t (1=t=104). Then t test cases follow.

The first line of each test case contains one integer n (1=n=2·105).

The second line contains n integers a1,a2,…,an (0=ai=104).

It is guaranteed that the sum of n over all test cases does not exceed 2·105.

Output
For each test case output:

the minimum value of k, such that Polycarp can choose exactly k friends so that he can redistribute the candies in the desired way;
"-1" if no such value k exists.
Example
inputCopy
5
4
4 5 2 5
2
0 4
5
10 8 5 1 4
1
10000
7
1 1 1 1 1 1 1
outputCopy
2
1
-1
0
0
*/





#include<bits/stdc++.h>
using namespace std;
 
void solve() {
	int n;
	cin >> n;
	
	vector <int> v(n);
	
	for (auto &x: v) cin >> x;
	
	long long sum = 0;
	
	for (auto &x: v) sum += x;
	
	if (sum % n != 0) {
		cout << -1 << "\n";
		return;
	}
	
	long long avg = sum / n;
	
	int k = 0;
	
	for (auto &x: v) {
		if (x > avg) k++;
	}
 
	cout << k << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
