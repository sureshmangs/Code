/*
Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.

Example 1:

Input:
S = "aabacbebebe", K = 3
Output: 7
Explanation: "cbebebe" is the longest 
substring with K distinct characters.
​Example 2:

Input: 
S = "aaaa", K = 2
Output: -1
Explanation: There's no substring with K
distinct characters.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestKSubstr() which takes the string S and an integer K as input and returns the length of the longest substring with exactly K distinct characters. If there is no substring with exactly K distinct characters then return -1.


Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).


Constraints:
1<=|S|<=105
1<=K<=105
*/






class Solution{
    public:
    int longestKSubstr(string s, int k) {
        int start = 0, end = 0, n = s.length(), res = 0;
        unordered_map <char, int> m;
        
        while (end < n) {
            m[s[end]]++;
            
            if (m.size() == k) {
                res = max(res, end - start + 1);
            }
            if (m.size() > k) {
                m[s[start]]--;
                if (m[s[start]] == 0) m.erase(s[start]);
                start++;
            }
            end++;
        }
        if (res == 0) return -1;
        else return res;
    }
};
