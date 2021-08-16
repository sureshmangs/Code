Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1
 

Constraints:

1 <= s.length <= 2000
s consists of lower-case English letters only.








// Recusive Memoized + Optimized (Accepted)

class Solution {
public:
    vector<vector<int>> dp;
    
    bool isPalindrome(int start, int end, string &s) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
    

    int solve (int i, int j, string &s){    
        if(i>=j || isPalindrome(i, j, s)) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int res = INT_MAX;
        
        for (int k = i; k < j; k++){
            if (isPalindrome(i, k, s)){                         
                int tmp = solve (k + 1, j, s) + 1;
                res = min (res, tmp);
            }
        }
        
        return dp[i][j] = res;
    }
    
    int minCut(string s) {
        int n = s.length();
        
        dp.resize(n, vector<int> (n, -1));
            
        return solve (0, n - 1, s);
    }
};













// REcursive Memoized (TLE)

class Solution {
public:
    vector<vector<int>> dp;
    
    bool isPalindrome(int start, int end, string s) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
    
    int solve(int i, int j, string s) {
        if (i >= j) return 0;
        
        if(isPalindrome(i, j, s)) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int res = INT_MAX;
        
        int left, right;
        
        for (int k = i; k <= j - 1; k++) {
            if (dp[i][k] != -1) left = dp[i][k];
            else dp[i][k] = left = solve(i, k, s);
            
            if (dp[k + 1][j] != -1) right = dp[k + 1][j];
            else dp[k + 1][j] = right = solve(k + 1, j, s);
            
            int tmp = left  + right + 1;
            res = min(res, tmp);
        }
        
        return dp[i][j] = res;
    }
    
    int minCut(string s) {
        int n = s.length();
        dp.resize(n, vector<int> (n, -1));
        
        return solve(0, n - 1, s);
    }
};












// All palindrome finding - backtracking(TLE)

class Solution {
public:
    
    bool isPalindrome(int start, int end, string s) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
    
    void dfs(int start, string s, vector<string> &cur, vector<vector<string>> &all) {
        if (start == s.length()) {
            all.push_back(cur);
            return;
        }
        
        for (int i = start; i <  s.length(); i++) {
            if (isPalindrome(start, i, s)) {
                cur.push_back(s.substr(start, i - start + 1));
                dfs(i + 1, s, cur, all);
                cur.pop_back();  // backtrack
            }
        }
    }
    
    int minCut(string s) {
        vector<vector<string>> all;
        vector<string> cur;
        
        dfs(0, s, cur, all);
        
        int res = INT_MAX;
        
        for (auto &x: all) {
            res = min(res, (int)x.size());
        }
        
        return res - 1;
    }
};
