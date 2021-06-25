/*
Four players participate in the playoff tournament. The tournament is held according to the following scheme: the first player will play with the second, and the third player with the fourth, then the winners of the pairs will play in the finals of the tournament.

It is known that in a match between two players, the one whose skill is greater will win. The skill of the i-th player is equal to si and all skill levels are pairwise different (i.?e. there are no two identical values in the array s).

The tournament is called fair if the two players with the highest skills meet in the finals.

Determine whether the given tournament is fair.

Input
The first line contains a single integer t (1=t=104) — the number of test cases.

A single line of test case contains four integers s1,s2,s3,s4 (1=si=100) — skill of the players. It is guaranteed that all the numbers in the array are different.

Output
For each testcase, output YES if the tournament is fair, or NO otherwise.

Example
inputCopy
4
3 7 9 5
4 5 6 9
5 3 8 1
6 5 3 2
outputCopy
YES
NO
YES
NO
Note
Consider the example:

in the first test case, players 2 and 3 with skills 7 and 9 advance to the finals;
in the second test case, players 2 and 4 with skills 5 and 9 advance to the finals. The player with skill 6 does not advance, but the player with skill 5 advances to the finals, so the tournament is not fair;
in the third test case, players 1 and 3 with skills 5 and 8 advance to the finals;
in the fourth test case, players 1 and 3 with skills 6 and 3 advance to the finals. The player with skill 5 does not advance, but the player with skill 3 advances to the finals, so the tournament is not fair.
*/



/*
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while (t--) {
		vector <int> v(4);
		
		for (auto &x: v) cin >> x;
		
		int a = v[0], b = v[1], c = v[2], d = v[3];
		
		sort(v.begin(), v.end());
		
		int max1 = v[3], max2 = v[2], res1, res2;
		
		if (a > b) res1 = a;
		else res1 = b;
		
		if (c > d) res2 = c;
		else res2 = d;
		
		if (res1 == max1 && res2 == max2) cout << "YES\n";
		else if (res1 == max2 && res2 == max1) cout << "YES\n";
		else cout << "NO\n";
	}
	
    return 0;
}

*/



#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while (t--) {
		int a, b, c,  d;
		cin >> a >>b >>c >> d;
		
		if (min(a, b) > max(c, d) || min(c, d) > max(a, b)) cout << "NO\n";
		else cout << "YES\n";
		
	}
	
    return 0;
}
