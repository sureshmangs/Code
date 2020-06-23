Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.








class Solution {
public:

    static bool comp(vector<int> i1, vector<int> i2){
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
};
