/*
Let us see the following equation,
ax+by=c

Given three positive integers a, b and c. 
You have to determine whether there exists at least one solution for some 
integers value of x and y where x, y may be negative or non-negative integers.

For example if a=2, b=4 and c=8 then the equation will be 2x+4y=8, and hence, for x=2 and y=1, there exists a solution.

Let us see another example for a=3, b=6 and c=7, so the equation will become 3x+6y=7 and there exists no solution satisfying this equation.

Input

Input starts with an integer T (1<=T<=105) denoting the number of test cases. 
Each test case contains three integers a, b, and c. (1<=a, b, c<=106).

Output

For each test case of input print the case number and “Yes” 
if there exists at least one solution, print “No” otherwise.

Sample Input

Output for Sample Input

2
2 4 8
3 6 7

Case 1: Yes
Case 2: No
*/









#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	for (int i = 1; i <= t; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		int g = __gcd(a, b);
		
		if (c % g == 0) 	cout << "Case " << i << ": Yes"<< "\n";
		else cout << "Case " << i << ": No" << "\n";
	}
	
    return 0;
}










// Linear Diophantine Equation

#include<bits/stdc++.h>
using namespace std;


int extendedEuclid(int a, int b, int &x, int &y) {
    if (a == 0){
        x = 0;
        y = 1;
        return b;
    }
    
    int x1, y1;
    int gcd = extendedEuclid(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

bool LDA(int a, int b, int c, int &x, int &y) {
	int x0, y0;
	
	int g = extendedEuclid(abs(a), abs(b), x0, y0);
	
	if (c % g) return false;
	
	x = x0 * c / g;
	y = y0 * c / g;
	
	if (a < 0) x = -x;
	if (b < 0) y = -y;
	
	return true;
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a, b, c;
    cin >> a >> b >> c;
	
	int x, y; // solution
	
	if (LDA(a, b, c,x, y) == false) cout << "Solution Doesn't Exists";
	else cout << x << " " << y;
	
    return 0;
}
