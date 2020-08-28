Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.

For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.

Note:

You may assume the interval's end point is always bigger than its start point.
You may assume none of these intervals have the same start point.


Example 1:

Input: [ [1,2] ]

Output: [-1]

Explanation: There is only one interval in the collection, so it outputs -1.


Example 2:

Input: [ [3,4], [2,3], [1,2] ]

Output: [-1, 0, 1]

Explanation: There is no satisfied "right" interval for [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point;
For [1,2], the interval [2,3] has minimum-"right" start point.


Example 3:

Input: [ [1,4], [2,3], [3,4] ]

Output: [-1, 2, -1]

Explanation: There is no satisfied "right" interval for [1,4] and [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.







class Solution {
public:

    int bSearch(vector<int> &first, int item){
        int l=0, h=first.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(item>first[mid]) l=mid+1;
            else h=mid-1;
        }
        return l;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int> ans;

        unordered_map<int, int> mp;  // <start, index>
        for(int i=0;i<n;i++){
            mp[intervals[i][0]]=i;
        }

        vector<int> first;
        for(int i=0;i<n;i++)
            first.push_back(intervals[i][0]);
        sort(first.begin(), first.end());

        for(int i=0;i<n;i++){
            int item=intervals[i][1];
            int key=bSearch(first, item);
            if(key==n)
                ans.push_back(-1);
            else if(key==0){
                if(intervals[i][1]<=first[0])
                    ans.push_back(mp[first[0]]);
                else ans.push_back(-1);
            } else ans.push_back(mp[first[key]]);
        }
        return ans;
    }
};
