Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) is included in the window.
If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

Constraints:
m == s.length
n == t.length
1 <= m, n <= 10^5
s and t consist of uppercase and lowercase English letters.
********************************************************************************










# Approach 1: Sliding Window

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char, int> freq;

        for (auto &x: t) freq[x]++;

        int res = INT_MAX, resIndex = -1, match = 0;
        int start = 0, end = 0; // start and end of the sliding window

        while (end < s.length()) {
            if (freq.find(s[end]) != freq.end()) {
                freq[s[end]]--;
                if (freq[s[end]] == 0) match++;
            }
            while (match == freq.size()) { // windows complete
                if (res > end - start + 1) {
                    res = end - start + 1;
                    resIndex = start;
                }

                if (freq.find(s[start]) != freq.end()) {
                    if (freq[s[start]] == 0) match--;
                    freq[s[start]]++;
                }
                start++;
            }
            end++;
        }
        return res == INT_MAX ? "" : s.substr(resIndex, res);
    }
};

TC -> O(m + n), m, n is the length of the string s, t
SC -> O(k), k is the maximum unique characters in the string t
