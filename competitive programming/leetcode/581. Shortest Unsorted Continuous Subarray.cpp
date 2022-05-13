Given an integer array nums, you need to find one continuous subarray that 
if you only sort this subarray in ascending order, then the whole array will 
be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to 
make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0
 

Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105
 

Follow up: Can you solve it in O(n) time complexity?












// TC -> O(nlogn)
// SC -> O(n)

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        vector <int> tmp = nums;
        
        sort(tmp.begin(), tmp.end());
        
        while (start < nums.size() && nums[start] == tmp[start]) {
            start++;
        }
        while (end >= 0 && nums[end] == tmp[end]) {
            end--;
        }
        
        if (start >= nums.size() || end < 0) return 0;
        
        return end - start + 1;
    }
};















// TC -> O(n)
// SC -> O(n)

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = nums.size(), end = 0;
        stack <int> s;
         
        for (int i = 0; i < nums.size(); i++) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                start = min(start, s.top());
                s.pop();
            }
            s.push(i);
        }
        
        // empty the stack
        while (!s.empty()) {
            s.pop();
        }
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                end = max(end, s.top());
                s.pop();
            }
            s.push(i);
        }
        
        if (start >= nums.size() || end < 0) return 0;
        
        return end - start + 1;
    }
};










// TC -> O(n)
// SC -> O(1)

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minv = INT_MAX, maxv = INT_MIN;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                minv = min(minv, nums[i]);
            }
        }
        
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                maxv = max(maxv, nums[i]);
            }
        }
        
        int start, end;
        
        for (start = 0; start < nums.size(); start++) {
            if (minv < nums[start]) break;
        }
        
        for (end = nums.size() - 1; end >= 0; end--) {
            if (maxv > nums[end]) break;
        }
        
        
        if (start >= nums.size() || end < 0) return 0;
        
        return end - start + 1;
    }
};
