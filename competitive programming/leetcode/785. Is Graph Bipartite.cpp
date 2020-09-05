Given an undirected graph, return true if and only if it is bipartite.

Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B
such that every edge in the graph has one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.
Each node is an integer between 0 and graph.length - 1.
There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

Example 1:
Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation:
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.
Example 2:
Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation:
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent subsets.


Note:

graph will have length in range [1, 100].
graph[i] will contain integers in range [0, graph.length - 1].
graph[i] will not contain i or duplicate values.
The graph is undirected: if any element j is in graph[i], then i will be in graph[j].







class Solution {
public:


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

    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();

        vector<int> color(V, -1);

        for(int i = 0; i < V; i++)
            if(color[i] == -1)
                if (isBipartiteUtil(graph, V, i, color) == false)
                    return false;

        return true;
    }
};
