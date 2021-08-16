/*
Moamen has an array of n distinct integers. He wants to sort that array in non-decreasing order by doing the following operations in order exactly once:

Split the array into exactly k non-empty subarrays such that each element belongs to exactly one subarray.
Reorder these subarrays arbitrary.
Merge the subarrays in their new order.
A sequence a is a subarray of a sequence b if a can be obtained from b by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

Can you tell Moamen if there is a way to sort the array in non-decreasing order using the operations written above?

Input
The first line contains a single integer t (1=t=103) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers n and k (1=k=n=105).

The second line contains n integers a1,a2,…,an (0=|ai|=109). It is guaranteed that all numbers are distinct.

It is guaranteed that the sum of n over all test cases does not exceed 3·105.

Output
For each test case, you should output a single string.

If Moamen can sort the array in non-decreasing order, output "YES" (without quotes). Otherwise, output "NO" (without quotes).

You can print each letter of "YES" and "NO" in any case (upper or lower).

Example
inputCopy
3
5 4
6 3 4 2 1
4 2
1 -4 0 -2
5 1
1 2 3 4 5
outputCopy
Yes
No
Yes
Note
In the first test case, a=[6,3,4,2,1], and k=4, so we can do the operations as follows:

Split a into {[6],[3,4],[2],[1]}.
Reorder them: {[1],[2],[3,4],[6]}.
Merge them: [1,2,3,4,6], so now the array is sorted.
In the second test case, there is no way to sort the array by splitting it into only 2 subarrays.

As an example, if we split it into {[1,-4],[0,-2]}, we can reorder them into {[1,-4],[0,-2]} or {[0,-2],[1,-4]}. However, after merging the subarrays, it is impossible to get a sorted array.

*/






#include<bits/stdc++.h>
using namespace std;
 
void solve() {
	int n, k;
	cin >> n >> k;
	
	vector <int> v(n);
	
	for (auto &x: v) cin >> x;
	
	vector <int> tmp = v;
	
	sort(tmp.begin(), tmp.end());
	
	int part = 0;
	
	for (int i = 0; i < n - 1; i++) {
		if (v[i] > v[i +1]) part++;
		else {
			int start = lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin();
			int end = lower_bound(tmp.begin(), tmp.end(), v[i + 1]) - tmp.begin();
			
			if (end - start >= 2) part++;
		}
	}
	
	if (part + 1 <= k) cout << "Yes\n";
	else cout << "No\n";
	
}
 
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--)  solve();
	
    return 0;
}
