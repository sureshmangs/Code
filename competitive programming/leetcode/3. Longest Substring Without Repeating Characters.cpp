Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.












class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int res=0;
        vector<int> lastIndex(128, -1);   // stores last index of the visited characters
        int i=0;
        for(int j=0;j<n;j++){
            i=max(i, lastIndex[s[j]]+1);
            res=max(res, j-i+1);
            lastIndex[s[j]]=j;
        }
        return res;
    }
};




/*
Approach 1 O(n3)
Consider all substrings one by one and check for each substring whether it contains all unique characters or not


Approach 2 O(n2)
Using Sliding Window Technique.
Whenever we see repetition, we remove the previous occurrence and slide the window forward
