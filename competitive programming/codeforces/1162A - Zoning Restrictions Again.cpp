/*
You are planning to build housing on a street. There are n spots available on the street on which you can build a house. The spots are labeled from 1 to n from left to right. In each spot, you can build a house with an integer height between 0 and h.

In each spot, if a house has height a, you will gain a2 dollars from it.

The city has m zoning restrictions. The i-th restriction says that the tallest house from spots li to ri (inclusive) must be at most xi.

You would like to build houses to maximize your profit. Determine the maximum profit possible.

Input
The first line contains three integers n, h, and m (1=n,h,m=50) — the number of spots, the maximum height, and the number of restrictions.

Each of the next m lines contains three integers li, ri, and xi (1=li=ri=n, 0=xi=h) — left and right limits (inclusive) of the i-th restriction and the maximum possible height in that range.

Output
Print a single integer, the maximum profit you can make.

Examples
inputCopy
3 3 3
1 1 1
2 2 3
3 3 2
outputCopy
14
inputCopy
4 10 2
2 3 8
3 4 7
outputCopy
262
Note
In the first example, there are 3 houses, the maximum height of a house is 3, and there are 3 restrictions. The first restriction says the tallest house between 1 and 1 must be at most 1. The second restriction says the tallest house between 2 and 2 must be at most 3. The third restriction says the tallest house between 3 and 3 must be at most 2.

In this case, it is optimal to build houses with heights [1,3,2]. This fits within all the restrictions. The total profit in this case is 12+32+22=14.

In the second example, there are 4 houses, the maximum height of a house is 10, and there are 2 restrictions. The first restriction says the tallest house from 2 to 3 must be at most 8. The second restriction says the tallest house from 3 to 4 must be at most 7.

In this case, it's optimal to build houses with heights [10,8,7,7]. We get a profit of 102+82+72+72=262. Note that there are two restrictions on house 3 and both of them must be satisfied. Also, note that even though there isn't any explicit restrictions on house 1, we must still limit its height to be at most 10 (h=10).
*/





#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
	int n, h, m;
	cin >> n >> h >> m;
	
	vector <int> v(n, h);
	
	while (m--) {
		int l, r, x;
		cin >> l >> r >> x;
		
		for (int i = l - 1; i <= r - 1; i++) v[i] = min(v[i], x);
		
	}
	
	long long res = 0;
	
	for (auto &x: v) res += x * x;
	
	cout << res;
   
    return 0;
}
