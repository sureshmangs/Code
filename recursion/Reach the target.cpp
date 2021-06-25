/*
Given four integers A, B, C, D. 
A represents the initial position of the geek on the x-axis. 
In each step, geek can go to X+B or X-B if he is standing at X. 
The tasks is to check if it is possible for the geek to reach C exactly after D steps.

Input:
1. The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
2. The first line of each test case contains four space-separated integers A, B, C, and D.

Output: For each test case, print "yes" if it is possible to reach C in exactly D steps. Otherwise, print "no" (without quotes).

Constraints:
1. 1 <= T <= 5
2. -10^9 <= A, C <= 10^9
3. 1 <= B <= 10^9
4. 1 <= D <= 15

Example:
Input:
3
2 3 8 4
-3 1 0 3
-3 1 1 3

Output:
yes
yes
no

Explanation:
Test case 1: one of the possible ways is {2, 5, 8, 11, 8}
*/



#include<bits/stdc++.h>
using namespace std;


bool solve(long long a, long long b, long long c, long long d){
    if (d == 0) return a == c;
    
    if (a <= c) solve(a + b, b, c, d - 1);
    else solve(a - b, b, c, d - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        
        cout << (solve(a, b, c, d) ? "yes\n" : "no\n");
    }



return 0;
}
