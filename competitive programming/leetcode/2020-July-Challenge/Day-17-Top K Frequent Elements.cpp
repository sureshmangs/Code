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
        vector<int>res;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >   > pq; // min heap
        unordered_map<int, int> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(m.find(nums[i])!=m.end())
                m[nums[i]]++;
            else m.insert({nums[i], 1});
        }
        for(auto it=m.begin(); it!=m.end(); it++){
            pq.push({it->second, it->first});
            if(pq.size()>k) pq.pop();
        }

        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
