#include<bits/stdc++.h>
using namespace std;

#define V 4

void printSolution(int color[]){
	for(int i = 0; i < V; i++)
		cout<<color[i]<<" ";
}


bool isSafe(int v, bool graph[V][V],int color[], int c){
    // If adjacent vertices are of same color return false
	for (int i = 0; i < V; i++)
		if(graph[v][i] && c == color[i])
			return false;
	return true;
}

bool graphColoringUtil(bool graph[V][V], int m, int color[], int v){
	// If all vertices are assigned a color then return true */
	if(v == V)
      return true;

	// Consider this vertex v and try out different colors
	for(int c = 1; c <= m; c++) {
		// Check if assignment of color c to v is fine
		if(isSafe(v, graph, color, c)){
			color[v] = c;

			// recur to assign colors to rest of the vertices
			if (graphColoringUtil(graph, m, color, v + 1) == true)
				return true;

			// If assigning color c doesn't lead to a solution then remove it
			color[v] = 0;
		}
	}

	// If no color can be assigned to this vertex
	return false;
}


bool graphColoring(bool graph[V][V], int m){
	// Initialize all color values as 0.
	// This initialization is needed correct functioning of isSafe()
	int color[V];
	for(int i = 0; i < V; i++)
		color[i] = 0;

	if (graphColoringUtil(graph, m, color, 0) == false) {   // <graph, m, color, vertex>
		cout<<"Solution does not exist";
		return false;
	}
	else printSolution(color);
	return true;
}



int main(){
	/* Given graph

	(3)---(2)
	|    / |
	|   /  |
	|  /   |
	(0)---(1)

	*/

	bool graph[V][V] = {
		{ 0, 1, 1, 1 },
		{ 1, 0, 1, 0 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 0 },
	};

	int m = 3; // Number of colors
	graphColoring(graph, m);
	return 0;
}
