Given two strings s and p, return an array of all the start indices of p's anagrams in s. 
You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Example 1:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

Constraints:
1 <= s.length, p.length <= 3 * 10^4
s and p consist of lowercase English letters.
********************************************************************************










# Approach 1:

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> freq;

        for (auto &x: p) freq[x]++;

        int start = 0, end = 0; // start and end of the sliding window
        int match = 0;

        while (end < s.length()) {
            char right = s[end];    // rightmost character ofthe window
            if (freq.find(right) != freq.end()) {
                freq[right]--;
                if (freq[right] == 0) match++;  // complete match for a unique character found
            }
            if (end - start + 1 == p.length()) { // windows complete
                if (match == freq.size()) res.push_back(start);		// anagram found
                char left = s[start];	// leftmost character ofthe window
                if (freq.find(left) != freq.end()) {
                    if (freq[left] == 0) match--;
                    freq[left]++;
                }
                start++;    // slide the window
            }
            end++;  // increment window size
        }

        return res;
    }
};

TC -> O(n + m), n, m is the length of the string s, p
SC -> O(26), 26 entries in the map or O(1)
