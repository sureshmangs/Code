There are n servers numbered from 0 to n - 1 connected by undirected server-to-server 
connections forming a network where connections[i] = [ai, bi] represents a connection 
between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 
Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]
 

Constraints:

2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.










// Approach 1: Brute Force
// Create a graph, traverse over the edges and remove the current edge from the graph
// and check via a dfs traversal whether all the nodes are still rechable from any node to any other
// if not, then it's a critical connection/
// TC -> O(E(V + E))



// Approach 2:
// TC -> O(V + E)

class Solution {
public:
    vector <bool> visited;
    vector <int> disc, low, parent;
    vector<vector<int>> criticalConn;
    int id = 0;
    
    void dfs(int u, vector <int> graph[]) {
        visited[u] = true;
        disc[u] = id;
        low[u] = id;
        id++;
        
        for (auto v: graph[u]) {
            if (!visited[v]) {
                parent[v] = u;
                dfs(v, graph);
                low[u] = min(low[u], low[v]);
                
                if (low[v] > disc[u]) {
                    criticalConn.push_back({u, v});
                }
            } else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
        
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector <int> graph[n];
        
        for (auto connection: connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }
        
        visited.resize(n, false);
        disc.resize(n, 0);
        low.resize(n, 0);
        parent.resize(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) dfs(i, graph);
        }
        
        return criticalConn;
    }
};
