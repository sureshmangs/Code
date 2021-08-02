Given a string s, partition s such that every substring of the partition 
is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.









class Solution {
public:
    
    bool isPalindrome(int start, int end, string &s) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
    
    void dfs(int start, string &s, vector<string> &curr, vector<vector<string>> &res) {
        if (start == s.length()) {
            res.push_back(curr);
            return;
        }
        
        for (int i = start; i < s.length(); i++) {
            if (isPalindrome(start, i, s)) {
                curr.push_back(s.substr(start, i - start + 1));
                dfs(i + 1, s, curr, res);
                curr.pop_back(); // backtrack
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        
        dfs(0, s, curr, res);
        
        return res;
    }
};
