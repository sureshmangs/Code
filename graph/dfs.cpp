#include<bits/stdc++.h>
using namespace std;

void adjListGraph(vector<int> adj[], int s, int d){
    // undirected graph
    adj[s].push_back(d);
    adj[d].push_back(s);
}

void dfs(vector<int> adj[], int src, bool vis[]){
    vis[src] = true;
    cout << src << " ";
    for (auto x : adj[src]) { 
        if (!vis[x]){
            dfs(adj, x, vis);
        }
    }
}

// Iterative dfs
void dfsIterative(vector<int> adj[], int src, bool vis[]){
    stack <int> s;
    s.push(src);
    
    while (!s.empty()) {
    	src = s.top();
    	s.pop();
    	vis[src] = true;
    	cout << src << " ";
    	
    	for (auto x: adj[src]) {
    		if (!vis[x]) s.push(x);
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int v, e;
    cin >> v >> e;
    
    vector <int> adj[v];
    
    while (e--) {
        int s, d;
        cin >> s >> d;
        adjListGraph(adj, s, d);
    }
    
    int src = 0;   // source is node 0
    bool vis[v] = {false};
    dfs(adj, src, vis); // recursive
    
    cout << endl;
    
    memset(vis, false, sizeof(vis));
    dfsIterative (adj, src, vis);
}
