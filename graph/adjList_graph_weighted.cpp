#include<bits/stdc++.h>
using namespace std;

void adjListGraph(vector<pair<int, int> > adj[], int s, int d, int w){
    // undirected and weighted graph
    adj[s].push_back(make_pair(d, w));
    adj[d].push_back(make_pair(s, w));
}

void showGraph(vector<pair<int, int> > adj[], int v){
    for(int i=0;i<v;i++){
        cout<<i;
        for(auto it=adj[i].begin(); it!=adj[i].end();it++){
            int d=it->first;
            int w=it->second;
                cout<<"->"<<d<<" "<<w<<" ";
        }
        cout<<endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v,e;
    cin>>v>>e;
    vector<pair<int, int> > adj[v];
    while(e--){
        int s,d,w;
        cin>>s>>d>>w;
        adjListGraph(adj, s, d, w);
    }
    showGraph(adj, v);
    //printGraph(adj, v);
}
