Given an array nums of n integers where nums[i] is in the range [1, n], 
return an array of all the integers in the range [1, n] that do not appear in nums.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2]
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
 

Follow up: Could you do it without extra space and in O(n) runtime? 
You may assume the returned list does not count as extra space.


















// TC: O(n) 
// SC: O(1)

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector <int> res;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] *= -1;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) res.push_back(i + 1);
        }
        
        return res;
    }
};






// TC: O(n) 
// SC: O(n)

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector <int> res;
        unordered_set <int> s;
        
        for (auto &x: nums) s.insert(x);
        
        for (int i = 1; i <= nums.size(); i++) {
            if (s.find(i) == s.end()) res.push_back(i);
        }
        
        return res;
    }
};

