/*
You are given an integer n. In one move, you can either multiply n by two or divide n by 6 (if it is divisible by 6 without the remainder).

Your task is to find the minimum number of moves needed to obtain 1 from n or determine if it's impossible to do that.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1=t=2·104) — the number of test cases. Then t test cases follow.

The only line of the test case contains one integer n (1=n=109).

Output
For each test case, print the answer — the minimum number of moves needed to obtain 1 from n if it's possible to do that or -1 if it's impossible to obtain 1 from n.

Example
inputCopy
7
1
2
3
12
12345
15116544
387420489
outputCopy
0
-1
2
-1
-1
12
36
Note
Consider the sixth test case of the example. The answer can be obtained by the following sequence of moves from the given integer 15116544:

Divide by 6 and get 2519424;
divide by 6 and get 419904;
divide by 6 and get 69984;
divide by 6 and get 11664;
multiply by 2 and get 23328;
divide by 6 and get 3888;
divide by 6 and get 648;
divide by 6 and get 108;
multiply by 2 and get 216;
divide by 6 and get 36;
divide by 6 and get 6;
divide by 6 and get 1.
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
		
		int res = 0;
		bool flag = true;
		
		while(n != 1) {
			if (n % 6 == 0) {
				n /= 6;
			} else {
				n *= 2;
				if (n % 6 != 0) {
					flag = false; break;
				}
			}
			res++;
		}
		
		flag ? cout << res : cout << -1;
		cout << endl;
	}
   
    return 0;
}


/*
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
		
		int cnt2 = 0, cnt3 = 0;
		
		while(n % 2 == 0) {
			cnt2++; 
			n /= 2;
		}
		
		while (n % 3 == 0) {
			cnt3++;
			n /= 3;
		}
		
		if (n != 1 || cnt2 > cnt3) {
			cout << -1 << endl;
			continue;
		} else {
			cout << (cnt3 - cnt2) + cnt3<< endl;
		}
		
	}
   
    return 0;
}
*/
