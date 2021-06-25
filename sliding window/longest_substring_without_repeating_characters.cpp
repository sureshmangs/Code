/*
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces
*/






class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0, n = s.length(), res = 0;
        unordered_map <char, int> m;
        
        while (end < n) {
            if (m.find(s[end]) == m.end()) {
                m[s[end]]++;
                res = max(res, end - start + 1);
            } else {
                while (s[start] != s[end]) {
                    m.erase(s[start]);
                    start++;
                }
                start++; 
            }
            end++;
        }
          
        return res;
    }
};
