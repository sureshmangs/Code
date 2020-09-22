Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
   Hide Hint #1
How many majority elements could it possibly have?
Do you have a better hint? Suggest it!







class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();
        map<int, int> m;
        for(auto num: nums){
            m[num]++;
        }

        for(auto [num, freq]: m){
            if(freq>n/3)
                res.push_back(num);
        }
        return res;
    }
};
