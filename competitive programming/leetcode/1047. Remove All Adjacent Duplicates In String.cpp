Given a string S of lowercase letters, a duplicate removal consists of 
choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.  
It is guaranteed the answer is unique.



Example 1:

Input: "abbaca"
Output: "ca"
Explanation:
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal,
and this is the only possible move.  The result of this move is that the string is "aaca", 
of which only "aa" is possible, so the final string is "ca".


Note:

1 <= S.length <= 20000
S consists only of English lowercase letters.










// TC -> O(n)
// SC -> O(n)

class Solution {
    public:
    string removeDuplicates(string S) {
        stack<char> s;
        int n = S.length();
        s.push(S[0]);
        for (int i = 1; i < n; i++) {
            if (!s.empty() && s.top() == S[i])
                s.pop();
            else
                s.push(S[i]);
        }
        string res = "";

        while (!s.empty()) {
            res = s.top() + res;
            s.pop();
        }
        return res;
    }
};











// TC -> O(n)
// SC -> O(n)

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        string tmp = "";
        
        for (int i = 0; i < n; i++) {
            if (tmp.length() == 0) tmp += s[i];
            else if (tmp[tmp.length() - 1] != s[i]) tmp += s[i];
            else tmp.erase(tmp.length() - 1);
        }
        
        return tmp;
    }
};














// TC -> O(n)
// SC -> O(1)

class Solution {
    public:
    string removeDuplicates(string S) {
        int k = 0, n = S.length();
        for (int i = 0; i < n; i++, k++) {
            S[k] = S[i];
            if (k > 0 && S[k - 1] == S[k]) k -= 2;
        }
        return S.substr(0, k);
    }
};

