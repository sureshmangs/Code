Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false



// Trie (TLE)

class Solution {
public:

    struct TrieNode {
        bool ew; // end of word
        struct TrieNode* child[26];
    };

    TrieNode* createNode(){
        TrieNode* newNode= new TrieNode;
        newNode->ew=false;
        for(int i=0;i<26;i++)
            newNode->child[i]=NULL;
        return newNode;
    }


    void insert(string word, TrieNode* root){
        TrieNode* curr=root;
        int wordLen=word.length();
        for(int i=0;i<wordLen;i++){
            int index=word[i]-'a';
            if(curr->child[index]==NULL)
                curr->child[index]=createNode();
            curr=curr->child[index];
        }
        curr->ew=true;
    }

    bool search(string word, TrieNode* root){
        TrieNode* curr=root;
        int wordLen=word.length();
        for(int i=0;i<wordLen;i++){
            int index=word[i]-'a';
            if(curr->child[index]==NULL) return false;
            curr=curr->child[index];
        }
        return (curr!=NULL && curr->ew);

    }

    bool wordBreakUtil(string s, TrieNode* root){
        int size=s.length();
        if(size==0) return true;

        for(int i=1;i<=size;i++){
            if( search(s.substr(0, i), root) && wordBreakUtil(s.substr(i, size-i), root ))
                return true;
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n=wordDict.size();
        TrieNode* root= createNode();
        for(int i=0;i<n;i++){
            insert(wordDict[i], root);
        }

        return wordBreakUtil(s, root);
    }
};















// Recursive (TLE)

class Solution {
public:

    bool searchDict(string word, vector<string> &wordDict){
        for(auto &x: wordDict)
            if(word==x)
                return true;
        return false;
    }

    bool wordBreakUtil(string s, vector<string> &wordDict){
        int size=s.length();
        if(size==0) return true;
        for(int i=1;i<=size;i++){
            if(searchDict(s.substr(0, i), wordDict) && wordBreakUtil(s.substr(i, size-i), wordDict) )
              return true;
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return wordBreakUtil(s, wordDict);
    }
};






// Recursive (memoized)

class Solution {
public:

    unordered_map<string, bool> memo;

    bool searchDict(string word, vector<string> &wordDict){
        for(auto &x: wordDict)
            if(word==x)
                return true;
        return false;
    }

    bool wordBreakUtil(string s, vector<string> &wordDict){
        int size=s.length();
        if(size==0) return true;
        if(memo.find(s)!=memo.end()) return memo[s];
        for(int i=1;i<=size;i++){
            if(searchDict(s.substr(0, i), wordDict) && wordBreakUtil(s.substr(i, size-i), wordDict) )
              return memo[s]=true;
        }
        return memo[s]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return wordBreakUtil(s, wordDict);
    }
};




// Dynamic Programming

// dp[i] denotes that the s.substr(0,i) is available in our dictionary

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>dictSet;
        for(auto &x: wordDict)
            dictSet.insert(x);

        int n=s.length();

        vector<bool> dp(n+1, false);

        dp[0]=true;

        for(int len=1;len<=n;len++){
            for(int i=0;i<len;i++){
                if(dp[i] && dictSet.find(s.substr(i, len-i))!=dictSet.end()){
                    dp[len]=true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
