Given a collection of numbers, nums, that might contain duplicates, 
return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10

















class Solution {
public:
    vector <vector<int>> res;
    vector <int> used;
    
    void dfs(vector <int> &curr, vector <int> nums) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i - 1] == nums[i] && used[i - 1]) continue;
            curr.push_back(nums[i]);
            used[i] = true;
            dfs(curr, nums);
            // Backtrack
            curr.erase(curr.end() - 1);
            used[i] = false;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        used.resize(nums.size(), false);
        vector <int> curr;
        
        sort(nums.begin(), nums.end());
        
        dfs(curr, nums);
        
        return res;
    }
};















class Solution {
public:
    vector <vector<int>> res;
    vector <int> used;
    
    void dfs(vector <int> &curr, vector <int> nums) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i - 1] == nums[i] && !used[i - 1]) continue;
            curr.push_back(nums[i]);
            used[i] = true;
            dfs(curr, nums);
            // Backtrack
            curr.erase(curr.end() - 1);
            used[i] = false;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        used.resize(nums.size(), false);
        vector <int> curr;
        
        sort(nums.begin(), nums.end());
        
        dfs(curr, nums);
        
        return res;
    }
};
