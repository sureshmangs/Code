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

    void combSum3(int k, int start, int target, vector<int> &comb, vector<vector<int> > &res){
        if(comb.size()==k && target==0){
            res.push_back(comb);
            return;
        }

        if(comb.size()>=k || target<=0)
            return;

        for(int i=start; i<10;i++){
            comb.push_back(i);
            combSum3(k, i+1, target-i, comb, res);
            comb.erase(comb.end()-1);
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> comb;
        combSum3(k, 1, n, comb, res);
        return res;
    }
};
