/*
Alice and Bob received n candies from their parents. Each candy weighs either 1 gram or 2 grams. Now they want to divide all candies among themselves fairly so that the total weight of Alice's candies is equal to the total weight of Bob's candies.

Check if they can do that.

Note that candies are not allowed to be cut in half.

Input
The first line contains one integer t (1=t=104) — the number of test cases. Then t test cases follow.

The first line of each test case contains an integer n (1=n=100) — the number of candies that Alice and Bob received.

The next line contains n integers a1,a2,…,an — the weights of the candies. The weight of each candy is either 1 or 2.

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
For each test case, output on a separate line:

"YES", if all candies can be divided into two sets with the same weight;
"NO" otherwise.
You can output "YES" and "NO" in any case (for example, the strings yEs, yes, Yes and YES will be recognized as positive).

Example
inputCopy
5
2
1 1
2
1 2
4
1 2 1 2
3
2 2 2
3
2 1 2
outputCopy
YES
NO
YES
NO
NO
Note
In the first test case, Alice and Bob can each take one candy, then both will have a total weight of 1.

In the second test case, any division will be unfair.

In the third test case, both Alice and Bob can take two candies, one of weight 1 and one of weight 2.

In the fourth test case, it is impossible to divide three identical candies between two people.

In the fifth test case, any division will also be unfair.
*/




#include<bits/stdc++.h>
using namespace std;
 
void solve() {
	int n;
	cin >> n;
	
	int ones = 0, twos = 0;
	
	for (int i= 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 1) ones++;
	}
	
	twos = n - ones;
	
	if (ones % 2) {
		cout << "NO\n";
		return;
	}
	
	if (twos % 2 == 0 && ones % 2 == 0) cout << "YES\n";
	else {
		int alice = twos / 2;
		int bob = twos / 2 + 1;
		if (ones < 2) {
			cout << "NO\n";
			return;
		}
		alice += 2;
		ones -= 2;
		
		if (ones % 2) cout << "NO\n";
		else cout << "YES\n";
	}
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
