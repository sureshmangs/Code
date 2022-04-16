There is a bi-directional graph with n vertices, 
where each vertex is labeled from 0 to n - 1 (inclusive). 
The edges in the graph are represented as a 2D integer array edges, 
where each edges[i] = [ui, vi] denotes a bi-directional edge between 
vertex ui and vertex vi. Every vertex pair is connected by at most one edge, 
and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex 
source to vertex destination.

Given edges and the integers n, source, and destination, 
return true if there is a valid path from source to destination, or false otherwise.

 

Example 1:


Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 ? 1 ? 2
- 0 ? 2
Example 2:


Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.
 

Constraints:

1 <= n <= 2 * 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ui, vi <= n - 1
ui != vi
0 <= source, destination <= n - 1
There are no duplicate edges.
There are no self edges.









// dfs (TLE -> due to stack overflow), TC -> (V + E)

class Solution {
public:
    
    bool dfs(vector <int> adj[], int src, int dst, vector <bool> vis) {
        vis[src] = true;
        
        if (src == dst) return true;
        
        for (auto v: adj[src]) {
            if (!vis[v] && dfs(adj, v, dst, vis)) return true; 
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector <int> adj[n];
        
        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector <bool> vis(n, false);
        
        return dfs(adj, source, destination, vis);
    }
};










// iterative dfs TC -> O(V + E)

class Solution {
public:
    
    bool dfs(vector <int> adj[], int src, int dst, vector <bool> vis) {
        stack <int> s;
        s.push(src);
        
        while (!s.empty()) {
            src = s.top();
            s.pop();
            vis[src] = true;
            
            if (src == dst) return true;
            
            for (auto v: adj[src]) {
                if (!vis[v]) s.push(v);
            }
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector <int> adj[n];
        
        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector <bool> vis(n, false);
        
        return dfs(adj, source, destination, vis);
    }
};











// bfs TC -> O(V + E)

class Solution {
public:
    
    bool bfs(vector <int> adj[], int src, int dst, vector <bool> vis) {
        queue <int> q;
        q.push(src);
        
        while (!q.empty()) {
            src = q.front();
            q.pop();
            vis[src] = true;
            
            if (src == dst) return true;
            
            for (auto v: adj[src]) {
                if (!vis[v]) q.push(v);
            }
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector <int> adj[n];
        
        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector <bool> vis(n, false);
        
        return bfs(adj, source, destination, vis);
    }
};
