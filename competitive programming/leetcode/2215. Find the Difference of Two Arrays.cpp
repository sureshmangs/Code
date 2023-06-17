Given two 0-indexed integer arrays nums1 and nums2,
return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.

Example 1:
Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1
and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4
and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].

Example 2:
Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3],
their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].

Constraints:
1 <= nums1.length, nums2.length <= 1000
-1000 <= nums1[i], nums2[i] <= 1000
********************************************************************************










# Approach 1:

class Solution {
public:

    void solve(vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &res) {
        unordered_set <int> s1, s2;
        for (auto &x: nums1) s1.insert(x);
        for (auto &x: nums2) s2.insert(x);

        vector <int> tmp;

        for (auto it = s1.begin(); it != s1.end(); it++) {
            if (s2.find(*it) == s2.end()) tmp.push_back(*it);
        }
        res.push_back(tmp);
    }

    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res;
        solve(nums1, nums2, res);
        solve(nums2, nums1, res);
        return res;
    }
};

TC -> O(n), n is the max size of one of the nums1, nums2
SC -> O(n), n is the max size of one of the nums1, nums2
