/*
There are n digital panels placed in a straight line. Each panel can show any digit from 0 to 9. Initially, all panels show 0.

Every second, the digit shown by each panel increases by 1. In other words, at the end of every second, a panel that showed 9 would now show 0, a panel that showed 0 would now show 1, a panel that showed 1 would now show 2, and so on.

When a panel is paused, the digit displayed on the panel does not change in the subsequent seconds.

You must pause exactly one of these panels, at any second you wish. Then, the panels adjacent to it get paused one second later, the panels adjacent to those get paused 2 seconds later, and so on. In other words, if you pause panel x, panel y (for all valid y) would be paused exactly |x-y| seconds later.

For example, suppose there are 4 panels, and the 3-rd panel is paused when the digit 9 is on it.

The panel 1 pauses 2 seconds later, so it has the digit 1;
the panel 2 pauses 1 second later, so it has the digit 0;
the panel 4 pauses 1 second later, so it has the digit 0.
The resulting 4-digit number is 1090. Note that this example is not optimal for n=4.

Once all panels have been paused, you write the digits displayed on them from left to right, to form an n digit number (it can consist of leading zeros). What is the largest possible number you can get? Initially, all panels show 0.

Input
The first line of the input contains a single integer t (1=t=100) — the number of test cases. Each test case consists of a single line containing a single integer n (1=n=2·105).

It is guaranteed that the sum of n over all test cases does not exceed 2·105.

Output
For each test case, print the largest number you can achieve, if you pause one panel optimally.

Example
inputCopy
2
1
2
outputCopy
9
98
Note
In the first test case, it is optimal to pause the first panel when the number 9 is displayed on it.

In the second test case, it is optimal to pause the second panel when the number 8 is displayed on it.


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
 		string res = "";
 		
 		if (n >= 1) res += "9";
 		if (n >= 2) res += "8";
 		
 		int start = 9;
 		
 		for (int i = 3; i <= n; i++) {
 			res += start + '0';
 			start++;
 			start %= 10;
		 }
		 
		 cout << res << endl;
	 }


    return 0;
}

