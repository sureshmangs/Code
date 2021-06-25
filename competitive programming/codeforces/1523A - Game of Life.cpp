/*
William really likes the cellular automaton called "Game of Life" so he decided to make his own version. For simplicity, William decided to define his cellular automaton on an array containing n cells, with each cell either being alive or dead.

Evolution of the array in William's cellular automaton occurs iteratively in the following way:

If the element is dead and it has exactly 1 alive neighbor in the current state of the array, then on the next iteration it will become alive. For an element at index i the neighbors would be elements with indices i-1 and i+1. If there is no element at that index, it is considered to be a dead neighbor.
William is a humane person so all alive elements stay alive.
Check the note section for examples of the evolution.

You are given some initial state of all elements and you need to help William find the state of the array after m iterations of evolution.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1=t=103). Description of the test cases follows.

The first line of each test case contains two integers n and m (2=n=103,1=m=109), which are the total number of cells in the array and the number of iterations.

The second line of each test case contains a string of length n made up of characters "0" and "1" and defines the initial state of the array. "1" means a cell is alive and "0" means it is dead.

It is guaranteed that the sum of n over all test cases does not exceed 104.

Output
In each test case output a string of length n, made up of characters "0" and "1"  — the state of the array after m iterations of evolution.

Example
inputCopy
4
11 3
01000000001
10 2
0110100101
5 2
10101
3 100
000
outputCopy
11111001111
1110111101
10101
000
Note
Sequence of iterations of evolution for the first test case

01000000001  — initial state
11100000011  — first iteration of evolution
11110000111  — second iteration of evolution
11111001111  — third iteration of evolution
Sequence of iterations of evolution for the second test case

0110100101  — initial state
1110111101  — first iteration of evolution
1110111101  — second iteration of evolution
*/




#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while (t--) {
		int n, m;
		cin >> n >> m;
		
		string v;
		cin >> v;
		
		int ones = count(v.begin(), v.end(), '1');
		
		while (m) {
			int prevOne = ones;
			string tmp = v;
			if (v[0] == '0' && v[1] == '1') {
				tmp[0] = '1';
				ones++;
			}
			if (v[n - 1] == '0' && v[n - 2] == '1') {
				tmp[n - 1] = '1';
				ones++;
			}
			for (int i = 1; i < n; i++) {
				if (v[i] == '0' && v[i - 1] == '1' && v[i + 1] == '0') {
					tmp[i] = '1';
					ones++;
				} else if (v[i] == '0' && v[i - 1] == '0' && v[i + 1] == '1') {
					tmp[i] = '1';
					ones++;
				}
			}
			if (prevOne == ones) break;
			
			m--;
			v = tmp;
		}
		
		for (auto &x: v) cout << x;
		cout << "\n";
	}
	
    return 0;
}
