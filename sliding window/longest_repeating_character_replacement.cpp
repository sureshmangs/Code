You are given a string s and an integer k.
You can choose any character of the string and change it to any other uppercase English character.
You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
 
Constraints:
1 <= s.length <= 10^5
s consists of only uppercase English letters.
0 <= k <= s.length
********************************************************************************










# Approach 1: Sliding Window

class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0, maxRepeatingLetterCnt = 0;
        int start = 0, end = 0; // start and end of the sliding window

        unordered_map<char, int> freq;

        while (end < s.length()) {
            freq[s[end]]++;
            maxRepeatingLetterCnt = max(maxRepeatingLetterCnt, freq[s[end]]);

            // length of sliding window - maxRepeatingLetterCnt are all the characters other than
            // the maxRepeatingLetter in the current window which can be replaced, if their size
            // becomes greater than k, then the sliding windows has to be shrunk
            while ((end - start + 1) - maxRepeatingLetterCnt > k) {
                freq[s[start]]--;
                start++;    // decrement window size
        		// No need to decrement the maxRepeatingLetterCnt as it won't affect the final result
        		// The window size or result will only increase when maxRepeatingLetterCnt is increasing
            }
            res = max(res, end - start + 1);
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
    int characterReplacement(string s, int k) {
        int res = 0, maxRepeatingLetterCnt = 0;
        int start = 0, end = 0; // start and end of the sliding window

        unordered_map<char, int> freq;

        while (end < s.length()) {
            freq[s[end]]++;
            maxRepeatingLetterCnt = max(maxRepeatingLetterCnt, freq[s[end]]);

            // length of sliding window - maxRepeatingLetterCnt are all the characters other than
            // the maxRepeatingLetter in the current window which can be replaced, if their size
            // becomes greater than k, then the sliding windows has to be shrunk
            
            // no while loop required as we are decreasing the size of the window, so the winodw
			// might still have unwanted characters but as it's size is lower so it won't affect the
			// final result
            if ((end - start + 1) - maxRepeatingLetterCnt > k) {
                freq[s[start]]--;
                start++;    // decrement window size
        		// No need to decrement the maxRepeatingLetterCnt as it won't affect the final result
        		// The window size or result will only increase when maxRepeatingLetterCnt is increasing
            }
            res = max(res, end - start + 1);
            end++;  // increment window size
        }

        return res;
    }
};

TC -> O(n), n is the length of the string s
SC -> O(k), k is the maximum number of unique characters in the string s
