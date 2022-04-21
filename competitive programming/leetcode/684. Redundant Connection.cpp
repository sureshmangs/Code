In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, 
with one additional edge added. The added edge has two different vertices chosen from 1 to n, 
and was not an edge that already existed. The graph is represented as an array edges of length n
where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. 
If there are multiple answers, return the answer that occurs last in the input.

 

Example 1:


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:


Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
 

Constraints:

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected.








// dfs, TC -> O(E * (N + E)), SC -> O(N)
class Solution {
public:
    
    bool dfs(vector <int> adj[], int src, int dst, vector <bool> &vis) {
        vis[src] = true;
        
        if (src == dst) return true;
        
        for (auto &v: adj[src]) {
            if (!vis[v] && dfs(adj, v, dst, vis)) return true;
        }
        
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector <int> adj[n];
        vector <int> res;
        
        for (int i = 0; i <  n; i++) {
            vector <bool> vis(n, false);
            
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            
            if (dfs(adj, u, v, vis) == false) {
                // we need this edge u -> v
                adj[u].push_back(v);
                adj[v].push_back(u);
            } else {
                // extra edge
                res = {u + 1, v + 1}; // node value starts from 1
            }
        }
        
        return res; 
    }
};

// For each edge (u, v), 
// traverse the graph with a depth-first search to see if we can connect u to v. 
// If we can, then it must be the duplicate edge
