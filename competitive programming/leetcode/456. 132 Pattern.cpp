Given an array of n integers nums, a 132 pattern is a subsequence of three 
integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

 

Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 

Constraints:

n == nums.length
1 <= n <= 2 * 105
-109 <= nums[i] <= 109












// TLE
// TC -> O(n ^ 3)
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        bool isPossible = false;
        
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] < nums[k] && nums[k] < nums[j]) {
                        isPossible = true;
                        break;
                    }
                }
                if (isPossible) break;
            }
            if (isPossible) break;
        }
        
        return isPossible;
    }
};












// TC -> O(n)
// SC -> O(n)

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return false;
        
        stack <int> s;
        int s2 = INT_MIN;
        
        for (int i = n - 1; i >= 0; i--) {
            if (s2 > nums[i]) return true;
            
            while (!s.empty() && s.top() < nums[i]) {
                s2 = max(s2, s.top());
                s.pop();
            }
            
            s.push(nums[i]);
        }
        
        return false;
    }
};
