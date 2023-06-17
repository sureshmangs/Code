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
 

Constraints:
0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.
********************************************************************************










# Approach 1: Sliding Window

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int start = 0, end = 0; // start and end of the sliding window

        unordered_map <char, int> freq;
        
        while (end < s.length()) {
            if (freq.find(s[end]) == freq.end()) {
                freq[s[end]]++;
                res = max(res, end - start + 1);
            } else {
                while (s[start] != s[end]) {
                    freq.erase(s[start]);
                   start++;	// slide the window
                }
                start++; 
            }
            end++;  // increment window size
        }

        return res;
    }
};

TC -> O(n), n is the length of the string s
SC -> O(k), k is the maximum number of unique characters in the string s
********************************************************************************










# Approach 2: Sliding Window Optimized

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        vector<int> lastIndex(128, -1);   // stores last index of the visited characters
        int start = 0, end = 0;
        while (end < s.length()) {
            start = max(start, lastIndex[s[end]] + 1); // using max because for a new character start again becomes 0
            res = max(res, end - start + 1);
            lastIndex[s[end]] = end;
            end++;
        }
        return res;
    }
};

TC -> O(n), n is the length of the string s
SC -> O(128), for 128 unique characters or O(1)

Extra:
Commonly used tables are:
	int[26]  for Letters 'a' - 'z' or 'A' - 'Z'
	int[128] for ASCII
	int[256] for Extended ASCII
