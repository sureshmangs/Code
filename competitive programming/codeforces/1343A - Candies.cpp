/*
Recently Vova found n candy wrappers. He remembers that he bought x candies during the first day, 2x candies during the second day, 4x candies during the third day, …, 2k-1x candies during the k-th day. But there is an issue: Vova remembers neither x nor k but he is sure that x and k are positive integers and k>1.

Vova will be satisfied if you tell him any positive integer x so there is an integer k>1 that x+2x+4x+?+2k-1x=n. It is guaranteed that at least one solution exists. Note that k>1.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1=t=104) — the number of test cases. Then t test cases follow.

The only line of the test case contains one integer n (3=n=109) — the number of candy wrappers Vova found. It is guaranteed that there is some positive integer x and integer k>1 that x+2x+4x+?+2k-1x=n.

Output
Print one integer — any positive integer value of x so there is an integer k>1 that x+2x+4x+?+2k-1x=n.

Example
inputCopy
7
3
6
7
21
28
999999999
999999984
outputCopy
1
2
1
7
4
333333333
333333328
Note
In the first test case of the example, one of the possible answers is x=1,k=2. Then 1·1+2·1 equals n=3.

In the second test case of the example, one of the possible answers is x=2,k=2. Then 1·2+2·2 equals n=6.

In the third test case of the example, one of the possible answers is x=1,k=3. Then 1·1+2·1+4·1 equals n=7.

In the fourth test case of the example, one of the possible answers is x=7,k=2. Then 1·7+2·7 equals n=21.

In the fifth test case of the example, one of the possible answers is x=4,k=3. Then 1·4+2·4+4·4 equals n=28
*/




#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		
		int k = 2;
		
		while (1) {
			int val = pow(2, k) - 1;
			if(n % val != 0) k++;
			else break;
		}
		
		cout << n / (long long)(pow(2, k) - 1) << endl;
	}

    return 0;
}
