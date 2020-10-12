Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/



Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"


Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.





class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a'] += 1;
        }

        string res = "";
        vector<bool> used(26, false);
        for (char c : s) {
            if (used[c - 'a']) {
                count[c - 'a'] -= 1;
                continue;
            }
            while (!res.empty() and c < res.back() and count[res.back() - 'a'] > 0) {
                used[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(c);
            used[c - 'a'] = true;
            count[c - 'a'] -= 1;
        }
        return res;
    }
};
