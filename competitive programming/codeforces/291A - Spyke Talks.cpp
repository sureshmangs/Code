/*
Polycarpus is the director of a large corporation. There are n secretaries working for the corporation, each of them corresponds via the famous Spyke VoIP system during the day. We know that when two people call each other via Spyke, the Spyke network assigns a unique ID to this call, a positive integer session number.

One day Polycarpus wondered which secretaries are talking via the Spyke and which are not. For each secretary, he wrote out either the session number of his call or a 0 if this secretary wasn't talking via Spyke at that moment.

Help Polycarpus analyze these data and find out the number of pairs of secretaries that are talking. If Polycarpus has made a mistake in the data and the described situation could not have taken place, say so.

Note that the secretaries can correspond via Spyke not only with each other, but also with the people from other places. Also, Spyke conferences aren't permitted — that is, one call connects exactly two people.

Input
The first line contains integer n (1?=?n?=?103) — the number of secretaries in Polycarpus's corporation. The next line contains n space-separated integers: id1,?id2,?...,?idn (0?=?idi?=?109). Number idi equals the number of the call session of the i-th secretary, if the secretary is talking via Spyke, or zero otherwise.

Consider the secretaries indexed from 1 to n in some way.

Output
Print a single integer — the number of pairs of chatting secretaries, or -1 if Polycarpus's got a mistake in his records and the described situation could not have taken place.

Examples
inputCopy
6
0 1 7 1 7 10
outputCopy
2
inputCopy
3
1 1 1
outputCopy
-1
inputCopy
1
0
outputCopy
0
Note
In the first test sample there are two Spyke calls between secretaries: secretary 2 and secretary 4, secretary 3 and secretary 5.

In the second test sample the described situation is impossible as conferences aren't allowed.

*/




#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    unordered_map <int, int> mp;
    
    for (int i = 0; i < n; i++) {
    	int a;
    	cin >> a;
    	mp[a]++;
	}
	
	bool flag = true;
	int res = 0;
	
	for (auto &it: mp) {
		if (it.first != 0 && it.second > 2) {
			flag = false; break;
		}
		else if (it.first != 0 && it.second == 2) res++;
	}
	
	if (flag == false) cout << "-1";
	else cout << res;

    return 0;
}
