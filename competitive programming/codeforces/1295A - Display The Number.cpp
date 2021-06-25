/*
You have a large electronic screen which can display up to 998244353 decimal digits. The digits are displayed in the same way as on different electronic alarm clocks: each place for a digit consists of 7 segments which can be turned on and off to compose different digits. The following picture describes how you can display all 10 decimal digits:



As you can see, different digits may require different number of segments to be turned on. For example, if you want to display 1, you have to turn on 2 segments of the screen, and if you want to display 8, all 7 segments of some place to display a digit should be turned on.

You want to display a really large integer on the screen. Unfortunately, the screen is bugged: no more than n segments can be turned on simultaneously. So now you wonder what is the greatest integer that can be displayed by turning on no more than n segments.

Your program should be able to process t different test cases.

Input
The first line contains one integer t (1=t=100) — the number of test cases in the input.

Then the test cases follow, each of them is represented by a separate line containing one integer n (2=n=105) — the maximum number of segments that can be turned on in the corresponding testcase.

It is guaranteed that the sum of n over all test cases in the input does not exceed 105.

Output
For each test case, print the greatest integer that can be displayed by turning on no more than n segments of the screen. Note that the answer may not fit in the standard 32-bit or 64-bit integral data type.

Example
inputCopy
2
3
4
outputCopy
7
11

*/



#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		
		if (n >= 3 && n % 2) {
			cout << 7;
			n -= 3;
		}
		
		while (n >= 2) {
			cout << 1;
			n -= 2;
		}
		cout << "\n";
	}
		
		
	
	
    return 0;
}
