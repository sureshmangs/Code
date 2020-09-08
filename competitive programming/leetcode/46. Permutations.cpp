Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]







class Solution {
public:

    void allPermute(vector<int> nums, int start, vector<vector<int> > &res){
        if(start==nums.size()){
            res.push_back(nums);
        } else {
            for(int i=start;i<nums.size();i++){
                swap(nums[start], nums[i]);
                allPermute(nums, start+1, res);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        allPermute(nums, 0, res);
        return res;
    }
};
