/*
There are three friend living on the straight line Ox in Lineland. The first friend lives at the point x1, the second friend lives at the point x2, and the third friend lives at the point x3. They plan to celebrate the New Year together, so they need to meet at one point. What is the minimum total distance they have to travel in order to meet at some point and celebrate the New Year?

It's guaranteed that the optimal answer is always integer.

Input
The first line of the input contains three distinct integers x1, x2 and x3 (1?=?x1,?x2,?x3?=?100) — the coordinates of the houses of the first, the second and the third friends respectively.

Output
Print one integer — the minimum total distance the friends need to travel in order to meet together.

Examples
inputCopy
7 1 4
outputCopy
6
inputCopy
30 20 10
outputCopy
20
Note
In the first sample, friends should meet at the point 4. Thus, the first friend has to travel the distance of 3 (from the point 7 to the point 4), the second friend also has to travel the distance of 3 (from the point 1 to the point 4), while the third friend should not go anywhere because he lives at the point 4.
*/




#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int a, b, c;
	cin >> a >> b >> c;
	
	int res = INT_MAX;
	
	res = min(res, abs(a - b) + abs(a - c));
	res = min(res, abs(b - a) + abs(b - c));
	res = min(res, abs(c - a) + abs(c - b));
	
	cout << res;
    
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int a, b, c;
	cin >> a >> b >> c;
	
	cout << max(a, max(b, c)) - min(a, min(b, c));
    
    return 0;
}
