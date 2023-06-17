Given a string, print the size of the longest possible substring that has exactly K unique characters.
If there is no possible substring then print -1.

Example 1:
Input: S = "aabacbebebe", K = 3
Output: 7
Explanation: "cbebebe" is the longest  substring with K distinct characters.

Example 2:
Input: S = "aaaa", K = 2
Output: -1
Explanation: There's no substring with K distinct characters.

Constraints:
1<=|S|<=10^5
1<=K<=10^5
********************************************************************************










# Approach 1:

class Solution {
public:
    int longestKSubstring(string s, int k) {
        int res = 0;
        int start = 0, end = 0; // start and end of the sliding window

        unordered_map <char, int> freq;
        
        while (end < s.length()) {
            freq[s[end]]++;
            
            if (freq.size() == k) res = max(res, end - start + 1);

            if (freq.size() > k) {
                freq[s[start]]--;
                if (freq[s[start]] == 0) freq.erase(s[start]);
                start++;	// slide the window
            }
            end++;  // increment window size
        }

        return res == 0 ? -1 : res;
    }
};

TC -> O(n), n is the length of the string s
SC -> O(k), k is the maximum number of unique characters in the string s
