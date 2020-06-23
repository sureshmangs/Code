/*
Given a collection of Intervals,merge all the overlapping Intervals.
For example:

Given [1,3], [2,6], [8,10], [15,18],

return [1,6], [8,10], [15,18].

Make sure the returned intervals are sorted.



Input:

The first line contains an integer T, depicting total number of test cases.
Then following T lines contains an integer N depicting the number of Intervals and next line followed by the intervals starting and ending positions 'x' and 'y' respectively.


Output:

Print the intervals after overlapping in sorted manner.  There should be a newline at the end of output of every test case.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 100
0 ≤ x ≤ y ≤ 100


Example:

Input
2
4
1 3 2 4 6 8 9 10
4
6 8 1 9 2 4 4 7

Output
1 4 6 8 9 10
1 9
*/







#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int> i1, vector<int> i2){
        return i1[0] < i2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > res;
        if(intervals.size()<=1) return intervals;
        sort(intervals.begin(), intervals.end(), comp);
        pair<int, int> tmp;
        tmp.first=intervals[0][0];
        tmp.second=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(tmp.second>=intervals[i][0]){
                tmp.second=max(tmp.second, intervals[i][1]);
            } else{
                res.push_back({tmp.first, tmp.second});
                tmp.first=intervals[i][0];
                tmp.second=intervals[i][1];
            }
        }
        res.push_back({tmp.first, tmp.second});   // adding last interva;
        return res;
    }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int> > intervals, res;
        for(int i=0;i<n;i++){
            int s, e;
            cin>>s>>e;
            intervals.push_back({s, e});
        }

        res=merge(intervals);

        for(int i=0;i<res.size();i++){
            cout<<res[i][0]<<" "<<res[i][1]<<" ";
        }
        cout<<endl;
    }

return 0;
}
