#include<bits/stdc++.h>
using namespace std;

void adjListGraph(vector<int> adj[], int s, int d){
    // undirected graph
    adj[s].push_back(d);
    adj[d].push_back(s);
}

void showGraph(vector<int> adj[], int v){
    for(int i=0;i<v;i++){
        cout<<i;
        for(auto x : adj[i])
            cout<<"->"<<x;
        cout<<endl;
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
    showGraph(adj, v);
}
