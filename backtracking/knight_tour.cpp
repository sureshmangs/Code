#include <bits/stdc++.h>
using namespace std;

#define N 8

int isSafe(int x, int y, int sol[N][N]){
	return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

void printSolution(int sol[N][N]){
    for(int x = 0; x < N; x++){
		for (int y = 0; y < N; y++)
			cout<<sol[x][y]<<" ";
		cout<< endl;
	}
}


int solveKT(int x, int y, int movei,int sol[N][N], int xMove[N],int yMove[N]){
	int k, next_x, next_y;
	if (movei == N*N)
		return 1;

	// Try all next moves from the current coordinate x, y
	for (k = 0; k < 8; k++)
	{
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if (isSafe(next_x, next_y, sol)){
			sol[next_x][next_y] = movei;
			if (solveKT(next_x, next_y,movei + 1, sol,xMove, yMove) == 1)
				return 1;
			else sol[next_x][next_y] = -1;   // backtrack
		}
	}
	return 0;
}


int main(){
	int sol[N][N];

	memset(sol, -1, sizeof(sol));


	// xMove[] and yMove[] define next move of Knight
	// xMove[] is for next value of x coordinate
	// yMove[] is for next value of y coordinate */
	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	// Since the Knight is initially at the first block
	sol[0][0] = 0;

	// Start from 0,0 and explore all tours using solveKT
	if (solveKT(0, 0, 1, sol, xMove, yMove) == 0){  // <x, y, move number, output, xmoves, ymoves>
		cout << "Solution does not exist";
	}
	else printSolution(sol);
}

