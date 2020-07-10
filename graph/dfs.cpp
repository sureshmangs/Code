#include<bits/stdc++.h>
using namespace std;

void adjListGraph(vector<int> adj[], int s, int d){
    // undirected graph
    adj[s].push_back(d);
    adj[d].push_back(s);
}

void dfs(vector<int> adj[], int s, bool vis[]){
    vis[s]=true;
    cout<<s<<" ";
    for(auto x : adj[s]){
        if(!vis[x]){
            dfs(adj, x, vis);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v,e;
    cin>>v>>e;
    vector<int> adj[v];
    while(e--){
        int s,d;
        cin>>s>>d;
        adjListGraph(adj,s,d);
    }
    int s=0;   // source is node 0
    bool vis[v]={false};
    dfs(adj, s, vis);
}
