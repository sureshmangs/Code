/*
The tycoon of a winery empire in Mondstadt, unmatched in every possible way. A thinker in the Knights of Favonius with an exotic appearance.

This time, the brothers are dealing with a strange piece of wood marked with their names. This plank of wood can be represented as a string of n characters. Each character is either a 'D' or a 'K'. You want to make some number of cuts (possibly 0) on this string, partitioning it into several contiguous pieces, each with length at least 1. Both brothers act with dignity, so they want to split the wood as evenly as possible. They want to know the maximum number of pieces you can split the wood into such that the ratios of the number of occurrences of 'D' to the number of occurrences of 'K' in each chunk are the same.

Kaeya, the curious thinker, is interested in the solution for multiple scenarios. He wants to know the answer for every prefix of the given string. Help him to solve this problem!

For a string we define a ratio as a:b where 'D' appears in it a times, and 'K' appears b times. Note that a or b can equal 0, but not both. Ratios a:b and c:d are considered equal if and only if a·d=b·c.

For example, for the string 'DDD' the ratio will be 3:0, for 'DKD' — 2:1, for 'DKK' — 1:2, and for 'KKKKDD' — 2:4. Note that the ratios of the latter two strings are equal to each other, but they are not equal to the ratios of the first two strings.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1=t=1000). Description of the test cases follows.

The first line of each test case contains an integer n (1=n=5·105) — the length of the wood.

The second line of each test case contains a string s of length n. Every character of s will be either 'D' or 'K'.

It is guaranteed that the sum of n over all test cases does not exceed 5·105.

Output
For each test case, output n space separated integers. The i-th of these numbers should equal the answer for the prefix s1,s2,…,si.

Example
inputCopy
5
3
DDK
6
DDDDDD
4
DKDK
1
D
9
DKDKDDDDK
outputCopy
1 2 1 
1 2 3 4 5 6 
1 1 1 2 
1 
1 1 1 2 1 2 1 1 3 
Note
For the first test case, there is no way to partition 'D' or 'DDK' into more than one block with equal ratios of numbers of 'D' and 'K', while you can split 'DD' into 'D' and 'D'.

For the second test case, you can split each prefix of length i into i blocks 'D'
*/


#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	map <pair<int, int>, int> mp;
	
	int cd = 0, ck = 0;
	
	for (auto &x: s) {
		if (x == 'D') cd++;
		else ck++;
		
		int gcd = __gcd(cd, ck);
		
		int a = cd / gcd;
		int b = ck / gcd;
		
		cout << mp[{a, b}] + 1 << " ";
		mp[{a, b}]++;
	}
	
	cout << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
