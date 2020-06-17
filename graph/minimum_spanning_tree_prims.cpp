/*
Given a weighted, undirected and connected graph. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

Input:
The first line of input contains an integer T denoting the number of testcases. Then T test cases follow. The first line of each testcase contains two integers V (starting from 1), E denoting the number of nodes and number of edges. Then in the next line are 3*E space separated values a b w where a, b denotes an edge from a to b and w is the weight of the edge.

Output:
For each test case in a new line print the sum of weights of  the edges of the Minimum Spanning Tree formed of the graph.

User task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function  spanningTree() which takes a graph graph, number of vertices V and the number of edges E as inputs and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree.
Note: Please note that input of graph is 1-based but the adjacency matrix is 0-based.

Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 100
2 <= V <= 1000
V-1 <= E <= (V*(V-1))/2
1 <= a, b <= N
1 <= w <= 1000
Graph is connected and doesn't contain self loops & multiple edges.

Example:
Input:
2
3 3
1 2 5 2 3 3 1 3 1
2 1
1 2 5

Output:
4
5

Example:
Testcase 1:  Sum of weights of edges in the minimum spanning tree is 4.
*/







#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, int E, vector<vector<int>> &graph);
// Driver code

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int> > graph(V, vector<int>(V, INT_MAX));

        while (E--) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout << spanningTree(V, E, graph) << endl;
    }
    return 0;
}
// } Driver Code Ends


// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX

#define INF INT_MAX
typedef pair<int, int> iPair;

int spanningTree(int V, int E, vector<vector<int>> &adj) {
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;     // min heap
    int src=0;
    vector<int> key(V, INF);         // weights
    vector<int> parent(V, -1);       //  u ----> v  edge then u is parent of v
    vector<bool> inMST(V,false);     //  keep track of vertices included in MST

    pq.push({0, src});      // insert source itself in priority queue
    key[src]=0;             // and initialize its key as 0

    while(!pq.empty()){
        int u=pq.top().second;      // pait< key, vertex>
        pq.pop();
        inMST[u]=true;
        for(int x=0; x<V; x++){
            int v=x;
            if(v<=0) continue;
            int w=adj[u][x];

            // If v is not in MST and weight of (u,v) is smaller than current key of v
            if(inMST[v]==false && w<key[v]){
                key[v]=w;
                pq.push({key[v], v});
                parent[v]=u;
            }
        }
    }
    int sum=0;
    for(int i=1;i<V;i++) sum+=key[i];
    return sum;
}
