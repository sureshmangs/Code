Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"











class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();

        vector<vector<bool> >dp(n, vector<bool> (n, 0));

        int start=0;  // start of lps
        int maxLen=1;

        // All substrings of length 1 are palindromes
        for(int i=0;i<n;i++) dp[i][i]=true;

        // check for sub-string of length 2
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                start=i;
                maxLen=2;
            }
        }

        // Check for lengths greater than 2, k is length of substring
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j=i+k-1;
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    start=i;
                    maxLen=k;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};


/*
dp[i][j] will be false if substring  str[i..j] is not palindrome.
Else dp[i][j] will be true



Time complexity: O(n^2).
Auxiliary Space: O(n^2).
*/



/*
Brute Force Approach
The simple approach is to check each substring whether the substring is a palindrome or not
*/
