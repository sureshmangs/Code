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
