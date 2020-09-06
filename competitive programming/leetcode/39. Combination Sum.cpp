Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]


Constraints:

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
Each element of candidate is unique.
1 <= target <= 500







class Solution {
public:

    void combSum(vector<int>& candidates, int target, int next, vector<int> &comb, vector<vector<int> > &res){
        if(target==0){
            res.push_back(comb);
            return;
        } else if(target<0) return;
        for(int i=next;i<candidates.size();i++){
            comb.push_back(candidates[i]);
            combSum(candidates, target-candidates[i], i, comb, res);
            comb.erase(comb.end()-1); // backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> comb;

        combSum(candidates, target, 0, comb, res);

        return res;
    }
};
