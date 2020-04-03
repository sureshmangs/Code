
#include<bits/stdc++.h>
using namespace std;

void adjListGraph(vector<int> adj[], int s, int d){
    // undirected graph
    adj[s].push_back(d);
    adj[d].push_back(s);
}

void bfs(vector<int> adj[], int s, int v){
    queue<int> q;
    bool vis[v]={false};
    q.push(s);
    vis[s]=true;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
        for(auto x : adj[s]){
            if(!vis[x]){
                q.push(x);
                vis[x]=true;
            }
        }
        s=q.front();
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
    bfs(adj, s, v);
}
