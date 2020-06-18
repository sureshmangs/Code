/*
Given a Undirected Graph. Check whether it contains a cycle or not.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' testcases follow. Each testcase consists of two lines. Description of testcases are as follows: The First line of each testcase contains two integers 'N' and 'M' which denotes the no of vertices and no of edges respectively. The Second line of each test case contains 'M'  space separated pairs u and v denoting that there is a bidirectional  edge from u to v .

Output:
The method should return 1 if there is a cycle else it should return 0.

User task:
You don't need to read input or print anything. Your task is to complete the function isCyclic which takes the Graph and the number of vertices as inputs and returns true if the given undirected graph contains any cycle. Else, it returns false.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 100
2 <= N <= 104
1 <= M <= (N*(N-1))/2
0 <= u, v <=  N-1
Graph doesn't contain multiple edges and self loops.

Example:
Input:
3
2 1
0 1
4 3
0 1 1 2 2 3
5 4
0 1 2 3 3 4 4 2

Output:
0
0
1
*/






#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> g[], int node, bool vis[], int parent){
    vis[node]=true;
    for(auto it: g[node]){
        if(!vis[it]){
            if(dfs(g, it, vis, node)) return true;
        } else {
            if(it!=parent) return true;
        }
    }
    return false;
}

bool isCyclic(vector<int> g[], int V)
{
   bool vis[V]={false};
   for(int i=0;i<V;i++){
       if(!vis[i])
        if(dfs(g, 0, vis, -1)) return true;
   }
   return false;

}



int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        // array of vectors to represent graph
        vector<int> adj[V];
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << isCyclic(adj, V)<<endl;
    }
}
