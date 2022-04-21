/*
Given an array a of n elements, print any value that appears at least three times or print -1 if there is no such value.

Input
The first line contains an integer t (1=t=104) — the number of test cases.

The first line of each test case contains an integer n (1=n=2·105) — the length of the array.

The second line of each test case contains n integers a1,a2,…,an (1=ai=n) — the elements of the array.

It is guaranteed that the sum of n over all test cases does not exceed 2·105.

Output
For each test case, print any value that appears at least three times or print -1 if there is no such value.

Example
inputCopy
7
1
1
3
2 2 2
7
2 2 3 3 4 2 2
8
1 4 3 4 3 2 4 1
9
1 1 1 2 2 2 3 3 3
5
1 5 2 4 3
4
4 4 4 4
outputCopy
-1
2
2
4
3
-1
4
Note
In the first test case there is just a single element, so it can't occur at least three times and the answer is -1.

In the second test case, all three elements of the array are equal to 2, so 2 occurs three times, and so the answer is 2.

For the third test case, 2 occurs four times, so the answer is 2.

For the fourth test case, 4 occurs three times, so the answer is 4.

For the fifth test case, 1, 2 and 3 all occur at least three times, so they are all valid outputs.

For the sixth test case, all elements are distinct, so none of them occurs at least three times and the answer is -1
*/






#include<bits/stdc++.h>
using namespace std;
 
void solve() {
	int n;
	cin >> n;
	
	unordered_map <int, int> mp;
	
	int res = -1;
	
	for (int i = 0; i < n; i++) {
		int ch;
		cin >> ch;
		mp[ch]++;
	}
	
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (it->second >= 3) {
			res = it->first;
			break;
		}
	}
	
	cout << res << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
