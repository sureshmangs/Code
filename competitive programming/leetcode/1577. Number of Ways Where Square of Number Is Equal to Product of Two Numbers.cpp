Given two arrays of integers nums1 and nums2, return the number of triplets formed (type 1 and type 2) under the following rules:

Type 1: Triplet (i, j, k) if nums1[i]2 == nums2[j] * nums2[k] where 0 <= i < nums1.length and 0 <= j < k < nums2.length.
Type 2: Triplet (i, j, k) if nums2[i]2 == nums1[j] * nums1[k] where 0 <= i < nums2.length and 0 <= j < k < nums1.length.


Example 1:

Input: nums1 = [7,4], nums2 = [5,2,8,9]
Output: 1
Explanation: Type 1: (1,1,2), nums1[1]^2 = nums2[1] * nums2[2]. (4^2 = 2 * 8).
Example 2:

Input: nums1 = [1,1], nums2 = [1,1,1]
Output: 9
Explanation: All Triplets are valid, because 1^2 = 1 * 1.
Type 1: (0,0,1), (0,0,2), (0,1,2), (1,0,1), (1,0,2), (1,1,2).  nums1[i]^2 = nums2[j] * nums2[k].
Type 2: (0,0,1), (1,0,1), (2,0,1). nums2[i]^2 = nums1[j] * nums1[k].
Example 3:

Input: nums1 = [7,7,8,3], nums2 = [1,2,9,7]
Output: 2
Explanation: There are 2 valid triplets.
Type 1: (3,0,2).  nums1[3]^2 = nums2[0] * nums2[2].
Type 2: (3,0,1).  nums2[3]^2 = nums1[0] * nums1[1].
Example 4:

Input: nums1 = [4,7,9,11,23], nums2 = [3,5,1024,12,18]
Output: 0
Explanation: There are no valid triplets.


Constraints:

1 <= nums1.length, nums2.length <= 1000
1 <= nums1[i], nums2[i] <= 10^5







class Solution {
    int count(vector<int> &nums1, vector<int> &nums2) {
        int res = 0;
        unordered_map<int, int> m;
        for (auto b : nums2) m[b]++;
        for (int a : nums1) {
            long target = (long)a * a;
            for (auto &it : m) {
                int b=it.first;
                if (target%b!=0 || m.count(target / b) == 0) continue;
                if (target / b == b) res += m[b] * (m[b] - 1);
                else res += m[b] * m[target / b];
            }
        }
        return res / 2;
    }
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return count(nums1, nums2) + count(nums2, nums1);
    }
};





/*
Type 1 and Type 2 are symmetrical
so we can define a function count(A, B) which returns the count of the Type 1 triples.
The answer is count(A, B) + count(B, A).

For count(A, B),
we can use a unordered_map<int, int> m to store the frequency of the numbers in B.
Then for each number a in A, the target value is a * a.
We traverse the map m to count the triplets.

For each entry (b, cnt) in m:

If target is not divisible by b or target / b is not in m, there is no triplets, skip.
If target / b == b, we need to pick 2 out of m[b] numbers so we can add m[b] * (m[b] - 1) triplets to the answer.
Otherwise, we can add m[b] * m[target / b] triplets to the answer.
Since we count the the pairs in B twice, we need to divide the answer by 2 before returning.

Sourece: https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/discuss/831519/C%2B%2B-O(MN)-with-explanation
*/
