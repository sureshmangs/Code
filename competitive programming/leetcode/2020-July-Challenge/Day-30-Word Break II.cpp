Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]









string s;int n;
unordered_map<string, int> mp;

bool cut(int start, int end, string a,vector<vector<char> >& dp)
{
    if(start > end)
        return 1;

    if(dp[start][end] != '?')
    {
        if(dp[start][end] == '1')
            return 1;
        return 0;
    }
    string ans;

    for(int i = start; i <= end; i++)
    {
        ans += a[i];
        if(mp.find(ans) != mp.end())
            if(cut(i+1, end, a, dp))
            {
                dp[start][end] = '1';
                return 1;
            }
    }
    dp[start][end] = '0';
    return 0;
}

void backtrack(string s, vector<string> &ans, string yet, int idx)
{
	if(idx == n)
	{
		yet.pop_back();
		ans.push_back(yet);
		return;
	}
	string temp = "";
	for(int i = idx; i < n; i++)
	{
		temp += s[i];
		if(mp.find(temp) != mp.end())
		{
			string ss = yet;
			ss += temp;
			ss += " ";
			backtrack(s, ans, ss, i+1);
		}
	}
}

class Solution {
public:
    vector<string> wordBreak(string A, vector<string>& B) {
        vector<string> ans;
        mp.clear();
        s = A;
        n = A.size();
        for(int i = 0; i < B.size(); i++)
            mp[B[i]] = 1;
        vector<vector<char> > dp(n, vector<char>(n, '?'));
        int x = cut(0, n-1, A, dp);
        if(x == 0)
        	return ans;
        backtrack(A, ans, "", 0);
        return ans;
    }
};
