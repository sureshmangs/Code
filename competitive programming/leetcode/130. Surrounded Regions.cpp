Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.









class Solution {
public:

    void dfs(vector<vector<char> >& board, int x, int y){
        if(x>=0 && x< board.size() && y>=0 && y< board[0].size() && board[x][y]=='O'){
            board[x][y]='P';
            dfs(board,x-1,y);
            dfs(board,x+1,y);
            dfs(board,x,y-1);
            dfs(board,x,y+1);
        } else return;
    }

    void solve(vector<vector<char>>& board) {
        int rows=board.size();
        if(rows==0) return;
        int cols=board[0].size();
        if(cols==0) return;

        for(int i=0; i<cols;i++){
            if(board[0][i]=='O')    // first row
                dfs(board, 0, i);
            if(board[rows-1][i]=='O')    // last row
                dfs(board, rows-1, i);
        }

        for(int i=0; i<rows;i++){
            if(board[i][0]=='O')    // first col
                dfs(board, i, 0);
            if(board[i][cols-1]=='O')    // last col
                dfs(board, i, cols-1);
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='P') board[i][j]='O';

            }
        }
    }
};
