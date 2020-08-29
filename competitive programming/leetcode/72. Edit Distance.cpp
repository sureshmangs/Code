Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')





// Recursive (TLE)

class Solution {
public:

    int editDistance(string word1, string word2, int m, int n){
        if(m==0) return n;
        if(n==0) return m;

        if(word1[m-1]==word2[n-1]) return editDistance(word1, word2, m-1, n-1);
        return 1 + min(editDistance(word1, word2, m-1, n), min(editDistance(word1, word2, m, n-1), editDistance(word1, word2, m-1, n-1)));
    }

    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();

        return editDistance(word1, word2, m, n);
    }
};


// Recursive (memoized)

class Solution {
public:

    int editDistance(string word1, string word2, int m, int n, vector<vector<int> > &dp){
        if(m==0) return n;
        if(n==0) return m;

        if(dp[m-1][n-1]!=-1) return dp[m-1][n-1];

        if(word1[m-1]==word2[n-1]) return  dp[m-1][n-1]=editDistance(word1, word2, m-1, n-1, dp);
        return dp[m-1][n-1]= 1 + min(editDistance(word1, word2, m-1, n, dp), min(editDistance(word1, word2, m, n-1, dp), editDistance(word1, word2, m-1, n-1, dp)));
    }

    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();

        vector<vector<int> > dp(m+1, vector<int> (n+1, -1));

        return editDistance(word1, word2, m, n, dp);
    }
};



// DP

class Solution {
public:

    int editDistance(string word1, string word2, int m, int n){
        int dp[m+1][n+1];

        for(int i=0;i<m+1;i++) dp[i][0]=i;
        for(int j=0;j<n+1;j++) dp[0][j]=j;

        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]= 1+ min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
       return dp[m][n];
    }

    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();

        return editDistance(word1, word2, m, n);
    }
};
