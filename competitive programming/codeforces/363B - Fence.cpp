/*
There is a fence in front of Polycarpus's home. The fence consists of n planks of the same width which go one after another from left to right. The height of the i-th plank is hi meters, distinct planks can have distinct heights.

Fence for n?=?7 and h?=?[1,?2,?6,?1,?1,?7,?1]
Polycarpus has bought a posh piano and is thinking about how to get it into the house. In order to carry out his plan, he needs to take exactly k consecutive planks from the fence. Higher planks are harder to tear off the fence, so Polycarpus wants to find such k consecutive planks that the sum of their heights is minimal possible.

Write the program that finds the indexes of k consecutive planks with minimal total height. Pay attention, the fence is not around Polycarpus's home, it is in front of home (in other words, the fence isn't cyclic).

Input
The first line of the input contains integers n and k (1?=?n?=?1.5·105,?1?=?k?=?n) — the number of planks in the fence and the width of the hole for the piano. The second line contains the sequence of integers h1,?h2,?...,?hn (1?=?hi?=?100), where hi is the height of the i-th plank of the fence.

Output
Print such integer j that the sum of the heights of planks j, j?+?1, ..., j?+?k?-?1 is the minimum possible. If there are multiple such j's, print any of them.

Examples
inputCopy
7 3
1 2 6 1 1 7 1
outputCopy
3
Note
In the sample, your task is to find three consecutive planks with the minimum sum of heights. In the given case three planks with indexes 3, 4 and 5 have the required attribute, their total height is 8.
*/






#include<bits/stdc++.h>
using namespace std;

#define MAX 100001
 
void solve() {
	int n, k;
	cin >> n >> k;
	
	vector <int> v(n);
	for (auto &x: v) cin >> x;
	
	int start = 0, end = 0, index;
	long long sum = 0, mini = INT_MAX;
	
	while (end < n) {
		sum += v[end];
		if (end - start + 1 == k) { // window size reached
			if (sum < mini) {
				mini = sum;
				index = start;
			}
			sum -= v[start];
			start++; // move the window
		}
		end++;
	}
	
	cout << index + 1;
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	//cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
