Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.



Example:

Input:
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]


Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
   Hide Hint #1
You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?
   Hide Hint #2
If the current candidate does not exist in all words' prefix,
you could stop backtracking immediately.
What kind of data structure could answer such query efficiently?
Does a hash table work? Why or why not? How about a Trie?
If you would like to learn how to implement a basic trie,
please work on this problem: Implement Trie (Prefix Tree) first.











class Solution {
public:
    struct TrieNode {
        int ew;   // end of word
        struct TrieNode* child[26];
        string word;
    };

    struct TrieNode* createNode(){
        struct TrieNode* newNode=new TrieNode;
        newNode->ew=0;
        newNode->word="";
        for(int i=0;i<26;i++)
            newNode->child[i]=NULL;
        return newNode;
    }

    void insert(struct TrieNode* root, string word){
        struct TrieNode* cur=root;
        int wordLen=word.length();
        for(int i=0;i<wordLen;i++){
            int index=word[i]-'a';
            // create new node if not already exist
            if(cur->child[index]==NULL)
                cur->child[index]=createNode();
            // point to new node
            cur=cur->child[index];
        }
        cur->ew+=1; // end of word
        cur->word=word;
    }


    void solve(vector<vector<char>>& board, int i, int j, int row, int col, vector<string> &res, struct TrieNode* cur){
        // base case
        int index=board[i][j]-'a';
        if(board[i][j]=='$' || cur->child[index]==NULL) return;

        cur=cur->child[index];
        if(cur->ew>0){
             res.push_back(cur->word);
            cur->ew-=1;
        }

        char ch=board[i][j];
        board[i][j]='$'; // mark visited

        if(i>0) // top
            solve(board, i-1, j, row, col, res, cur);
        if(i<row-1) // down
            solve(board, i+1, j, row, col, res, cur);
        if(j>0) //left
            solve(board, i, j-1, row, col, res, cur);
        if(j<col-1) // right
            solve(board, i, j+1, row, col, res, cur);

        board[i][j]=ch;


    }

    static bool comp(string a, string b){
        int tmp=a.compare(b);
        return tmp<=0 ? true: false;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int row=board.size();
        int col=board[0].size();
        vector<string> res;

        struct TrieNode* root=createNode();  // root

        // insert words in TRIE
        int wordLen=words.size();
        for(int i=0;i<wordLen;i++)
            insert(root, words[i]);

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                solve(board, i, j, row, col, res, root);
            }
        }

        sort(res.begin(), res.end(), comp);

        return res;
    }
};
