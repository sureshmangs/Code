/*
Given a Directed Graph. Find any Topological Sorting of that Graph.

Input:
The first line of input takes the number of test cases then T test cases follow . 
Each test case contains two lines. The first  line of each test case  contains two integers E and V 
representing no of edges and the number of vertices. Then in the next line are E  pairs of integers u, v 
representing an edge from u to v in the graph.

Output:
For each test case output will be 1 if the topological sort is done correctly else it will be 0.

Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort() 
which takes the adjacency list of the Graph and the number of vertices (N) as inputs are returns 
an array consisting of a the vertices in Topological order. As there are multiple Topological 
orders possible, you may return any of them.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 100
2 <= V <= 104
1 <= E <= (N*(N-1))/2
0 <= u, v <= N-1
Graph doesn't contain multiple edges, self loops and cycles.
Graph may be disconnected.

Example:
Input
2
6 6
5 0 5 2 2 3 4 0 4 1 1 3
3 4
3 0 1 0 2 0

Output:
1
1

Explanation:
Testcase 1: The output 1 denotes that the order is valid.  So, if you have implemented your function correctly, then output would be 1 for all test cases.
*/







#include <bits/stdc++.h>

using namespace std;

vector <int> topoSort(int N, vector<int> adj[]);

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector <int> res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}// } Driver Code Ends

















// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/

stack <int> s;

void dfs(vector<int> adj[],int node, vector<bool> &vis){
    vis[node] = true;
    for (auto x: adj[node]){
        if(!vis[x])
            dfs(adj, x, vis);
    }
    s.push(node);
}

vector <int> topoSort(int V, vector<int> adj[]) {
    vector <bool> vis(V, false);
    for (int i = 0; i < V; i++){
        if (!vis[i])
         dfs(adj, i, vis);
    }
    vector <int> res;
    
    while (!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    
    return res;
}
