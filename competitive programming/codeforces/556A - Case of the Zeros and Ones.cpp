/*
Andrewid the Android is a galaxy-famous detective. In his free time he likes to think about strings containing zeros and ones.

Once he thought about a string of length n consisting of zeroes and ones. Consider the following operation: we choose any two adjacent positions in the string, and if one them contains 0, and the other contains 1, then we are allowed to remove these two digits from the string, obtaining a string of length n?-?2 as a result.

Now Andreid thinks about what is the minimum length of the string that can remain after applying the described operation several times (possibly, zero)? Help him to calculate this number.

Input
First line of the input contains a single integer n (1?=?n?=?2·105), the length of the string that Andreid has.

The second line contains the string of length n consisting only from zeros and ones.

Output
Output the minimum length of the string that may remain after applying the described operations several times.

Examples
inputCopy
4
1100
outputCopy
0
inputCopy
5
01010
outputCopy
1
inputCopy
8
11101111
outputCopy
6
*/




/*
#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int cnt = 0;
	
	for (auto &x: s) {
		if (x == '0') cnt++;
	}
	
	cout << n - 2 * min(cnt, n - cnt);
 
	
    return 0;
}
*/



#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int cnt = 0;
	
	for (auto &x: s) {
		if (x == '0') cnt++;
	}
	
	cout << n - 2 * min(cnt, n - cnt);

	
    return 0;
}
