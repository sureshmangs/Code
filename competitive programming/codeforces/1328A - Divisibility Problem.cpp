/*
You are given two positive integers a and b. In one move you can increase a by 1 (replace a with a+1). Your task is to find the minimum number of moves you need to do in order to make a divisible by b. It is possible, that you have to make 0 moves, as a is already divisible by b. You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1=t=104) — the number of test cases. Then t test cases follow.

The only line of the test case contains two integers a and b (1=a,b=109).

Output
For each test case print the answer — the minimum number of moves you need to do in order to make a divisible by b.

Example
inputCopy
5
10 4
13 9
100 13
123 456
92 46
outputCopy
2
5
4
333
0
*/




#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
    	int a, b;
    	cin >> a >> b;
    	
    	int r = a % b;
    	
    	int res = r ? b - r : r;
    	
    	cout << res << endl;
    		
	}


    return 0;
}
