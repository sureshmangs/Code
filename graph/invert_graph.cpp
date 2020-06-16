#include<bits/stdc++.h>
using namespace std;

void adjListGraph(vector<int> adj[], int s, int d){
    // directed graph
    adj[s].push_back(d);
}


void invertGraph(vector<int>iadj[], vector<int>adj[], int v){
    for(int i=0;i<v;i++){
        for(auto x: adj[i]){
            iadj[x].push_back(i);
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
    vector<int>iadj[v];
    invertGraph(iadj, adj, v);
    for(int i=0;i<v;i++){
        cout<<i<<" ->";
        for(auto x: adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<" -> ";
        for(auto x: iadj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}


