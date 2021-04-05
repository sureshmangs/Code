/*
There are n athletes in front of you. Athletes are numbered from 1 to n from left to right. You know the strength of each athlete — the athlete number i has the strength si.

You want to split all athletes into two teams. Each team must have at least one athlete, and each athlete must be exactly in one team.

You want the strongest athlete from the first team to differ as little as possible from the weakest athlete from the second team. Formally, you want to split the athletes into two teams A and B so that the value |max(A)-min(B)| is as small as possible, where max(A) is the maximum strength of an athlete from team A, and min(B) is the minimum strength of an athlete from team B.

For example, if n=5 and the strength of the athletes is s=[3,1,2,6,4], then one of the possible split into teams is:

first team: A=[1,2,4],
second team: B=[3,6].
In this case, the value |max(A)-min(B)| will be equal to |4-3|=1. This example illustrates one of the ways of optimal split into two teams.

Print the minimum value |max(A)-min(B)|.

Input
The first line contains an integer t (1=t=1000) — the number of test cases in the input. Then t test cases follow.

Each test case consists of two lines.

The first line contains positive integer n (2=n=50) — number of athletes.

The second line contains n positive integers s1,s2,…,sn (1=si=1000), where si — is the strength of the i-th athlete. Please note that s values may not be distinct.

Output
For each test case print one integer — the minimum value of |max(A)-min(B)| with the optimal split of all athletes into two teams. Each of the athletes must be a member of exactly one of the two teams.

Example
inputCopy
5
5
3 1 2 6 4
6
2 1 3 2 4 3
4
7 9 3 1
2
1 1000
3
100 150 200
outputCopy
1
0
2
999
50
Note
The first test case was explained in the statement. In the second test case, one of the optimal splits is A=[2,1], B=[3,2,4,3], so the answer is |2-2|=0.
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
	    
	    for (int i = 0; i < n; i++) cin >> v[i];
	    
	    sort(v.begin(), v.end());
	    
	    int res = INT_MAX;
	    
	    for (int i = 0; i < n - 1; i++) res = min(res, v[i + 1] - v[i]);
	    
	    cout << res << endl;
	}
    
    
    return 0;
}
	
