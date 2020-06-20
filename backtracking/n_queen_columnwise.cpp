#include<bits/stdc++.h>
using namespace std;

#define MAX 10

void printBoard(int board[MAX][MAX], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(int board[MAX][MAX], int row, int col, int n){
    // only check the left portion of board as no queen is placed in right side
    // horizontal row check
    for(int i=0;i<col;i++)
        if(board[row][i]) return false;
    // upper left diagonal check
    for(int i=row, j=col; i>=0 && j>=0; i--, j--)
        if(board[i][j]) return false;
    // lower left diagonal check
    for(int i=row, j=col; i<n && j>=0; i++, j--)
        if(board[i][j]) return false;

    return true;
}

bool nQueen(int board[MAX][MAX], int n, int col){
    if(col >= n){
        printBoard(board, n);       // base case
        return true;
    }
    bool res = false;
    for(int i=0;i<n;i++){
        if(isSafe(board, i, col, n)){
            board[i][col]=1;
            res= nQueen(board, n, col+1) || res;
            // if code reaches here, then backtrack
            board[i][col]=0;
        }
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    int board[MAX][MAX];
    memset(board, 0, sizeof(board));

    if(!nQueen(board, n, 0))   // starting col --> 0   -> we are placing queens column wise
        cout<<"No solution exists\n";

    return 0;
}
