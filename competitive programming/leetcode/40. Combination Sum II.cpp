Given a collection of candidate numbers (candidates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]













class Solution {
public:
    
    void combSum(vector<int> &candidates, int target, int cur, vector<int> &comb, vector<vector<int>> &res){
        if (target == 0){
            res.push_back(comb);
            return;
        }
        if (target < 0) return;
        
        for (int i = cur; i < candidates.size(); i++){
            if (i > 0 && candidates[i] == candidates[i - 1] && i > cur) continue; // check for duplicates
            comb.push_back(candidates[i]);
            combSum(candidates, target - candidates[i], i + 1, comb, res);  // i + 1 because we can consider one element only once
            comb.erase(comb.end() - 1); // backtrack
        }
    }
    
    vector <vector<int>> combinationSum2(vector <int> &candidates, int target) {
        vector <vector<int> > res;
        vector <int> comb;
        
        sort(candidates.begin(), candidates.end());
        
        combSum(candidates, target, 0, comb, res);
        
        return res;
    }
};










// Using a set to avoid duplicates

class Solution {
public:

    void combSum(vector<int>& candidates, int target, int next, vector<int> &comb, set<vector<int> > &resSet ){
        if(target==0){
            resSet.insert(comb);
            return;
        } else if(target<0) return;
        for(int i=next;i<candidates.size();i++){
            comb.push_back(candidates[i]);
            combSum(candidates, target-candidates[i], i+1, comb, resSet);
            comb.erase(comb.end()-1); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        set<vector<int> > resSet;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        combSum(candidates, target, 0, comb, resSet);

        for(auto &x: resSet) res.push_back(x);

        return res;
    }
};








class Solution {
public:
    vector <vector<int>> res;
    void combSum(int i, vector <int> &candidates, vector <int> &comb, int target, vector <bool> &used) {
        if (i >= candidates.size()) {
            if (target == 0) res.push_back(comb);
            return;
        }

        if (target < 0) return;

        combSum(i + 1, candidates, comb, target, used);     // not considering i'th element

        if (i == 0 || candidates[i] != candidates[i-1] || used[i-1]) {
            comb.push_back(candidates[i]);                              
            used[i] = true;
            combSum(i + 1, candidates, comb, target - candidates[i], used); // considering i'th element
            used[i] = false;
            comb.erase(comb.end() - 1);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector <int> comb;
        vector <bool> used(candidates.size(), false); // to check if previous element has been used

        sort(candidates.begin(), candidates.end());
        combSum(0, candidates, comb, target, used);
        return res;
    }
};
