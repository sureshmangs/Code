/*
The easiest problem of the lot !

You are provided with coins of denominations "a" and "b". You are required to find the least value of n, such that all currency values greater than or equal to n can be made using any number of coins of denomination "a" and "b" and in any order. If no such number exists, print "-1" in that case.

Input Constraints:
1 <= t <= 106
1 <= a <= 109
1 <= b <= 109
Input Format:
The first line contains t, the number of test cases.

Each of the next t lines contains 2 integers a & b, as specified in the question.

Output Format:
For each test case, print the required answer

Example
Input:
1 
4 7
6 1
2 4

Output:
18
0
-1
NOTE:Prefer fast input/output methods
*/




#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while (t--) {
		long long a, b;
		cin >> a >> b;
		
		int g = __gcd(a, b);
		
		if (g > 1) cout << -1 << "\n";
		else cout << a * b - a - b + 1 << "\n"; // using chicken mcnugget theorem
	}
	
    return 0;
}
