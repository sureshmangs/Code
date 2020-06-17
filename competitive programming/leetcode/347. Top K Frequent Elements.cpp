Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.





class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > minh;
        int n=nums.size();
        unordered_map<int, int> mp;  // calculating frequencies
        for(int i=0;i<n;i++) mp[nums[i]]++;
        for(auto it=mp.begin(); it!=mp.end(); it++){
            minh.push({it->second, it->first});
            if(minh.size()> k) minh.pop();
        }
        vector<int> res;
        while(!minh.empty()){
            res.push_back(minh.top().second);
            minh.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};
