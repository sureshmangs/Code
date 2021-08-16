/*
Ezzat has an array of n integers (maybe negative). He wants to split it into two non-empty subsequences a and b, such that every element from the array belongs to exactly one subsequence, and the value of f(a)+f(b) is the maximum possible value, where f(x) is the average of the subsequence x.

A sequence x is a subsequence of a sequence y if x can be obtained from y by deletion of several (possibly, zero or all) elements.

The average of a subsequence is the sum of the numbers of this subsequence divided by the size of the subsequence.

For example, the average of [1,5,6] is (1+5+6)/3=12/3=4, so f([1,5,6])=4.

Input
The first line contains a single integer t (1=t=103)— the number of test cases. Each test case consists of two lines.

The first line contains a single integer n (2=n=105).

The second line contains n integers a1,a2,…,an (-109=ai=109).

It is guaranteed that the sum of n over all test cases does not exceed 3·105.

Output
For each test case, print a single value — the maximum value that Ezzat can achieve.

Your answer is considered correct if its absolute or relative error does not exceed 10-6.

Formally, let your answer be a, and the jury's answer be b. Your answer is accepted if and only if |a-b|max(1,|b|)=10-6.

Example
inputCopy
4
3
3 1 2
3
-7 -6 -6
3
2 2 2
4
17 3 5 -3
outputCopy
4.500000000
-12.500000000
4.000000000
18.666666667
Note
In the first test case, the array is [3,1,2]. These are all the possible ways to split this array:

a=[3], b=[1,2], so the value of f(a)+f(b)=3+1.5=4.5.
a=[3,1], b=[2], so the value of f(a)+f(b)=2+2=4.
a=[3,2], b=[1], so the value of f(a)+f(b)=2.5+1=3.5.
Therefore, the maximum possible value 4.5.
In the second test case, the array is [-7,-6,-6]. These are all the possible ways to split this array:

a=[-7], b=[-6,-6], so the value of f(a)+f(b)=(-7)+(-6)=-13.
a=[-7,-6], b=[-6], so the value of f(a)+f(b)=(-6.5)+(-6)=-12.5.
Therefore, the maximum possible value -12.5.
*/






#include<bits/stdc++.h>
using namespace std;
 
void solve() {
	long long n;
	cin >> n;
	
	vector <long long> v(n);
	
	for (auto &x: v) cin >> x;
	
	int maxi = *max_element(v.begin(), v.end());
	
	long long sum = 0;
	
	for (auto &x: v) sum += x;
	
	sum -= maxi;
	
	double res = double(maxi) + double(sum) / (n - 1);
	
	cout << setprecision(9) << fixed << res << "\n";
	
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
