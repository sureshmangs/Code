/*
You are given some Tetris field consisting of n columns. The initial height of the i-th column of the field is ai blocks. On top of these columns you can place only figures of size 2×1 (i.e. the height of this figure is 2 blocks and the width of this figure is 1 block). Note that you cannot rotate these figures.

Your task is to say if you can clear the whole field by placing such figures.

More formally, the problem can be described like this:

The following process occurs while at least one ai is greater than 0:

You place one figure 2×1 (choose some i from 1 to n and replace ai with ai+2);
then, while all ai are greater than zero, replace each ai with ai-1.
And your task is to determine if it is possible to clear the whole field (i.e. finish the described process), choosing the places for new figures properly.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1=t=100) — the number of test cases.

The next 2t lines describe test cases. The first line of the test case contains one integer n (1=n=100) — the number of columns in the Tetris field. The second line of the test case contains n integers a1,a2,…,an (1=ai=100), where ai is the initial height of the i-th column of the Tetris field.

Output
For each test case, print the answer — "YES" (without quotes) if you can clear the whole Tetris field and "NO" otherwise.

Example
inputCopy
4
3
1 1 3
4
1 1 2 1
2
11 11
1
100
outputCopy
YES
NO
YES
YES
Note
The first test case of the example field is shown below:



Gray lines are bounds of the Tetris field. Note that the field has no upper bound.

One of the correct answers is to first place the figure in the first column. Then after the second step of the process, the field becomes [2,0,2]. Then place the figure in the second column and after the second step of the process, the field becomes [0,0,0].

And the second test case of the example field is shown below:



It can be shown that you cannot do anything to end the process.

In the third test case of the example, you first place the figure in the second column after the second step of the process, the field becomes [0,2]. Then place the figure in the first column and after the second step of the process, the field becomes [0,0].

In the fourth test case of the example, place the figure in the first column, then the field becomes [102] after the first step of the process, and then the field becomes [0] after the second step of the process.
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
		
		vector <int> v(n);
		
		for (auto &x: v) cin >> x;
		
		int odd = 0;
		
		for (auto &x: v) {
			if (x % 2) odd++;
		}
		
		if (odd == n || n - odd == n) cout << "YES\n";
		else cout << "NO\n";
	}

	
    return 0;
}

