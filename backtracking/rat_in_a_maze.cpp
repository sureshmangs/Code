#include<bits/stdc++.h>
using namespace std;

#define N 4


void printSolution(int sol[N][N]){
	for(int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout<<sol[i][j]<<" ";
		cout<<endl;
	}
}


bool isSafe(int maze[N][N], int x, int y){
   return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y]);
}


bool solveMaze(int maze[N][N], int x,int y, int sol[N][N]){
	// if we reached our destination
	if(x == N-1 && y == N-1 && maze[x][y] == 1){
		sol[x][y] = 1;
		return true;
	}

	// Check if maze[x][y] is valid
	if (isSafe(maze, x, y) == true) {

		sol[x][y] = 1;   // mark x, y as part of solution path

		// Move forward in x direction
		if (solveMaze(maze, x + 1, y, sol) == true)
			return true;

		// If moving in x direction doesn't give solution then move down in y direction
		if (solveMaze(maze, x, y + 1, sol) == true)
			return true;

		// If none of the above movements work then BACKTRACK: unmark x, y as part of solution path
		sol[x][y] = 0;
		return false;
	}

	return false;
}


int main(){
	int maze[N][N] = { { 1, 0, 0, 0 },
					{ 1, 1, 0, 1 },
					{ 0, 1, 0, 0 },
					{ 1, 1, 1, 1 } };

    int sol[N][N];
	memset(sol, 0, sizeof(sol));

	if(solveMaze(maze, 0, 0, sol)== false){  // <maze, start x, start y, output matrix>
		cout<<"Solution doesn't exist";
	} else {
	    printSolution(sol);
	}

	return 0;
}
