#include<bits/stdc++.h>
using namespace std;

bool mat[100][100];

void adjListGraph(vector<int> adj[], int s, int d){
    // directed graph
    adj[s].push_back(d);
}

void dfsUtil(vector<int> adj[], int s, int d){
    mat[s][d]=true;
    for(auto x : adj[d]){
        if(!mat[s][x]){
            dfsUtil(adj, s, x);
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

    memset(mat, false, sizeof(mat));

    for(int i=0;i<v;i++){
        dfsUtil(adj, i, i);
    }

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}
