Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

Constraints:
1 <= s1.length, s2.length <= 10^4
s1 and s2 consist of lowercase English letters.
********************************************************************************










# Approach 1:

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> freq;

        for (auto &x: s1) freq[x]++;

        int start = 0, end = 0; // start and end of the sliding window
        int match = 0;

        while (end < s2.length()) {
            char right = s2[end];
            if (freq.find(right) != freq.end()) {
                freq[right]--;
                if (freq[right] == 0) match++;
            }

            if (end - start + 1 == s1.length()) { // windows complete
                if (match == freq.size()) return true;
                char left = s2[start];
                if (freq.find(left) != freq.end()) {
                    if (freq[left] == 0) match--;
                    freq[left]++;
                }
                start++;    // slide the window 
            }
            end++;  // increment window size
        }
        return false;
    }
};

TC -> O(n + m), n, m is the length of the string s1, s2
SC -> O(k), k is the maximum unique characters in the string s1

Extra:
	This problem is similar to finding all the anagrams of a string p in string s.
