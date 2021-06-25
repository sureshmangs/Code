/*
While trading on his favorite exchange trader William realized that he found a vulnerability. Using this vulnerability he could change the values of certain internal variables to his advantage. To play around he decided to change the values of all internal variables from a1,a2,…,an to -a1,-a2,…,-an. For some unknown reason, the number of service variables is always an even number.

William understands that with his every action he attracts more and more attention from the exchange's security team, so the number of his actions must not exceed 5000 and after every operation no variable can have an absolute value greater than 1018. William can perform actions of two types for two chosen variables with indices i and j, where i<j:

Perform assignment ai=ai+aj
Perform assignment aj=aj-ai
William wants you to develop a strategy that will get all the internal variables to the desired values.
Input
Each test contains multiple test cases. The first line contains the number of test cases t (1=t=20). Description of the test cases follows.

The first line of each test case contains a single even integer n (2=n=103), which is the number of internal variables.

The second line of each test case contains n integers a1,a2,…,an (1=ai=109), which are initial values of internal variables.

Output
For each test case print the answer in the following format:

The first line of output must contain the total number of actions k, which the strategy will perform. Note that you do not have to minimize k. The inequality k=5000 must be satisfied.

Each of the next k lines must contain actions formatted as "type i j", where "type" is equal to "1" if the strategy needs to perform an assignment of the first type and "2" if the strategy needs to perform an assignment of the second type. Note that i<j should hold.

We can show that an answer always exists.

Example
inputCopy
2
4
1 1 1 1
4
4 3 1 2
outputCopy
8
2 1 2
2 1 2
2 1 3
2 1 3
2 1 4
2 1 4
1 1 2
1 1 2
8
2 1 4
1 2 4
1 2 4
1 2 4
1 3 4
1 1 2
1 1 2
1 1 4
Note
For the first sample test case one possible sequence of operations is as follows:

"2 1 2". Values of variables after performing the operation: [1, 0, 1, 1]
"2 1 2". Values of variables after performing the operation: [1, -1, 1, 1]
"2 1 3". Values of variables after performing the operation: [1, -1, 0, 1]
"2 1 3". Values of variables after performing the operation: [1, -1, -1, 1]
"2 1 4". Values of variables after performing the operation: [1, -1, -1, 0]
"2 1 4". Values of variables after performing the operation: [1, -1, -1, -1]
"1 1 2". Values of variables after performing the operation: [0, -1, -1, -1]
"1 1 2". Values of variables after performing the operation: [-1, -1, -1, -1]
For the second sample test case one possible sequence of operations is as follows:

"2 1 4". Values of variables after performing the operation: [4, 3, 1, -2]
"1 2 4". Values of variables after performing the operation: [4, 1, 1, -2]
"1 2 4". Values of variables after performing the operation: [4, -1, 1, -2]
"1 2 4". Values of variables after performing the operation: [4, -3, 1, -2]
"1 3 4". Values of variables after performing the operation: [4, -3, -1, -2]
"1 1 2". Values of variables after performing the operation: [1, -3, -1, -2]
"1 1 2". Values of variables after performing the operation: [-2, -3, -1, -2]
"1 1 4". Values of variables after performing the operation: [-4, -3, -1, -2]
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
		
		cout << 3 * n << "\n";
		
		for (int i = 1; i < n; i += 2) {
			cout << 1 << " " << i  << " " << i + 1 << "\n";
			cout << 2 << " " << i  << " " << i + 1 << "\n";
			cout << 1 << " " << i  << " " << i + 1 << "\n";
			cout << 2 << " " << i  << " " << i + 1 << "\n";
			cout << 1 << " " << i  << " " << i + 1 << "\n";
			cout << 2 << " " << i  << " " << i + 1 << "\n";
		}
	}
	
    return 0;
}
