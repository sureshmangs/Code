Given a string s and an integer k, return the maximum number of vowel
letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

Example 1:
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

Example 2:
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.

Example 3:
Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.

Constraints:
1 <= s.length <= 10^5
s consists of lowercase English letters.
1 <= k <= s.length
********************************************************************************










# Approach 1: Sliding Window

class Solution {
public:
    bool isVowel (char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    int maxVowels(string s, int k) {
        int res = 0, vowel = 0;
        int start = 0, end = 0; 	// start and end of the sliding window

        while (end < s.length()) {
            if (isVowel(s[end])) vowel++;

            if (end - start + 1 == k) { // window complete
                res = max(res, vowel);
                if (isVowel(s[start])) vowel--;
                start++;	// slide the window
            }
            end++;  // increment window size
        }

        return res;
    }
};

TC -> O(n), n is the length of string s
SC -> O(1)
