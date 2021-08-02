/*
In number theory, the totient f of a positive integer n 
is defined to be the number of positive integers less than 
or equal to n that are coprime to n.

Given an integer n (1 <= n <= 10^6). Compute the value of the totient f.

Input
First line contains an integer T, the number of test cases. (T <= 20000)

T following lines, each contains an integer n.

Output
T lines, one for the result of each test case.

Example
Input:
5
1
2
3
4
5

Output:
1
1
2
2
4
*/





/*
phi(n) = (n * (p1 - 1) * (p2 - 1)....(pk - 1)) / (p1 * p2....pk)
*/


// TC: sqrt(n)

#include<bits/stdc++.h>
using namespace std;
 

int ETF(int n) {
	int res = n, limit = n;
        
    for (int i = 2; i * i <= limit; i++) {
        if (n % i == 0) {
            res /= i;
            res *= (i - 1);
        }
        while (n % i == 0) {
            n /= i;
        }
    }  
    
    if (n > 1) {
        res /= n;
        res *= (n - 1);
    }
        
    return res;
}

 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  {
		int n;
		cin >> n;
		
		cout << ETF(n) << "\n";
	}
	
    return 0;
}
