You are given a string s and an integer k, a k duplicate removal consists of 
choosing k adjacent and equal letters from s and removing them, causing the left 
and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. 
It is guaranteed that the answer is unique.

 

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
Example 2:

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
Example 3:

Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
 

Constraints:

1 <= s.length <= 105
2 <= k <= 104
s only contains lower case English letters.












// TLE
// TC -> O(n^2)
// SC-> O(n)

class Solution {
public:
    bool isAllEqual (string s) {
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] != s[i + 1]) return false;
        }
        return true;
    }
    string removeDuplicates(string s, int k) {
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            res += s[i];
            if (res.size() >= k) {
                if (isAllEqual(res.substr(res.size() - k, k)))
                    res.erase(res.size() - k, k);
            }
        }
         return res;
    }
};









// TC -> O(n)
// SC-> O(n)

class Solution {
public:
    string removeDuplicates(string s, int k) {
        string res = "";
        stack <pair<char, int>> st;
        
        for (int i = 0; i < s.length(); i++) {
            if (!st.empty() && st.top().first == s[i]) st.top().second++;
            else st.push({s[i], 1});
            
            if (!st.empty() && st.top().second == k) st.pop();
        }
        
        while (!st.empty()) {
            res.append(st.top().second, st.top().first);
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
