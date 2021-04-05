/*
Find the minimum area of a square land on which you can place two identical rectangular a×b houses. The sides of the houses should be parallel to the sides of the desired square land.

Formally,

You are given two identical rectangles with side lengths a and b (1=a,b=100) — positive integers (you are given just the sizes, but not their positions).
Find the square of the minimum area that contains both given rectangles. Rectangles can be rotated (both or just one), moved, but the sides of the rectangles should be parallel to the sides of the desired square.
Two rectangles can touch each other (side or corner), but cannot intersect. Rectangles can also touch the sides of the square but must be completely inside it. You can rotate the rectangles. Take a look at the examples for a better understanding.

The picture shows a square that contains red and green rectangles.
Input
The first line contains an integer t (1=t=10000) —the number of test cases in the input. Then t test cases follow.

Each test case is a line containing two integers a, b (1=a,b=100) — side lengths of the rectangles.

Output
Print t answers to the test cases. Each answer must be a single integer — minimal area of square land, that contains two rectangles with dimensions a×b.

Example
inputCopy
8
3 2
4 2
1 1
3 1
4 7
1 3
7 4
100 100
outputCopy
16
16
4
9
64
9
64
40000
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
		int res = min(max(2 * a, b), max(2 * b, a));
		cout << res * res << endl;
	}
    
    return 0;
}

