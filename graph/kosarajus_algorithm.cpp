#include<bits/stdc++.h>
using namespace std;

void adjListGraph(vector<int> adj[], int s, int d){
    // directed graph
    adj[s].push_back(d);
}

void dfs(vector<int> adj[], int s, bool vis[], stack<int> &st){
    vis[s]=true;
    for(auto x : adj[s]){
        if(!vis[x]){
            dfs(adj, x, vis,st);
        }
    }
    st.push(s);
}

void invertGraph(vector<int>iadj[], vector<int>adj[], int v){

    for(int i=0;i<v;i++){
        for(auto x: adj[i]){
            iadj[x].push_back(i);
        }
    }
}

void reDfs(vector<int>iadj[], int s, bool vis[]){
    vis[s]=true;
    cout<<s<<" ";
    for(auto x: iadj[s]){
        if(!vis[x]){
            reDfs(iadj, x, vis);
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
    bool vis[v];
    memset(vis, false, sizeof(vis));
    stack<int> st;
    dfs(adj, s, vis, st);     // STEP 1
    vector<int>iadj[v];
    invertGraph(iadj, adj, v);  // STEP 2
    memset(vis, false, sizeof(vis));    // STEP 3
    while(!st.empty()){
        int yy=st.top();
        st.pop();
        if(!vis[yy]){
            cout<<"SCC: ";
            reDfs(iadj, yy, vis);
            cout<<endl;
        }
    }
}


