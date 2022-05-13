Find all possible combinations of k numbers that add up to a number n,
given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]






class Solution {
public:
    vector<vector<int>> res;
    
    void combSumUtil(int start, int k, int sum, vector <int> &comb) {
        if (comb.size() == k && sum == 0) {
            res.push_back(comb);
            return;
        }
        if (comb.size() >= k || sum <= 0) return;
        
        for (int i = start; i <= 9; i++) {
            comb.push_back(i);
            combSumUtil(i + 1, k, sum - i, comb);
            comb.erase(comb.end() - 1); // backtrack
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <int> comb;
        combSumUtil(1, k, n, comb);
        return res;
    }
};


// TC -> O(C(9,k)) -> O(9^k)
// SC -> ???
