#include <bits/stdc++.h>
using namespace std;


bool isBipartiteUtil(vector<vector<int> > &graph, int V, int src, vector<int> &color){
    queue<int> q;

	color[src] = 1;
	q.push(src);

	while (!q.empty()){
		int u = q.front();
		q.pop();

		// Find all non-colored adjacent vertices
		for(auto v: graph[u]){
			if(color[v] == -1){ // uncolored
				// Assign alternate color to this adjacent v of u
				color[v] = 1 - color[u];
				q.push(v);
			}
			// v is colored with same color as u
			else if(color[v] == color[u])
				return false;
		}
	}

	// If we reach here, then all adjacent vertices can be colored with alternate color
	return true;
}


bool isBipartite(vector<vector<int> > &graph, int V){
	vector<int> color(V, -1);

	for(int i = 0; i < V; i++)
        if(color[i] == -1)
            if (isBipartiteUtil(graph, V, i, color) == false)
                return false;

	return true;
}


int main(){

	vector<vector<int> >graph { {1,3}, {0,2}, {1,3}, {0,2} };
	int V=graph.size();

	isBipartite(graph, V) ? cout << "Yes" : cout << "No";
	return 0;
}
