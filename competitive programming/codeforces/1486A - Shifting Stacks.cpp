/*
You have n stacks of blocks. The i-th stack contains hi blocks and it's height is the number of blocks in it. In one move you can take a block from the i-th stack (if there is at least one block) and put it to the i+1-th stack. Can you make the sequence of heights strictly increasing?

Note that the number of stacks always remains n: stacks don't disappear when they have 0 blocks.

Input
First line contains a single integer t (1=t=104) — the number of test cases.

The first line of each test case contains a single integer n (1=n=100). The second line of each test case contains n integers hi (0=hi=109) — starting heights of the stacks.

It's guaranteed that the sum of all n does not exceed 104.

Output
For each test case output YES if you can make the sequence of heights strictly increasing and NO otherwise.

You may print each letter in any case (for example, YES, Yes, yes, yEs will all be recognized as positive answer).

Example
inputCopy
6
2
1 2
2
1 0
3
4 4 4
2
0 0
3
0 1 0
4
1000000000 1000000000 1000000000 1000000000
outputCopy
YES
YES
YES
NO
NO
YES
Note
In the first test case there is no need to make any moves, the sequence of heights is already increasing.

In the second test case we need to move one block from the first stack to the second. Then the heights become 0 1.

In the third test case we could move one block from the first stack to the second and then from the second to the third, which would make the heights 3 4 5.

In the fourth test case we can't make a move, but the sequence is not increasing, so the answer is NO.

In the fifth test case we can only make one move (from the second to the third stack), which would make the heights 0 0 1. Both 0 1 0 and 0 0 1 are not increasing sequences, so the answer is NO.
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
		
		vector <long long> v(n);
		
		for (auto &x: v) cin >> x;
		
		bool res = true;
		
		long long toadd = v[0];
		
		v[0] = 0;
		
		for (int i = 1; i <  n; i++) {
			v[i] += toadd;
			
			if (v[i] <= v[i - 1]) {
				res = false;
				break;
			} else {
				toadd = v[i] - i;
				v[i] = i;
			}
		}
		
		res ? cout << "YES\n" : cout << "NO\n";
	}
	
	
    return 0;
}
