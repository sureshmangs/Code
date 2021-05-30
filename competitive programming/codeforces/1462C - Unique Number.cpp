/*
You are given a positive number x. Find the smallest positive integer number that has the sum of digits equal to x and all digits are distinct (unique).

Input
The first line contains a single positive integer t (1=t=50) — the number of test cases in the test. Then t test cases follow.

Each test case consists of a single integer number x (1=x=50).

Output
Output t answers to the test cases:

if a positive integer number with the sum of digits equal to x and all digits are different exists, print the smallest such number;
otherwise print -1.
Example
inputCopy
4
1
5
15
50
outputCopy
1
5
69
-1

*/




#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while (t--) {
		int x;
		cin >> x;
		
		if (x > 45) {
			cout << -1 << "\n";
		} else {
			string res = "";
			vector <bool> used(10, false);
					
			for (int i = 9; i >= 1; i--) {
				if (used[i] == false && x >= i) {
					used[i] = true;
					res = to_string(i) + res;
					x -= i;
				}
			}
			
			cout << res << "\n";
		}
	}
	
    return 0;
}

