Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]









// Backtracking
// TC: n * 2^n

class Solution {
public:
    
    void solve(int start, int size, vector <int> &nums, vector<int> &cur, vector<vector<int>> &res) {
        if (cur.size() == size) {
            res.push_back(cur);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            solve(i + 1, size, nums, cur, res);
            cur.pop_back();  // backtrack
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector <int> cur;
        
        int n = nums.size();
        
        for (int k = 0; k <= n; k++) {
            solve(0, k, nums, cur, res);
        }
        
        return res;
    }
};








// Backtracking

class Solution {
public:

    void subset(vector<int> nums, int i, vector<vector<int> > &res, vector<int> &curr){
        if(i==nums.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        subset(nums, i+1, res, curr);
        curr.erase(curr.end()-1);
        subset(nums, i+1, res, curr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> curr;
        subset(nums, 0, res, curr);
        return res;
    }
};






// also can be done using bitmasking
