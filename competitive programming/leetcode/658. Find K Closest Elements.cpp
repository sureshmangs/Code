Given a sorted array arr, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.



Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]


Constraints:

1 <= k <= arr.length
1 <= arr.length <= 10^4
Absolute value of elements in the array and x will not exceed 104






class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        priority_queue<pair<int, int> > maxh;
        for(int i=0;i<n;i++){
            maxh.push({abs(x-arr[i]), arr[i]});
            if(maxh.size()>k) maxh.pop();
        }
        vector<int> res;
        while(!maxh.empty()){
            res.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};
