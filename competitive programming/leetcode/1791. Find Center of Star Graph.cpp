There is an undirected star graph consisting of n nodes labeled from 1 to n.
A star graph is a graph where there is one center node and exactly n - 1 edges 
that connect the center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi] 
indicates that there is an edge between the nodes ui and vi. 
Return the center of the given star graph.

 

Example 1:


Input: edges = [[1,2],[2,3],[4,2]]
Output: 2
Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.
Example 2:

Input: edges = [[1,2],[5,1],[1,3],[1,4]]
Output: 1
 

Constraints:

3 <= n <= 105
edges.length == n - 1
edges[i].length == 2
1 <= ui, vi <= n
ui != vi
The given edges represent a valid star graph.





// using indegree concept

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        
        vector <int> adj[n + 1];
        
        for (auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        for (int i = 1; i < n + 1; i++) {
            if (n - 1 == adj[i].size()) return i;
        }
        
        return -1; // no star
    }
};








// star node will be a part of all the edges
// star node will have (n - 1) indegree and also the edges.size() is equal to (n - 1)

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a = edges[0][0];
        int b = edges[0][1];
        int c = edges[1][0];
        int d = edges[1][1];
        
        if (a == c || a == d) return a;
        else return b;
    }
};
