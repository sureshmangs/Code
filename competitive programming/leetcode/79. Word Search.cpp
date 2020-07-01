Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.


Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3










class Solution {
public:

    bool dfs(int i, int j, vector<vector<char> > &board, int count, string word, vector<vector<bool> > &vis){
        //base case
        if(count==word.length()) return true;

        // boundary check
        if(i<0 || i>=board.size() || j<0 || j>= board[0].size() || board[i][j]!=word[count] || vis[i][j])
            return false;

        vis[i][j]=true;

        if(dfs(i-1, j, board, count+1, word, vis)
          || dfs(i, j+1, board, count+1,word, vis)
          || dfs(i+1, j, board, count+1, word, vis)
          || dfs(i, j-1, board, count+1, word, vis))
                return true;

        vis[i][j]=false; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        vector<vector<bool> > vis(row, vector<bool> (col, false));

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0] && dfs(i, j, board, 0, word, vis))
                    return true;
            }
        }
         return false;
    }

};
