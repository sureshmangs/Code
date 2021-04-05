/*
Phoenix has n coins with weights 21,22,…,2n. He knows that n is even.

He wants to split the coins into two piles such that each pile has exactly n2 coins and the difference of weights between the two piles is minimized. Formally, let a denote the sum of weights in the first pile, and b denote the sum of weights in the second pile. Help Phoenix minimize |a-b|, the absolute value of a-b.

Input
The input consists of multiple test cases. The first line contains an integer t (1=t=100) — the number of test cases.

The first line of each test case contains an integer n (2=n=30; n is even) — the number of coins that Phoenix has.

Output
For each test case, output one integer — the minimum possible difference of weights between the two piles.

Example
inputCopy
2
2
4
outputCopy
2
6
Note
In the first test case, Phoenix has two coins with weights 2 and 4. No matter how he divides the coins, the difference will be 4-2=2.

In the second test case, Phoenix has four coins of weight 2, 4, 8, and 16. It is optimal for Phoenix to place coins with weights 2 and 16 in one pile, and coins with weights 4 and 8 in another pile. The difference is (2+16)-(4+8)=6.
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
    	
    	long long res = 0;
    	
    	res += pow(2, n);
    	
    	for (int i = 1; i <= n / 2 - 1; i++) res += pow(2, i);
    	
    	for (int i = n / 2; i < n; i++) res -= pow(2, i);
    	
    	cout << res << endl;
    	
	}
    
    
    return 0;
}

