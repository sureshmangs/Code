/*
Polycarpus has got n candies and m friends (n?=?m). He wants to make a New Year present with candies to each friend. Polycarpus is planning to present all candies and he wants to do this in the fairest (that is, most equal) manner. He wants to choose such ai, where ai is the number of candies in the i-th friend's present, that the maximum ai differs from the least ai as little as possible.

For example, if n is divisible by m, then he is going to present the same number of candies to all his friends, that is, the maximum ai won't differ from the minimum one.

Input
The single line of the input contains a pair of space-separated positive integers n, m (1?=?n,?m?=?100;n?=?m) — the number of candies and the number of Polycarpus's friends.

Output
Print the required sequence a1,?a2,?...,?am, where ai is the number of candies in the i-th friend's present. All numbers ai must be positive integers, total up to n, the maximum one should differ from the minimum one by the smallest possible value.

Examples
inputCopy
12 3
outputCopy
4 4 4 
inputCopy
15 4
outputCopy
3 4 4 4 
inputCopy
18 7
outputCopy
2 2 2 3 3 3 3 
Note
Print ai in any order, separate the numbers by spaces.
*/




#include<bits/stdc++.h>
using namespace std;

 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
   	int equal = n / m;
   	
   	int extra = n % m;
   	
   	for (int i = 1; i <= m - extra; i++) cout << equal << " ";
   	for (int i = m - extra + 1; i <= m; i++) cout << equal + 1 << " ";
  	
    return 0;
}
