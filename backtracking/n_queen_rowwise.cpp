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
    // only check the upper portion of board as no queen is placed in lower side
    // vertical col check
    for(int i=0;i<row;i++)
        if(board[i][col]) return false;
    // upper left diagonal check
    for(int i=row, j=col; i>=0 && j>=0; i--, j--)
        if(board[i][j]) return false;
    // upper right diagonal check
    for(int i=row, j=col; i>=0 && j<n; i--, j++)
        if(board[i][j]) return false;

    return true;
}

bool nQueen(int board[MAX][MAX], int n, int row){
    if(row >= n){
        printBoard(board, n);       // base case
        return true;
    }
    bool res = false;
    for(int i=0;i<n;i++){
        if(isSafe(board, row, i, n)){
            board[row][i]=1;
            res= nQueen(board, n, row+1) || res;
            // if code reaches here, then backtrack
            board[row][i]=0;
        }
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    int board[MAX][MAX];
    memset(board, 0, sizeof(board));

    if(!nQueen(board, n, 0))   // starting row --> 0   -> we are placing queens column wise
        cout<<"No solution exists\n";

    return 0;
}
