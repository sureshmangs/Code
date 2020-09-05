#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define V 4


void floydWarshall(int graph[][V]){
	int dist[V][V]; // resultant matrix

    // Initialize dist matrix, similar to given matrix
	for(int i = 0; i < V; i++)
		for(int j = 0; j < V; j++)
			dist[i][j] = graph[i][j];

	for(int k = 0; k < V; k++){
		// Pick all vertices as source one by one
		for(int i = 0; i < V; i++){
			// Pick all vertices as destination for the above picked source
			for (int j = 0; j < V; j++){
				// If vertex k is on the shortest path from
				// i to j, then update the value of dist[i][j]
				if(dist[i][k]!=INF && dist[k][j]!=INF && dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	// Print the shortest distance matrix
	for(int i = 0; i < V; i++){
		for (int j = 0; j < V; j++){
			if (dist[i][j] == INF)
				cout<<"INF"<<"	 ";
			else
				cout<<dist[i][j]<<"	 ";
		}
		cout<<endl;
	}
}

int main(){

	/*
             10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)

    */

	int graph[V][V] = { {0, 5, INF, 10},
						{INF, 0, 3, INF},
						{INF, INF, 0, 1},
						{INF, INF, INF, 0}
					};

	floydWarshall(graph);
	return 0;
}



// Time Complexity: O(V^3)
