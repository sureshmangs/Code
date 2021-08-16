Given an integer array nums that may contain duplicates, 
return all possible subsets (the power set).

The solution set must not contain duplicate subsets. 
Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10





class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        set <vector<int>> s;
        
        int n = nums.size();
        int limit = pow(2, n);
        
        for (int i = 0; i < limit; i++) {
            multiset <int> ms;
            for (int k = 0; k < n; k++) {
                if (i & (1 << k)) ms.insert(nums[k]);
            }
            
            vector <int> tmp;
            for (auto &x: ms) tmp.push_back(x);
            s.insert(tmp);
        }
        
        for (auto &x: s) res.push_back(x);
        
        return res;
    }
};
